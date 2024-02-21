/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:31:51 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/19 12:26:39 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "swap.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

/* get_next_line main and utils functions*/
int		ft_strncmp(const char *s1, const char *s2, int n);
void	ft_bzero(void *p, int n);
int		check(char *p);
int		cal_len(char *p);
char	*get_save(char *str, char *save);
char	*get_lin(char *str);
char	*get_next_line(int fd);
int		get_next(int fd, char **str, char **line);

#endif