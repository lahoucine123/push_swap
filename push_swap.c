/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:03:22 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/19 14:26:25 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	sort_by_proximity(t_stack **a, t_stack **b, int n, int conf)
{
	int	proximate;
	int	i;

	proximate = ft_sqrt(n) + (n / 500) + 5;
	i = 0;
	best_way_top(*a, ft_lstsize(*a));
	best_way_top(*b, ft_lstsize(*b));
	if (conf)
	{
		while (i < n)
		{
			push_to_b(a, b, get_best_mov(*a, i, proximate, &conf), "pb\n");
			if (conf == 0)
				conf = rotate_one(b);
			i++;
		}
	}
	else
	{
		while (n - 1 >= 0)
		{
			push_to_b(a, b, get_best_mov(*a, n - 1, proximate, &conf), "pa\n");
			n--;
		}
	}
}

int	*parsing_args(int *ac, char **av)
{
	int		*list;
	int		i;
	char	*strlist;

	i = 1;
	strlist = NULL;
	while (av[i])
	{
		if (check_if_empty(av[i]))
			ft_error();
		strlist = ft_strjoin(strlist, av[i]);
		strlist = ft_strjoin(strlist, " ");
		i++;
	}
	list = getlist_from_str(ac, strlist);
	return (list);
}

void	fetching_from_tab(t_stack **a, int *list, t_stack *tmp, int n)
{
	int		i;

	i = 0;
	tmp = malloc(sizeof(t_stack));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->value = list[i++];
	*a = tmp;
	while (i < n)
	{
		tmp->next = malloc(sizeof(t_stack));
		if (tmp->next == NULL)
			exit(EXIT_FAILURE);
		tmp = tmp->next;
		tmp->value = list[i++];
	}
	tmp->next = NULL;
	best_way_top(*a, n);
	list_sorting(list, n);
	tmp = *a;
	while (tmp)
	{
		tmp->order = get_index(tmp->value, list, n);
		tmp = tmp->next;
	}
}

void	sort_three(t_stack **a, t_stack *s)
{
	if (s->order == 0 || s->next->order == 1 || s->next->next->order == 2)
	{
		write(1, "sa\n", 3);
		swap(*a);
		if ((*a)->order == 2)
		{
			write(1, "ra\n", 3);
			shiftup(a);
		}
		else if ((*a)->next->order == 2)
		{
			write(1, "rra\n", 4);
			shiftdown(a);
		}
	}
	else if (s->order == 2 && s->next->order == 0)
	{
		write(1, "ra\n", 3);
		shiftup(a);
	}
	else if (s->order == 1 && s->next->order == 2)
	{
		write(1, "rra\n", 4);
		shiftdown(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	i;
	int	conf;

	i = 0;
	conf = 1;
	while (i < 2)
	{
		push_to_b(a, b, get_best_mov(*a, i, 0, &conf), "pb\n");
		if (conf == 0)
			conf = rotate_one(b);
		i++;
	}
	if (check_if_sorted(*b))
	{
		write(1, "sb\n", 3);
		swap(*b);
	}
	set_order(*a);
	if (!check_if_sorted(*a))
		sort_three(a, *a);
	write(1, "pa\npa\n", 6);
	push(b, a);
	push(b, a);
}
