/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:31:09 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/04 16:31:10 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct stack
{
	int	value;
	struct stack *next;
} stack;

void	affstack(stack *a, stack *b);
void	swap(stack *a);
void	push(stack **a, stack **b);
void	shiftup(stack **a);
void	shiftdown(stack **a);

#endif