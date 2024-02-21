/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:26:40 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/19 09:42:58 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			(*lst) = tmp;
		}
	}
	lst = NULL;
}

int	ft_lstsize(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		stk = stk->next;
		i++;
	}
	return (i);
}

int	check_if_sorted(t_stack *stk)
{
	if (stk)
	{
		while (stk->next)
		{
			if (stk->value > stk->next->value)
				return (0);
			stk = stk->next;
		}
	}
	return (1);
}

int	check_if_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}

int	rotate_one(t_stack **stk)
{
	write(1, "rb\n", 3);
	shiftup(stk);
	return (1);
}
