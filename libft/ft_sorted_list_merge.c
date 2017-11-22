/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:58:47 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/16 18:16:25 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_ptr_swap(void **a, void **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_list_sor(t_list **begin_list, int (*cmp)())
{
	int		changed;
	t_list	*head;

	changed = 1;
	if (*begin_list)
		while (changed)
		{
			changed = 0;
			head = *begin_list;
			while (head->next)
			{
				if ((*cmp)(head->data, head->next->data) > 0)
				{
					ft_ptr_swap(&head->data, &head->next->data);
					changed = 1;
				}
				head = head->next;
			}
		}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2
, int (*cmp)())
{
	int		size;
	t_list	*last;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	size = ft_list_size(*begin_list1);
	last = ft_list_at(*begin_list1, size);
	last->next = begin_list2;
	ft_list_sor(begin_list1, cmp);
}
