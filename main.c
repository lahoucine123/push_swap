/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:17:22 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/21 09:43:33 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	push_swap(t_stack **a, t_stack **b, int nelem)
{
	if (!check_if_sorted(*a))
	{
		if (nelem == 2)
		{
			if (!check_if_sorted(*a))
			{
				swap(*a);
				write(1, "sa\n", 3);
			}
		}
		else if (nelem == 3)
			sort_three(a, *a);
		else if (nelem == 5)
			sort_five(a, b);
		else
		{
			sort_by_proximity(a, b, nelem, 1);
			sort_by_proximity(b, a, nelem, 0);
		}
	}
}

int	main(int ac, char **av)
{
	int		*list;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else
		list = parsing_args(&ac, av);
	fetching_from_tab(&a, list, NULL, ac);
	push_swap(&a, &b, ac);
	return (free(list), ft_lstclear(&a), 0);
}
