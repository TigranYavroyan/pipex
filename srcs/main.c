/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:01:18 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/12 21:10:07 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	open_file(t_pipex *pipex, char **av, int ac)
{
	if (pipex->doc_flag)
	{
		pipex->infile = open(av[1], O_CREAT | O_RDWR, PERMISSION);
		if (pipex->infile < 0)
			_err();
		create_doc(pipex);
	}
	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC
			* !(pipex->doc_flag) | O_APPEND * pipex->doc_flag, PERMISSION);
	if (pipex->infile < 0 || pipex->outfile < 0)
		_err();
	dup2(pipex->infile, STDIN_FILENO);
}

int	t_main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	pipex.main_env = env;
	if (ac < 5)
	{
		ft_putstr_fd("pipex: wrong count of arguments", 2);
		exit(EXIT_FAILURE);
	}
	check_here_doc(&pipex, av);
	find_paths(&pipex, env);
	pipex.cmds_count = ac - 3 - pipex.doc_flag;
	if (identify_cmd(&pipex, av))
	{
		dealloc_pipex(&pipex);
		_err();
	}
	open_file(&pipex, av, ac);
	execute(&pipex);
	dealloc_pipex(&pipex);
	while (wait(NULL) != -1)
		(void)pipex;
	if (pipex.doc_flag)
		unlink(av[1]);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_main(ac, av, env);
	//system("leaks pipex");
}
