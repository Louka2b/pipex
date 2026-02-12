/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:44:39 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/18 11:50:48 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and all its
successors, using the function ’del’ and free(3).
Finally, set the pointer to the list to NULL
 * 
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
	lst = NULL;
}
