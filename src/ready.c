/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:25:57 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/16 18:28:57 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	ready(int argc, char *argv[], char *envp[])
{
	//open in + out
	int fd_in;
	int	ft_out;

	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_RDWR);
	if (fd_in == -1 || fd_out == -1)
		perror();
	
	//send commands to 
}

int	parse_command(int argc, char *argv[], envp[])
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