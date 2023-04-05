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
	data -> cmd = NULL;
	data -> path = NULL;
	data -> args = NULL;
	data -> envp = envp;
	data -> i = 1;
	return (data);
}

char	**find_paths(t_cmds *data)
{
	int		i;
	char	**ret;

	i = 0;
	while (ft_strncmp(data -> envp[i], "PATH=", 5) && data -> envp[i])
		i++;
	if (!data -> envp[i])
		*data -> envp = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";
	ret = ft_split(data -> envp[i], ':');
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
