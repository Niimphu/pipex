/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:25:57 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/22 18:54:56 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];

	if (argc < 5)
		return (ft_printf("Not enough arguments."));
	fd[1] = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd[1] == -1)
		open_error((argv[argc - 1]), fd);
	if (!ft_strncmp(argv[1], "here_doc", 9))
		fd[0] = heredoc(argv[2]);
	else
		fd[0] = open(argv[1], O_RDONLY, 0666);
	if (fd[0] == -1)
		open_error((argv[1]), fd);
	pipex(argv, envp, fd);
	close(fd[1]);
	return (0);
}
