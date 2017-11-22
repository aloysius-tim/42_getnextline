/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:02:01 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/14 20:02:32 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		counter;

	counter = 0;
	if (!s1 || !s2)
		return (0);
	if ((final = (char *)malloc(sizeof(char) * (ft_strlen((char*)s1) +
ft_strlen((char*)s2) + 1))) == 0)
		return (0);
	while (*s1)
	{
		final[counter] = *s1;
		s1++;
		counter++;
	}
	while (*s2)
	{
		final[counter] = *s2;
		s2++;
		counter++;
	}
	final[counter] = 0;
	return (final);
}
