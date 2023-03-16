/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:25:57 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/16 15:26:50 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	ready(int argc, char *argv[])
{
	//open in + out
	int fd_in;

	fd_in = open(argv[i], O_RDONLY);
	if (fd_in == -1)
		perror();
	//send commands to 
}

int	parse_command(int argc, char *argv[])
{
	//env search
	//strncmp 5
	//split
	//cat cmd
	//
}