/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:05:31 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/25 10:12:34 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

char	*get_path(char *cmd, char **envp);
void	execute_cmd(char *argv, char **envp);
void	free_tab(char **tab);
void	ft_check_space(char *cmd);

#endif