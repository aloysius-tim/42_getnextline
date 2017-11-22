/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 19:49:24 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/16 18:17:40 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	int		size;
	t_list	*last;

	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	size = ft_list_size(*begin_list1);
	last = ft_list_at(*begin_list1, size);
	last->next = begin_list2;
}
