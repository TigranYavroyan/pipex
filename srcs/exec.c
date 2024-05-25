/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:54:35 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/15 18:16:09 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	destroy_script(t_pipex *pipex, int i)
{
	int	count;

	count = -1;
	while (pipex->cmds[i][++count])
		free(pipex->cmds[i][count]);
	free(pipex->cmds[i]);
}

void	execute_proc(t_pipex *pipex, int *pips)
{
	close(pips[READ]);
	if (pipex->cmds_count - 1 > pipex->cmds_index)
		dup2(pips[WRITE], STDOUT_FILENO);
	else
		dup2(pipex->outfile, STDOUT_FILENO);
	execve(pipex->cmds[pipex->cmds_index][0], pipex->cmds[pipex->cmds_index],
		pipex->main_env);
	_err(pipex);
}

void	execute(t_pipex *pipex)
{
	pid_t	pid;
	int		pips[2];
	int		i;

	i = 0;
	pipex->cmds_index = 0;
	while (i < pipex->cmds_count)
	{
		if (pipe(pips) < 0)
			_err(pipex);
		pid = fork();
		if (pid < 0)
			_err(pipex);
		if (pid == 0)
			execute_proc(pipex, pips);
		++pipex->cmds_index;
		++i;
		dup2(pips[READ], STDIN_FILENO);
		close(pips[READ]);
		close(pips[WRITE]);
	}
	close(pipex->outfile);
	close(pipex->infile);
}

void	do_script(t_pipex *pipex, int i)
{
	int	size;
	int	index;
	int	j;

	size = 0;
	while (pipex->cmds[i][size])
		++size;
	pipex->script = (char **)malloc(sizeof(char *) * (++size + 1));
	if (!pipex->script)
		return ;
	pipex->script[size] = 0;
	j = 0;
	index = 0;
	pipex->script[j++] = ft_strdup("/bin/bash");
	while (j < size)
	{
		pipex->script[j++] = ft_strdup(pipex->cmds[i][index++]);
	}
	destroy_script(pipex, i);
	pipex->cmds[i] = pipex->script;
}
