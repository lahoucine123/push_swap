/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:13:00 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/18 09:43:05 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*join;

	i = 0;
	if (!s1 && !s2)
		return (0);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (0);
	if (s1)
	{
		while (s1[i])
		{
			join[i] = s1[i];
			i++;
		}
		free(s1);
	}
	if (s2)
	{
		while (*s2)
			join[i++] = *s2++;
	}
	join[i] = 0;
	return (join);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb && i < 46500)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

long	ft_atoi(char *str, int *err)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 44 - str[i++];
		if (str[i] == 0)
			*err = 1;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	res = sign * res;
	if (str[i] != 0 || res > INT_MAX || res < INT_MIN)
		*err = 1;
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
