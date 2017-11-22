/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:06:56 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/14 20:07:09 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		len;

	if (s == 0)
		return (0);
	len = ft_strlen((char *)s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len <= 0)
		len = 0;
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	s += i;
	i = -1;
	while (++i < len)
		str[i] = *s++;
	str[i] = 0;
	return (str);
}
