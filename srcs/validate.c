/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:52:51 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/25 22:32:21 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	identify_cmd(t_pipex *pipex, char **av)
{
	int	count;
	int	i;

	pipex->cmds = (char ***)malloc(sizeof(char **) * pipex->cmds_count + 1);
	if (!pipex->cmds)
		return (1);
	pipex->cmds[pipex->cmds_count] = 0;
	i = 0;
	pipex->cmds_err_count = 0;
	while (i < pipex->cmds_count)
	{
		count = i + 2 + pipex->doc_flag;
		pipex->cmds[i] = ft_split(av[count], ' ');
		access_cmd(pipex, i);
		pipex->cmds_err_count++;
		++i;
	}
	return (0);
}
