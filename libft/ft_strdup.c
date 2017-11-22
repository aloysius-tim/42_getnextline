/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:01:14 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/15 13:49:44 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *src)
{
	char *dest;

	if ((dest = (char*)malloc(sizeof(*src) * (ft_strlen(src) + 1))) == 0)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}
