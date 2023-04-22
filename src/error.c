/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:44:57 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/25 15:44:57 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

// void	error_exit(t_cmds *data, char *str)
// {
// 	free_cmds(data);
// 	perror(str);
// 	exit(errno);
// }

void	close_exit(int code)
{
	int	fd;

	fd = 3;
	while (fd < 64)
	{
		close(fd);
		fd++;
	}
	exit(code);
}

void	open_error(char *filename, int fd[])
{
	if (fd[0])
		write(fd[1], "       0\n", 9);
	if (fd[0] > 0)
		close(fd[0]);
	if (fd[1])
		close(fd[1]);
	write(STDERR_FILENO, "pipex: ", 7);
	perror(filename);
	exit(0);
}

void	cmd_notfound(t_cmds *data)
{
	write(2, "pipex: ", 7);
	write(2, data -> cmd, ft_strlen(data -> cmd));
	write(2, ": command not found\n", 20);
}
