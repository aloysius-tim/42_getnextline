/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 04:26:02 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/15 13:53:34 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned	int		dest_len;
	unsigned	int		src_len;

	if (size < (unsigned)ft_strlen(dest))
		dest_len = size;
	else
		dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_len == size)
		return (size + src_len);
	if (src_len < size - dest_len)
		ft_strncat(dest, src, src_len + 1);
	else
	{
		ft_strncat(dest, src, size - dest_len - 1);
		dest[size - 1] = '\0';
	}
	return (dest_len + src_len);
}
