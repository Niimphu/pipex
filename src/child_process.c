/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:32:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/21 17:56:53 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	pipe_fork(char *cmd, t_cmds *data)
{
	int		pid;

	data -> args = ft_split(cmd);
	data -> cmd = (data -> args)[0];
	(data -> args)++;
	if (pipe(data -> ) == -1)
		return (1);
	pid = fork();
	if (pid < 0)
		return (perror("fork"));
	if (pid == 0)
		execute(data);
	return (0);
}

int	execute(t_cmds *data)
{
	char	*executable;

	executable = find_exec(data -> cmd, data -> path);
	if (!executable)
		return (1);
	execve(executable, data -> args, data -> envp)
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

char	*create_path(char *cmd, char *path)
{
	char	*slash;
	char	*ret;

	slash = "/";
	ret = strjoin(path, slash);
	if (!ret)
		return (NULL);
	ret = strjoin(ret, cmd);
	if (!ret)
		return (NULL);
	return (ret);
}
