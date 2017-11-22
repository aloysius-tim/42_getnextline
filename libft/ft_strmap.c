/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:03:00 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/14 20:03:14 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	retlen;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	retlen = ft_strlen((char *)s);
	if ((ret = ft_memalloc(retlen + 1)) == 0)
		return (0);
	while (*s)
	{
		ret[i++] = f(*s);
		s++;
	}
	return (ret);
}
