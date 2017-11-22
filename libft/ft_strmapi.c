/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:03:18 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/14 20:03:51 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	size_t			retlen;
	int				i;
	unsigned	int	counter;

	i = 0;
	counter = 0;
	if (!s || !f)
		return (NULL);
	retlen = ft_strlen((char *)s);
	if ((ret = ft_memalloc(retlen + 1)) == 0)
		return (0);
	while (*s)
	{
		ret[i++] = f(counter, *s);
		s++;
		counter++;
	}
	return (ret);
}
