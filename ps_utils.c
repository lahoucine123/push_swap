/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:55:46 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/19 12:25:38 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	rotate_stack(t_stack **stk, t_stack *node, int curr_stk)
{
	while (node != *stk)
	{
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

int	get_best_mov(t_stack *stk, int index, int proximate, int *conf)
{
	if (*conf)
	{
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
	}
	else
	{
		while (stk)
		{
			if (stk->order == index)
				return (stk->order);
			stk = stk->next;
		}
	}
	return (-1);
}

void	best_way_top(t_stack *stk, int n)
{
	int	pos;

	pos = 0;
	while (stk)
	{
		if (pos <= n / 2)
			stk->waytop = 1;
		else
			stk->waytop = 0;
		pos++;
		stk = stk->next;
	}
}

void	push_to_b(t_stack **a, t_stack **b, int index, char *opr)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->order != index)
		tmp = tmp->next;
	rotate_stack(a, tmp, opr[1]);
	write(1, opr, 3);
	push(a, b);
}

void	set_order(t_stack *a)
{
	int		*list;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	list = malloc(sizeof(int) * 3);
	if (!list)
	{
		write(2, "Error: Unable to allocate memory\n", 32);
		exit(EXIT_FAILURE);
	}
	while (i < 3)
	{
		list[i++] = a->value;
		a = a->next;
	}
	list_sorting(list, 3);
	while (tmp)
	{
		tmp->order = get_index(tmp->value, list, 3);
		tmp = tmp->next;
	}
}
