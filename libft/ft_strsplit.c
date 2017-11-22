/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:05:55 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/14 20:19:45 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

const	char	*ft_str_find_next(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static	int		ft_str_count_splits(const char *str, char seps)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str = ft_str_find_next(str, seps, 1);
		if (*str != '\0')
		{
			i++;
			str = ft_str_find_next(str, seps, 0);
		}
	}
	return (i);
}

static	char	**ft_tabledel(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (0);
}

char			**ft_strsplit(char const *str, char c)
{
	char		**ret;
	int			i;
	const char	*next;

	if (str == 0)
		return (0);
	ret = (char**)malloc(sizeof(char*) * (ft_str_count_splits(str, c) + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		str = ft_str_find_next(str, c, 1);
		if (*str != '\0')
		{
			next = ft_str_find_next(str, c, 0);
			ret[i] = ft_strsub(str, 0, next - str);
			if (ret[i] == 0)
				return (ft_tabledel(ret, i));
			i++;
			str = next;
		}
	}
	ret[i] = 0;
	return (ret);
}
