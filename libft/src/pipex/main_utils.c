/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:59:50 by awaegaer          #+#    #+#             */
/*   Updated: 2025/05/22 19:31:42 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	childs_process(t_pipex *px)
{
	int		pipefd[2];
	pid_t	cpid1;
	pid_t	cpid2;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		close_n_free(px);
		exit(EXIT_FAILURE);
	}
	cpid1 = fork();
	if (cpid1 == -1)
		return (perror("fork"), EXIT_FAILURE);
	if (cpid1 == 0)
		child1_exec(px, pipefd);
	cpid2 = fork();
	if (cpid2 == -1)
		return (perror("fork"), EXIT_FAILURE);
	if (cpid2 == 0)
		child2_exec(px, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(cpid1, &px->status, 0);
	waitpid(cpid2, &px->status, 0);
	return (EXIT_SUCCESS);
}

void	close_n_free(t_pipex *px)
{
	if (px->fd_infile >= 0)
		close(px->fd_infile);
	if (px->fd_outfile >= 0)
		close(px->fd_outfile);
	if (px->cmd1)
		free_split(px->cmd1);
	if (px->cmd2)
		free_split(px->cmd2);
}

int	init_cmds(t_pipex *px, char **argv)
{
	px->cmd1 = ft_split(argv[2], ' ');
	px->cmd2 = ft_split(argv[3], ' ');
	if (!px->cmd1 || !px->cmd2 || !px->cmd1[0] || !px->cmd2[0])
	{
		ft_putstr_fd("Error: split commands empty or invalid\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	open_files(t_pipex *px, char **argv)
{
	px->fd_infile = open(argv[1], O_RDONLY | __O_CLOEXEC);
	if (px->fd_infile < 0)
	{
		perror("Error: open infile");
		return (EXIT_FAILURE);
	}
	px->fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | __O_CLOEXEC,
			0644);
	if (px->fd_outfile < 0)
	{
		perror("Error: open outfile");
		close(px->fd_infile);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
