/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:25:57 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/25 16:17:52 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_cmds	*data;

	if (argc < 5)
		return (ft_printf("Not enough arguments."));
	data = struct_init(argv, envp);
	if (data == NULL)
		return (1);
	data -> fd[1] = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (data -> fd[1] == -1)
		open_error((argv[argc - 1]), data);
	if (!ft_strncmp(argv[1], "here_doc", 9))
		data -> fd[0] = heredoc(argv[2]);
	else
		data -> fd[0] = open(argv[1], O_RDONLY, 0666);
	if (data -> fd[0] == -1)
		open_error((argv[1]), data);
	pipex(data);
	close(data -> fd[1]);
	return (0);
}

int	heredoc(char *limiter)
{
	int		fd;
	char	*input;

	input = NULL;
	fd = open("temp", O_RDWR | O_CREAT, 0666);
	while (fd != -1)
	{
		input = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input, limiter, ft_strlen(input) - 1) == 0
			&& ft_strlen(input) == ft_strlen(limiter) + 1)
			break ;
		write(fd, input, ft_strlen(input));
	}
	close(fd);
	fd = open("temp", O_RDONLY, 0666);
	return (fd);
}
