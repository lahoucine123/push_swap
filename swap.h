/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:31:09 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/13 11:47:15 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include <stdio.h>  //delete me plz
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct stack
{
	int				value;
	int				order;
	int				waytop;
	struct stack	*next;
}	t_stack;

/* operation functions */
void	affstack(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	push(t_stack **a, t_stack **b);
void	shiftup(t_stack **a);
void	shiftdown(t_stack **a);

/* simple utils functions */
void	ft_error(void);
int		ft_strlen(const char *str);
long	ft_atoi(char *str);
char	**ft_split(char const *s, char c);
int		ft_lstsize(t_stack *stk);

/* list utils functions */
int		get_index(int value, int *list, int n);
void	list_sorting(int list[], int n);
int		*getlist_from_str(int *n, char *str);
int		*getlist(int n, char **strlist);
void	check_list(int n, int *list);

/* push_swap utils functions */
void	best_way_top(t_stack *stk, int n);
int		check_if_sorted(t_stack *stk);

#endif