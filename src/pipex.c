/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/17 17:16:19 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int fd_in;
	int	ft_out;

	if (argc < 5)
		return (ft_printf("Not enough arguments."));
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_RDWR);
	if (fd_in == -1 || fd_out == -1)
		perror();
}