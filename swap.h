/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:31:09 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/19 10:06:24 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

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
void	swap(t_stack *a);
void	push(t_stack **a, t_stack **b);
void	shiftup(t_stack **a);
void	shiftdown(t_stack **a);

/* simple utils functions */
void	ft_error(void);
int		ft_strlen(const char *str);
long	ft_atoi(char *str, int *err);
char	**ft_split(char const *s, char c);
int		ft_sqrt(int nb);
char	**ft_free(char **ptr);
char	*ft_strjoin(char *s1, char *s2);

/* list utils functions */
int		check_if_empty(char *str);
int		check_if_sorted(t_stack *stk);
void	ft_lstclear(t_stack **lst);
int		ft_lstsize(t_stack *stk);
int		rotate_one(t_stack **stk);

/* table utils functions */
int		get_index(int value, int *list, int n);
void	list_sorting(int list[], int n);
int		*getlist_from_str(int *ac, char *str);
int		*getlist(int n, char **strlist);
void	check_tab(int n, int *tab);

/* push_swap utils functions */
void	rotate_stack(t_stack **stk, t_stack *node, int curr_stk);
int		get_best_mov(t_stack *stk, int index, int proximate, int *conf);
void	best_way_top(t_stack *stk, int n);
void	push_to_b(t_stack **a, t_stack **b, int index, char *opr);

void	sort_five(t_stack **a, t_stack **b);
void	set_order(t_stack *a);
void	sort_three(t_stack **a, t_stack *s);
void	fetching_from_tab(t_stack **a, int *list, t_stack *tmp, int n);
int		*parsing_args(int *ac, char **av);
void	sort_by_proximity(t_stack **a, t_stack **b, int n, int conf);

#endif