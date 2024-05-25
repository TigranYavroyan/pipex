/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:53:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/25 22:48:07 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	_err(t_pipex *pipex)
{
	perror("pipex");
	dealloc_pipex(pipex);
	system("leaks pipex");
	exit(EXIT_FAILURE);
}

void	__err_just(void)
{
	perror("pipex");
	system("leaks pipex");
	exit(EXIT_FAILURE);
}

void	__err_open(void)
{
	perror("pipex");
	system("leaks pipex");
	exit(EXIT_FAILURE);
}

void	dealloc_pipex(t_pipex *pipex)
{
	int	i;
	int	j;

	i = -1;
	while (++i < pipex->cmds_err_count && pipex->cmds[i])
	{
		j = -1;
		while (pipex->cmds[i][++j])
			free(pipex->cmds[i][j]);
		free(pipex->cmds[i]);
	}
	i = -1;
	if (pipex->new_env)
		while (pipex->new_env[++i])
			free(pipex->new_env[i]);
	free(pipex->cmds);
	free(pipex->new_env);
}
