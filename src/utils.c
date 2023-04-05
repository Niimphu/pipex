/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:17:11 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/05 01:48:11 by yiwong           ###   ########.fr       */
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

char	*find_exec(t_cmds *data)
{
	char	*test;
	int		i;

	i = 0;
	data -> path = find_paths(data);
	while (data -> path[i])
	{
		test = create_path(data -> cmd, data -> path[i++]);
		if (!test)
			return (NULL);
		if (access(test, X_OK) == 0)
		{
			free_ppointer(data -> path);
			return (test);
		}
	}
	free_ppointer(data -> path);
	free_pointer(test);
	return (NULL);
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
