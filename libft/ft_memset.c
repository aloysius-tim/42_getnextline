/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:56:25 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/14 19:56:42 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*head;

	if (len == 0)
		return (b);
	head = (unsigned char *)b;
	while (len--)
	{
		*head = (unsigned char)c;
		if (len)
			head++;
	}
	return (b);
}
