/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:57:31 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/01 17:57:54 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	free_cmds(t_cmds *data)
{
	if (data -> cmd)
		free_pointer(data -> cmd);
	if (*data -> path)
		free_ppointer(data -> path);
	if (*data -> args)
		free_ppointer(data -> args);
	if (data)
	{
		free(data);
		data = NULL;
	}
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
