/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/28 19:03:13 by yiwong           ###   ########.fr       */
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
	if (data -> path)
		free_ppointer(data -> path);
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
		close(pipe_fd[1]);
	data -> fd[0] = pipe_fd[0];
	if (data -> args)
		free_ppointer(data -> args);
	return (0);
}

int	child_process(t_cmds *data, int pipe_fd[])
{
	dup2(data -> fd[0], STDIN_FILENO);
	if (data -> i == 0)
		dup2(data -> fd[1], STDOUT_FILENO);
	else
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execute(data) == 1)
		error_exit(data, NULL);
	return (0);
}

int	execute(t_cmds *data)
{
	char	*executable;

	executable = find_exec(data -> cmd, data -> path);
	if (!executable)
		return (1);
	execve(executable, data -> args, data -> envp);
	return (0);
}
