/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/21 18:16:43 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

int	pipex(char *argv[], char *envp[], int fd[])
{
	t_cmds	*data;
	int		i;

	data = struct_init(envp, fd);
	ft_printf("test print: %s, %s\n", argv[2], data -> cmd);
	print_array(data -> path);
	i = 2;
	while (argv[i + 1])
	{
//		pipe_fork(argv[i], data);
		i++;
	}
	return (0);
}

t_cmds	*struct_init(char *envp[], int fd_in[])
{
	t_cmds	*data;

	data = malloc(sizeof(t_cmds));
	if (!data)
		return (NULL);
	data -> fd[0] = dup2(fd_in[0], 0);
	data -> fd[1] = dup2(fd_in[1], 1);
	data -> cmd = NULL;
	data -> path = find_paths(envp);
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
