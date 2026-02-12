/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:33:37 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 18:49:24 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node of the list.
 * 
 * @param lst The beginning of the list.
 * @return t_list* Last node of the list
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (lst);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
