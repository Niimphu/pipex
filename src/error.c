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

void	error_exit(t_cmds *data, char *str)
{
	free_cmds(data);
	perror(str);
	exit(errno);
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
	int		i;
	char	**str;

	i = 0;
	if (i == 0)
	{
		while (data -> argv[i])
			i++;
		i -= 2;
	}
	str = ft_split(data -> argv[i], ' ');
	execve(str[i], str, data -> envp);
	write(2, "pipex: ", 7);
	write(2, str[0], ft_strlen(str[0]));
	write(2, ": command not found", 19);
}
