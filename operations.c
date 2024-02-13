/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:30:00 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/13 12:53:07 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	affstack(t_stack *a, t_stack *b)
{
	printf("------------------------\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d %d", a->value, a->waytop);
			a = a->next;
		}
		else
			printf(" ");
		if (b)
		{
			printf("\t%d %d", b->value, b->waytop);
			b = b->next;
		}
		printf("\n");
	}
	printf("------------------------\n");
}

void	swap(t_stack *stk)
{
	int	tmp;
	int tmp2;

	tmp = 0;
	tmp2 = 0;
	if (stk && stk->next)
	{
		tmp2 = stk->order;
		tmp = stk->value;
		stk->value = stk->next->value;
		stk->order = stk->next->order;
		stk->next->value = tmp;
		stk->next->order = tmp2;
	}
}

void	push(t_stack **stk1, t_stack **stk2)
{
	t_stack	*tmp;

	if (!(*stk1))
		return ;
	tmp = (*stk1)->next;
	if (*stk2 == NULL)
	{
		(*stk2) = (*stk1);
		(*stk2)->next = NULL;
	}
	else
	{
		(*stk1)->next = (*stk2);
		(*stk2) = (*stk1);
	}	
	(*stk1) = tmp;
}

void	shiftup(t_stack **stk)
{
	t_stack	*tmp;

	if(!(*stk) || !((*stk)->next))
		return ;
	tmp = *stk;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stk;
	(*stk) = (*stk)->next;
	tmp->next->next = NULL;
}

void	shiftdown(t_stack **a)
{
	t_stack	*tmp;

	if(!(*a) || !((*a)->next))
		return ;	
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
}
