/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/05 02:19:45 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	pipex(char *argv[], char *envp[], int fd[])
{
	t_cmds	*data;
	int		i;

	data = struct_init(envp, fd);
	if (data == NULL)
		return (1);
	i = 2;
	while (argv[i + 2])
	{
		fork_this(argv[i], data);
		i++;
	}
	data -> i = 0;
	fork_this(argv[i], data);
	free(data);
	return (0);
}

int	fork_this(char *cmd, t_cmds *data)
{
	int	pid;
	int	pipe_fd[2];

	data = cmd_split(cmd, data);
	if (pipe(pipe_fd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (perror("fork: "), 0);
	if (pid == 0)
		child_process(data, pipe_fd);
	else
		parent_process(data, pipe_fd);
	data -> fd[0] = pipe_fd[0];
	if (data -> args)
		free_ppointer(data -> args);
	return (0);
}

void	child_process(t_cmds *data, int pipe_fd[])
{
	dup2(data -> fd[0], STDIN_FILENO);
	if (data -> i == 0)
		dup2(data -> fd[1], STDOUT_FILENO);
	else
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execute(data) == 1)
		exit(errno);
}

void	parent_process(t_cmds *data, int pipe_fd[])
{
	// int	status;
	// int	error;

	close(pipe_fd[1]);
	if (data -> i == 0)
		close(pipe_fd[0]);
	// while (wait(&status) > 0)
	// {
	// 	if (status != 0)
	// 	{
	// 		ft_printf("status: %i\n", status);
	// 		error = status;
	// 	}
	// }
	// if (error > 0)
	// 	exit(error);
}

int	execute(t_cmds *data)
{
	char	*executable;

	executable = find_exec(data);
	if (!executable)
		return (1);
	return (execve(executable, data -> args, data -> envp));
}
