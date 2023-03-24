/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:32:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/24 19:02:02 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

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
	if (execute(data))
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

char	*find_exec(char *cmd, char **paths)
{
	char	*test;
	int		i;

	i = 0;
	while (paths[i])
	{
		test = create_path(cmd, paths[i++]);
		if (!test)
			return (NULL);
		if (access(test, X_OK) == 0)
			return (test);
	}
	return (NULL);
}
