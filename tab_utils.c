/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <laoubaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:01:07 by laoubaid          #+#    #+#             */
/*   Updated: 2024/02/18 17:55:23 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	check_tab(int n, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] == tab[j])
				ft_error();
			j++;
		}
		i++;
	}
}

int	*getlist(int n, char **strlist)
{
	int	i;
	int	*list;
	int	err;

	err = 0;
	list = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		list[i] = ft_atoi(strlist[i], &err);
		if (err)
		{
			free(list);
			ft_free(strlist);
			ft_error();
		}
		i++;
	}
	check_tab(n, list);
	return (list);
}

int	*getlist_from_str(int *ac, char *str)
{
	int		i;
	int		*list;
	char	**strlist;

	i = 0;
	strlist = ft_split(str, ' ');
	free(str);
	while (strlist[i])
		i++;
	*ac = i;
	list = getlist(*ac, strlist);
	ft_free(strlist);
	return (list);
}

void	list_sorting(int list[], int n)
{
	int	i;
	int	current;
	int	j;

	i = 1;
	while (i < n)
	{
		current = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > current)
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = current;
		i++;
	}
}

int	get_index(int value, int *list, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (list[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
