/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:29:38 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/16 18:18:35 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list && nbr)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	if (!nbr)
		return (begin_list);
	else
		return (0);
}
