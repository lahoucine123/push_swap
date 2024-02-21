/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:32:24 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/19 12:26:45 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_operation_syntax(char *op)
{
	if (op[0] == 'r')
	{
		if ((op[1] == 'a' || op[1] == 'b' || op[1] == 'r') && op[2] == 10)
			return (0);
		else if (op[1] == 'r')
			if ((op[2] == 'a' || op[2] == 'b' || op[2] == 'r') && op[3] == 10)
				return (0);
	}
	if (op[0] == 's')
		if ((op[1] == 'a' || op[1] == 'b' || op[1] == 's') && op[2] == 10)
			return (0);
	if (op[0] == 'p')
		if ((op[1] == 'a' || op[1] == 'b') && op[2] == 10)
			return (0);
	return (1);
}

void	execute_operation_suit(t_stack **a, t_stack **b, char *op)
{
	if (!(ft_strncmp(op, "ss", 2)))
	{
		swap(*a);
		swap(*b);
	}
	if (!(ft_strncmp(op, "rr", 2)))
	{
		shiftup(a);
		shiftup(b);
	}
	if (!(ft_strncmp(op, "rrr", 3)))
	{
		shiftdown(a);
		shiftdown(b);
	}
}

void	execute_operation(t_stack **a, t_stack **b, char *op)
{
	if (!(ft_strncmp(op, "pa", 2)))
		push(b, a);
	else if (!(ft_strncmp(op, "pb", 2)))
		push(a, b);
	else if (!(ft_strncmp(op, "sa", 2)))
		swap(*a);
	else if (!(ft_strncmp(op, "sb", 2)))
		swap(*b);
	else if (!(ft_strncmp(op, "ra", 2)))
		shiftup(a);
	else if (!(ft_strncmp(op, "rb", 2)))
		shiftup(b);
	else if (!(ft_strncmp(op, "rra", 3)))
		shiftdown(a);
	else if (!(ft_strncmp(op, "rrb", 3)))
		shiftdown(b);
	else
		execute_operation_suit(a, b, op);
}

void	read_and_execute(t_stack **a, t_stack **b, int *list)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (check_operation_syntax(line))
		{
			free(list);
			free(line);
			ft_lstclear(a);
			ft_lstclear(b);
			ft_error();
		}
		execute_operation(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
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
	read_and_execute(&a, &b, list);
	free(list);
	if (check_if_sorted(a) && ft_lstsize(a) == ac)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
