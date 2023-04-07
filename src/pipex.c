/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/07 19:13:32 by yiwong           ###   ########.fr       */
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
		parent_process(data, pipe_fd, pid);
	return (0);
}

void	child_process(t_cmds *data, int pipe_fd[])
{
	int	ret_exec;

	ret_exec = 0;
	dup2(data -> fd[0], STDIN_FILENO);
	if (data -> i == 0)
		dup2(data -> fd[1], STDOUT_FILENO);
	else
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ret_exec = execute(data);
	if (ret_exec == -1)
		exit(2);
	if (ret_exec == 1 && data -> i == 0)
		exit(127);
	exit(ret_exec);
}

void	parent_process(t_cmds *data, int pipe_fd[], int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	close(pipe_fd[1]);
	close(data -> fd[0]);
	if (data -> i == 0)
		close(pipe_fd[0]);
	else
		data -> fd[0] = pipe_fd[0];
	free_ppointer(data -> args);
	if (status)
	{
		close(pipe_fd[0]);
		exit(status);
	}
	return ;
}

int	execute(t_cmds *data)
{
	char	*executable;

	executable = find_exec(data);
	if (!executable)
		return (1);
	return (execve(executable, data -> args, data -> envp));
}
