/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:25:57 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/31 04:39:08 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];

	if (argc < 5)
		return (ft_printf("Not enough arguments.\n"));
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd[0] == -1 || fd[1] == -1)
		error_exit(NULL, "Open: ", -1);
	pipex(argv, envp, fd);
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		error_exit(NULL, "Close: ", -1);
	return (0);
}
