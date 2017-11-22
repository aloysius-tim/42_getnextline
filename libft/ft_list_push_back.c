/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:55:44 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/21 15:50:44 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*current;
	t_list	*new;

	new = ft_create_elem(data);
	current = *begin_list;
	if (!begin_list || !(*begin_list))
	{
		*begin_list = new;
		return (new);
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
	return (new);
}
