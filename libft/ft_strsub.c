/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:06:45 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/14 20:12:36 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		counter;
	char	*final;

	if (!s)
		return (0);
	counter = 0;
	if ((final = ft_strnew(len)) == 0)
		return (0);
	while (len)
	{
		final[counter] = s[start];
		start++;
		counter++;
		len--;
	}
	return (final);
}
