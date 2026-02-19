/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeplace <ldeplace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:05:31 by ldeplace          #+#    #+#             */
/*   Updated: 2026/02/19 15:49:55 by ldeplace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_pipex
{
	char	**cmd1_args;
	char	*cmd1_path;
	char	**cmd2_args;
	char	*cmd2_path;
}			t_pipex;

void		error_exit(char *msg, int status);
void		error_exit(char *msg, int status);
char		*find_cmd_path(char *cmd, char **envp);
void		ft_parsing(t_pipex *pipex, char **argv, char **envp);
void		error_exit(char *msg, int status);
void		free_tab(char **tab);
char		*get_env_path(char **envp);

#endif