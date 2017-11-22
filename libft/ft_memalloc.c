/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:54:01 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/14 19:54:23 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *final;

	if (size == 0)
		return (0);
	if ((final = (void *)malloc(size)) == 0)
		return (0);
	ft_memset(final, 0, size);
	return (final);
}
