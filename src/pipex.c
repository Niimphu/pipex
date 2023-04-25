/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/25 17:30:08 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	pipex(t_cmds *data)
{
	int		i;

	i = 2 + data -> is_heredoc;
	while (data -> argv[i + 2])
	{
		fork_this(data -> argv[i], data);
		i++;
	}
	data -> i = LAST;
	fork_this(data -> argv[i], data);
	return (0);
}

int	fork_this(char *cmd, t_cmds *data)
{
	int	pid;

	data = cmd_split(cmd, data);
	if (pipe(data -> pipe_fd) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (perror("fork: "), 0);
	if (pid == 0)
		child_process(data);
	else
	{
		free_ppointer(data -> args);
		parent_process(data, pid);
	}
	return (0);
}

void	child_process(t_cmds *data)
{
	int	ret_exec;

	ret_exec = 0;
	dup2(data -> fd[0], STDIN_FILENO);
	if (data -> i == 0)
		dup2(data -> fd[1], STDOUT_FILENO);
	else
		dup2(data -> pipe_fd[1], STDOUT_FILENO);
	close_reset(data -> pipe_fd[0]);
	close_reset(data -> pipe_fd[1]);
	ret_exec = execute(data);
	if (ret_exec == -1)
		exit(2);
	if (ret_exec == 1)
		exit(127);
	exit(ret_exec);
}

void	parent_process(t_cmds *data, int pid)
{
	int	status;
	int	exit_code;

	waitpid(pid, &status, 0);
	exit_code = WEXITSTATUS(status);
	close_reset(data -> pipe_fd[1]);
	if (data -> i == LAST || exit_code == 0)
		close_reset(data -> fd[0]);
	if (data -> i == LAST || (exit_code == 127 && data -> i != LAST))
		close_reset(data -> pipe_fd[0]);
	else if (exit_code == 0)
	{
		close_reset(data -> fd[0]);
		data -> fd[0] = data -> pipe_fd[0];
	}
	if (exit_code == 127 && data -> i == LAST)
		close_exit(127);
	else if (exit_code && exit_code != 127)
	{
		close_reset(data -> pipe_fd[0]);
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
