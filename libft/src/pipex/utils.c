/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:03:37 by awaegaer          #+#    #+#             */
/*   Updated: 2025/10/09 17:54:33 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*extract_path_envp(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
			break ;
		}
		i++;
	}
	return (path);
}

char	*find_exe(char **paths, char *cmd)
{
	int		i;
	char	*temp_path;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		if (!temp_path)
			return (NULL);
		full_path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (!full_path)
			return (NULL);
		if (!access(full_path, X_OK))
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	**paths;

	if (!cmd || !*cmd)
		return (NULL);
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	path = extract_path_envp(envp);
	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	free(path);
	if (!paths)
		return (NULL);
	path = find_exe(paths, cmd);
	free_split(paths);
	if (!path)
		return (NULL);
	return (path);
}

void	child1_exec(t_pipex *px, int pipefd[2])
{
	char	*path;

	dup2(px->fd_infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	path = get_cmd_path(px->cmd1[0], px->envp);
	if (!path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(px->cmd1[0], 2);
		close_n_free(px);
		exit(127);
	}
	if (execve(path, px->cmd1, px->envp) == -1)
	{
		perror("execve");
		free(path);
		close_n_free(px);
		exit(EXIT_FAILURE);
	}
}

void	child2_exec(t_pipex *px, int pipefd[2])
{
	char	*path;

	dup2(px->fd_outfile, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	close(pipefd[0]);
	path = get_cmd_path(px->cmd2[0], px->envp);
	if (!path)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(px->cmd2[0], 2);
		close_n_free(px);
		exit(127);
	}
	if (execve(path, px->cmd2, px->envp) == -1)
	{
		perror("execve");
		free(path);
		close_n_free(px);
		exit(EXIT_FAILURE);
	}
}
