/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:13:42 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/19 12:11:32 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	cal_len(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i] && p[i] != '\n')
		i++;
	if (p[i] == '\n')
		i++;
	return (i);
}

void	ft_bzero(void *p, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)p;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1)
		return (-1);
	if (n == 0 && s1)
		return (1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
