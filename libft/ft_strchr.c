/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:59:39 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/15 13:53:53 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int counter;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		if (*(s + counter) == (unsigned char)c)
			return (char *)(s + counter);
		counter++;
	}
	if ((unsigned char)c == '\0' && *(s + counter) == '\0')
		return (char *)(s + counter);
	return (0);
}
