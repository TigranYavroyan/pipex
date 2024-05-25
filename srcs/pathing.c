/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:55:20 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/25 22:55:13 by tyavroya         ###   ########.fr       */
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
	path = ft_strdup(current_cmd);
	if (!access(path, X_OK | F_OK))
		return (path);
	if (!new_env)
		__err_just();
	while (new_env[++i])
	{
		free(path);
		tmp = ft_strjoin(new_env[i], "/");
		path = ft_strjoin(tmp, current_cmd);
		free(tmp);
		if (!access(path, X_OK | F_OK))
			return (path);
	}
	free(path);
	return (0);
}

void	access_cmd(t_pipex *pipex, int i)
{
	char	*tmp;
	int		flag;

	flag = 0;
	if (!ft_strnstr(pipex->cmds[i][0], "/bin/", ft_strlen(pipex->cmds[i][0]))
		&& ft_strchr(pipex->cmds[i][0], '/')
		&& !access(pipex->cmds[i][0], X_OK | F_OK))
	{
		do_script(pipex, i);
		return ;
	}
	tmp = path_for_exec(pipex->cmds[i][0], pipex->new_env);
	free(pipex->cmds[i][0]);
	pipex->cmds[i][0] = tmp;
}
