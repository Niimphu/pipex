/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/20 02:42:43 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	pipex(char *argv[], char *envp[], int *fd[])
{
	t_cmds data;
	
	data = struct_init(argv, envp, fd);
	
}

t_cmds *struct_init(char *argv[], char *envp[], int *fd_in[])
{
	t_cmds	data;

	data = calloc(sizeof(s_cmds*), 1);
	if (!data)
		return (NULL);
	data -> fd = *fd_in;
	
}

int	parse_command(char *argv[], char *envp[], int *fd[])
{
	int	i;

	i = 0;
	while ()
	//env search
	//strncmp 5
	//split
	//cat cmd
	//
}