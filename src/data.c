/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:39:35 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/25 15:39:35 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

t_cmds	*struct_init(char *envp[], int fd_in[])
{
	t_cmds	*data;

	data = malloc(sizeof(t_cmds));
	if (!data)
		return (NULL);
	data -> fd[0] = fd_in[0];
	data -> fd[1] = fd_in[1];
	if (data -> fd[0] == -1 || data -> fd[1] == -1)
		return (NULL);
	data -> cmd = NULL;
	data -> path = find_paths(envp);
	data -> args = NULL;
	if (!(data -> path))
		return (NULL);
	data -> envp = envp;
	data -> i = 1;
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
		*envp = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";
	ret = ft_split(envp[i], ':');
	if (!ret)
		return (NULL);
	ret[0] = path_trim(ret[0]);
	return (ret);
}

t_cmds	*cmd_split(char *cmd, t_cmds *data)
{
	data -> args = ft_split(cmd, ' ');
	if (!data -> args)
		error_exit(data, "split: ");
	data -> cmd = (data -> args)[0];
	return (data);
}
