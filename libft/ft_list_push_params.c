/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 15:36:09 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/16 18:17:18 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	int		current;
	t_list	*begin_list;

	current = 0;
	begin_list = 0;
	while (current < ac)
	{
		ft_list_push_front(&begin_list, av[current]);
		current++;
	}
	return (begin_list);
}
