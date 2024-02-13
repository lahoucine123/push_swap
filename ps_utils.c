/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:55:46 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/13 13:09:15 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	best_way_top(t_stack *stk, int n)
{
	int pos;

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

int check_if_sorted(t_stack *stk)
{
    while (stk->next)
    {
        if(stk->value > stk->next->value)
            return (0);
        stk = stk->next;
    }
    return (1);
}