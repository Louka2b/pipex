/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:04:12 by ldeplace          #+#    #+#             */
/*   Updated: 2025/11/17 18:30:11 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of nodes in the list.
 * 
 * @param lst The beginning of the list.
 * @return int The length of the list
 */
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (lst == NULL)
		return (i);
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
