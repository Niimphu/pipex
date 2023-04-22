/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:58:06 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/22 16:58:06 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

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
