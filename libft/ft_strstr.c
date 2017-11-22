/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:56:04 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/15 13:56:45 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*head;
	const char	*tmp;

	if (!*little)
		return ((char *)big);
	tmp = little;
	while (*big)
	{
		head = big;
		while ((*big == *little) && *little)
		{
			++big;
			++little;
		}
		if (!*little)
			return ((char *)head);
		little = tmp;
		big = head + 1;
	}
	return (0);
}
