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
		return (NULL);
	ret = ft_split(data -> envp[i], ':');
	if (!ret)
		return (NULL);
	ret[0] = path_trim(ret[0]);
	return (ret);
}

char	**default_path(void)
{
	char	**ret;

	ret = malloc(sizeof(char **) + 1);
	if (!ret)
		return (NULL);
	ret[0] = ft_strdup("/usr/local/bin");
	ret[1] = ft_strdup("/usr/bin");
	ret[2] = ft_strdup("/bin");
	ret[3] = ft_strdup("/usr/sbin");
	ret[4] = ft_strdup("sbin");
	ret[5] = NULL;
	return (ret);
}

t_cmds	*cmd_split(char *cmd, t_cmds *data)
{
	int		i;
	int		j;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			j = i + 1;
			while (cmd[j] != cmd[i] && cmd[j])
				j++;
			if (cmd[j])
			{
				cmd[i] = 26;
				cmd[j] = 26;
				i = j;
			}
		}
		else if (cmd[i] == ' ')
			cmd[i] = 26;
		i++;
	}
	data -> args = ft_split(cmd, 26);
	data -> cmd = data -> args[0];
	return (data);
}
