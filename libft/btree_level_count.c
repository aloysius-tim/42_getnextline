/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:28:12 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/16 18:19:05 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_max_on_node(int right, int left)
{
	if (right > left)
		return (right);
	else
		return (left);
}

int		btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_max_on_node(btree_level_count(root->right), btree_level_count(
root->left)) + 1);
}
