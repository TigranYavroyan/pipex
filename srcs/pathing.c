/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:55:20 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/11 18:55:28 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	*copy_path(char **env)
{
	int	count;

	count = -1;
	while (env[++count])
		if (!ft_strncmp(env[count], "PATH=", 5))
			return (ft_strdup(env[count] + 5));
	return (0);
}

void	find_paths(t_pipex *pipex, char **env)
{
	char	*path;

	path = copy_path(env);
	pipex->new_env = ft_split(path, ':');
	free(path);
}

char	*path_for_exec(char *current_cmd, char **new_env)
{
	char	*tmp;
	char	*path;
	int		i;

	i = -1;
	while (new_env[++i])
	{
		tmp = ft_strjoin(new_env[i], "/");
		path = ft_strjoin(tmp, current_cmd);
		free(tmp);
		if (!access(path, X_OK | F_OK))
			return (path);
		free(path);
	}
	return (0);
}

int	access_cmd(t_pipex *pipex, int i)
{
	char	*tmp;

	if (ft_strchr(pipex->cmds[i][0], '/')
		&& !access(pipex->cmds[i][0], X_OK | F_OK))
	{
		do_script(pipex, i);
		return (0);
	}
	tmp = path_for_exec(pipex->cmds[i][0], pipex->new_env);
	if (!tmp)
		return (1);
	free(pipex->cmds[i][0]);
	pipex->cmds[i][0] = tmp;
	return (0);
}
