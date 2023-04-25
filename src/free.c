/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:57:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/25 17:14:30 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	close_reset(int fd)
{
	if (fd == 3)
	{
		if (access("temp", F_OK) == 0)
			unlink("temp");
	}
	if (fd != -1)
		close(fd);
	fd = -1;
	return ;
}

void	close_all(t_cmds *data)
{
	if (access("temp", F_OK) == 0)
		unlink("temp");
	close_reset(data -> fd[0]);
	close_reset(data -> fd[1]);
	close_reset(data -> pipe_fd[0]);
	close_reset(data -> pipe_fd[1]);
	return ;
}

void	free_pointer(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return ;
}

void	free_ppointer(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			free_pointer(str[i++]);
		free(str);
		str = NULL;
	}
	return ;
}
