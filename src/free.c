/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:57:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/25 16:45:54 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	free_data(t_cmds *data)
{
	if (!data)
		return ;
	if (data -> path)
		free_ppointer(data -> path);
	if (data -> args)
		free_ppointer(data -> args);
	close_all(data);
	free(data);
	data = NULL;
	return ;
}

void	close_all(t_cmds *data)
{
	if (data -> is_heredoc)
		unlink("temp");
	close_reset(data -> fd[0]);
	close_reset(data -> fd[1]);
	close_reset(data -> pipe_fd[0]);
	close_reset(data -> pipe_fd[1]);
}

void	close_reset(int fd)
{
	if (fd != -1)
		close(fd);
	fd = -1;
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
