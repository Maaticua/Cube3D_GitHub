/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macaruan <macaruan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:06:41 by awaegaer          #+#    #+#             */
/*   Updated: 2025/10/28 14:10:21 by macaruan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	int		status;
	int		pipefd[2];
	char	**cmd1;
	char	**cmd2;
	char	**envp;
}t_pipex;

// main.c
//int		main(int argc, char **argv, char **envp);

// main_utils.c
int		init_cmds(t_pipex *px, char **argv);
int		open_files(t_pipex *px, char **argv);
int		childs_process(t_pipex *px);
void	free_split(char **tab);
void	close_n_free(t_pipex *px);

// utils.c
void	child2_exec(t_pipex *px, int pipefd[2]);
void	child1_exec(t_pipex *px, int pipefd[2]);
char	*get_cmd_path(char *cmd, char **envp);
char	*find_exe(char **paths, char *cmd);
char	*extract_path_envp(char **envp);

#endif
