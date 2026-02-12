/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:53:52 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 12:03:15 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates through the list ’lst’ and applies the
function ’f’ to the content of each node.
 *
 * @param lst The address of a pointer to a node.
 * @param f The address of the function to apply to each
node’s content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	while (lst)
	{
		temp = (lst)->next;
		(*f)(lst->content);
		lst = temp;
	}
}
