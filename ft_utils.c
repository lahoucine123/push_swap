/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:13:00 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/13 11:42:06 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

long ft_atoi(char *str)
{
    int i;
    long res;

    i = 0;
    res = 0;
    while (str[i] < 58 && str[i] > 47)
    {
        res *= 10;
		res += str[i] - 48;
		i++;
    }
    if (str[i] != 0 || res > INT_MAX)
        return (-1);
    return (res);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int ft_lstsize(t_stack *stk)
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