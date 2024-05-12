/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:25:40 by tyavroya          #+#    #+#             */
/*   Updated: 2024/05/12 17:31:00 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **line)
{
	free(*line);
	return (*line = 0);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_lines;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (ft_free(&line));
	if (!line)
	{
		line = (char *)malloc(1);
		if (!line)
			return (0);
		line[0] = '\0';
	}
	else
	{
		next_lines = ft_strchr_gnl(line, '\n');
		if (!next_lines)
			return (ft_free(&line));
		else
			new_line(&line, next_lines + 1);
	}
	ft_read_gnl(fd, &line);
	return (ft_slice(&line));
}
// int main () {
// 	int fd = open("text.txt", O_RDONLY);
// 	for (int i = 0; i < 5; ++i) {
// 		char *str = get_next_line(fd);
// 		printf("%s", str);
// 	}
// }
