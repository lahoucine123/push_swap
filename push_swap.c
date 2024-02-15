/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:03:22 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/14 21:55:38 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		get_best_mov(t_stack *stk, int index, int proximate, int *conf)
{
	if (*conf)
		while (stk)
		{
			if (stk->order >= index && stk->order <= index + proximate)
				return (stk->order);
			else if (stk->order < index)
			{
				*conf = 0;
				return (stk->order);
			}
			stk = stk->next;
		}
	else
		while (stk)
		{
			if (stk->order == index)
				return (stk->order);
			stk = stk->next;
		}
		return (-1);
}

void	rotate_stack(t_stack **stk, t_stack *node, int curr_stk)
{
	while (node != *stk)
	{
		// printf("\nhere: %d %d\n",node->value,node->waytop);
		if (node->waytop)
		{
			if (curr_stk == 'b')
				write(1, "ra\n", 3);
			else
				write(1, "rb\n", 3);
			shiftup(stk);
		}
		else
		{
			if (curr_stk == 'b')
				write(1, "rra\n", 4);
			else
				write(1, "rrb\n", 4);
			shiftdown(stk);
		}
	}
	best_way_top(*stk, ft_lstsize(*stk));
}
void	push_to_b(t_stack **a, t_stack **b, int index, char *opr)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->order != index)
		tmp = tmp->next;
	rotate_stack(a, tmp, opr[1]);
	write(1, opr, 2);
	write(1, "\n", 1);
	push(a, b);
}

int	rotate_one(t_stack **stk)
{
	write(1, "rb\n", 3);
	shiftup(stk);
	return (1);
}

void	push_swap(t_stack **a, t_stack **b, int n, int conf)
{
	int	proximate;
	int	i;
	int index;

	proximate = 30;
	i = 0;
	best_way_top(*a, ft_lstsize(*a));
	best_way_top(*b, ft_lstsize(*b));
	if (conf)
		while (i < n)
		{
			index = get_best_mov(*a, i, proximate, &conf);
			push_to_b(a, b, index, "pb");
			if (conf == 0)
				conf = rotate_one(b);
			i++;
		}
	else
		while (n - 1 >= 0)
		{
			index = get_best_mov(*a, n - 1, proximate, &conf);
			push_to_b(a, b, index, "pa");
			n--;
		}
}

int main(int ac, char **av)
{
	int i = 0;
	int	*list;
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	t_stack	*head1, *head2;

	if (ac == 1)
		ft_error();
	else if (ac == 2)
		list = getlist_from_str(&ac, av[1]);
	else
		list = getlist(ac - 1, &av[1]);
	a = malloc(sizeof(t_stack));
	a->value = list[i++];
	head1 = a;
	head2 = b;
	while (i < ac - 1)
	{
		a->next = malloc(sizeof(t_stack));
		a = a->next;
		a->order = 0;
		a->value = list[i];
		i++;
	}
	a->next = NULL;
	a = head1;
	best_way_top(a, ac - 1);
	list_sorting(list, ac - 1);
	while (a)
	{
		a->order = get_index(a->value, list, ac - 1);
		a = a->next;
	}
	if (check_if_sorted(head1))
		return (0);
	push_swap(&head1, &head2, ac - 1, 1);
	push_swap(&head2, &head1, ac - 1, 0);
	// affstack(head1, head2);
	// printf("\nres: %d",check_if_sorted(head1));
	return (0);
}
