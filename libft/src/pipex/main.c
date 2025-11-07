/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:38 by awaegaer          #+#    #+#             */
/*   Updated: 2025/05/20 18:46:44 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
		return (ft_putstr_fd("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n"
				, 2), 1);
	px.envp = envp;
	if (open_files(&px, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_cmds(&px, argv) == EXIT_FAILURE)
	{
		close_n_free(&px);
		return (EXIT_FAILURE);
	}
	if (childs_process(&px) == EXIT_FAILURE)
	{
		close_n_free(&px);
		return (EXIT_FAILURE);
	}
	close_n_free(&px);
	return (EXIT_SUCCESS);
}
