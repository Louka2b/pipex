/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:24:08 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 17:46:32 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns
a new node. The ’content’ member variable is
initialized with the given parameter ’content’.
The variable ’next’ is initialized to NULL.
 * 
 * @param content The content to store in the new node.
 * @return t_list* A pointer to the new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof (t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
