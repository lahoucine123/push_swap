/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:30:00 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/04 16:30:04 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	affstack(stack *a, stack *b)
{
	printf("------------------------\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d",a->value);
			a = a->next;
		}
		else
			printf(" ");
		if (b)
		{
			printf("\t%d",b->value);
			b = b->next;
		}
		printf("\n");
	}
	printf("------------------------\n");
}

void	swap(stack *a)
{
	int	tmp = 0;
	if (a && a->next)
	{
		tmp = a->value;
		a->value = a->next->value;
		a->next->value = tmp;
	}
}

void	push(stack **a, stack **b)
{
	stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	if (*b == NULL)
	{
		(*b) = (*a);
		(*b)->next = NULL;
	}
	else
	{
		(*a)->next = (*b);
		(*b) = (*a);
	}	
	(*a) = tmp;
}

void	shiftup(stack **a)
{
	stack	*tmp;

	if(!(*a) || !((*a)->next))
		return ;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	(*a) = (*a)->next;
	tmp->next->next = NULL;
}

void	shiftdown(stack **a)
{
	stack	*tmp;

	if(!(*a) || !((*a)->next))
		return ;	
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
}
