/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/23 16:35:36 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	pipex(char *argv[], char *envp[], int fd[])
{
	t_cmds	*data;
	int		i;

	data = struct_init(envp, fd);
	i = 2;
	while (argv[i + 2])
	{
		dup2(fd[0], STDIN_FILENO);
		fork_this(argv[i], data);
		i++;
	}
	// dup2(fd[1], STDOUT_FILENO);
	// fork_this(argv[i], data);
	return (0);
}

t_cmds	*struct_init(char *envp[], int fd_in[])
{
	t_cmds	*data;

	data = malloc(sizeof(t_cmds));
	if (!data)
		return (NULL);
	data -> fd[0] = dup2(fd_in[0], STDIN_FILENO);
	data -> fd[1] = dup2(fd_in[1], STDOUT_FILENO);
	if (data -> fd[0] == -1 || data -> fd[1] == -1)
		return (NULL);
	data -> cmd = NULL;
	data -> path = find_paths(envp);
	data -> args = NULL;
	if (!(data -> path))
		return (NULL);
	data -> envp = envp;
	return (data);
}

char	**find_paths(char *envp[])
{
	int		i;
	char	**ret;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) && envp[i])
		i++;
	if (!envp[i])
		return (NULL);
	ret = ft_split(envp[i], ':');
	if (!ret)
		return (NULL);
	ret[0] = path_trim(ret[0]);
	return (ret);
}
