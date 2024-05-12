/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:53:43 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/12 21:04:25 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	_err(void)
{
	perror("pipex");
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
	while (pipex->new_env[++i])
		free(pipex->new_env[i]);
	free(pipex->cmds);
	free(pipex->new_env);
}
