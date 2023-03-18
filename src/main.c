/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:25:57 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/18 16:46:47 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int *fd[2];

	if (argc < 5)
		return (ft_printf("Not enough arguments."));
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_RDWR);
	if (fd_in == -1 || fd_out == -1)
		return (perror());
	pipex(argv, envp, fd);
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		return (perror());
	return (0);
}