/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/22 18:36:33 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	pipex(char *argv[], char *envp[], int fd[])
{
	t_cmds	*data;
	int		i;

	data = struct_init(argv, envp, fd);
	if (data == NULL)
		return (1);
	i = 2 + data -> is_heredoc;
	while (argv[i + 2])
	{
		fork_this(argv[i], data);
		i++;
	}
	data -> i = LAST;
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
	if (ret_exec == 1)
		exit(127);
	exit(ret_exec);
}

void	parent_process(t_cmds *data, int pipe_fd[], int pid)
{
	int	status;
	int	exit_code;

	waitpid(pid, &status, 0);
	exit_code = WEXITSTATUS(status);
	free_ppointer(data -> args);
	close(pipe_fd[1]);
	if (data -> i == LAST || exit_code == 0)
		close(data -> fd[0]);
	if (data -> i == LAST)
		close(pipe_fd[0]);
	else if (exit_code == 0)
	{
		close(data -> fd[0]);
		data -> fd[0] = pipe_fd[0];
	}
	if (exit_code == 127 && data -> i == LAST)
		close_exit(127);
	else if (exit_code && exit_code != 127)
	{
		close(pipe_fd[0]);
		close_exit(exit_code);
	}
	return ;
}

int	execute(t_cmds *data)
{
	char	*executable;
	int		ret;

	executable = find_exec(data);
	if (!executable)
	{
		cmd_notfound(data);
		return (1);
	}
	ret = execve(executable, data -> args, data -> envp);
	free_pointer(executable);
	return (ret);
}
