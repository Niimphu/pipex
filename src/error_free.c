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

void	error_exit(t_cmds *data, char *strerr, int status)
{
	if (data)
		free_cmds(data);
	perror(strerr);
	exit(status);
}

void	free_cmds(t_cmds *data)
{
	if (!data)
		return ;
	if (data -> cmd)
		free_pointer(data -> cmd);
	if (*data -> path)
		free_ppointer(data -> path);
	if (*data -> args)
		free_ppointer(data -> args);
	free(data);
	data = NULL;
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
