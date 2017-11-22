/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:54:59 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/15 13:40:03 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
size_t n)
{
	unsigned int		i;
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if ((*s1++ = *s2++) == (unsigned char)c)
			return (s1);
		i++;
	}
	return (0);
}
