/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:55:57 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/12 20:58:08 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define PERMISSION 0644
# define READ 0
# define WRITE 1

# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**main_env;
	char	***cmds;
	char	**script;
	int		cmds_count;
	int		cmds_err_count;
	int		*fd;
	int		fd_index;
	int		cmds_index;
	int		doc_flag;
	char	**new_env;
	char	*limiter;
}			t_pipex;

//----------------------------- executing ---------------------------

void		destroy_script(t_pipex *pipex, int i);
void		execute_proc(t_pipex *pipex, int *pips);
void		execute(t_pipex *pipex);
void		do_script(t_pipex *pipex, int i);
void		create_doc(t_pipex *pipex);
void		check_here_doc(t_pipex *pipex, char **av);

//----------------------------- pathing -----------------------------

void		find_paths(t_pipex *pipex, char **env);
char		*path_for_exec(char *current_cmd, char **new_env);
int			access_cmd(t_pipex *pipex, int i);

//----------------------------- validate ----------------------------

int			identify_cmd(t_pipex *pipex, char **av);

//-------------------------------- exit -----------------------------

void		_err(void);
void		dealloc_pipex(t_pipex *pipex);

//--------------------------------- here_doc ------------------------

void		create_doc(t_pipex *pipex);
void		check_here_doc(t_pipex *pipex, char **av);

#endif // PIPEX_H
