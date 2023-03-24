/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:17:11 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/24 00:12:01 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

char	*path_trim(char *str)
{
	char	*ret;

	ret = ft_strdup(str + 5);
	if (!ret)
		return (NULL);
	free(str);
	str = NULL;
	return (ret);
}

t_cmds	*cmd_split(char *cmd, t_cmds *data)
{
	data -> args = ft_split(cmd, ' ');
	data -> cmd = (data -> args)[0];
	return (data);
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

void	print_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("arr[%i]: %s\n", i, arr[i]);
		i++;
	}
	return ;
}
