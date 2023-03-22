/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:32:59 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/22 23:41:14 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	fork_this(char *cmd, t_cmds *data)
{
	int		pid;

	data = cmd_split(cmd, data);
	if (pipe(data -> fd) == -1)	
		return (1);
	pid = fork();
	if (pid < 0)
		return (perror("fork: "), 0);
	if (pid == 0)
		execute(data);
	// free_ppointer(data -> args);
	free_pointer(data -> cmd);
	waitpid(pid, NULL, 0);
	return (0);
}

int	execute(t_cmds *data)
{
	char	*executable;

	executable = find_exec(data -> cmd, data -> path);
	if (!executable)
		return (1);
	printf("testing: %s\n", executable);
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

char	*create_path(char *cmd, char *path)
{
	char	*slash;
	char	*ret;

	slash = "/";
	ret = ft_strjoin(path, slash);
	if (!ret)
		return (NULL);
	ret = ft_strjoin(ret, cmd);
	if (!ret)
		return (NULL);
	return (ret);
}
