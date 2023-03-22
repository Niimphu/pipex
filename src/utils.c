/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:17:11 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/22 23:26:30 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

char	*path_trim(char *str)
{
	char	*ret;

	ret = ft_strdup(str + 5);
	free(str);
	str = NULL;
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

t_cmds	*cmd_split(char *cmd, t_cmds *data)
{
	data -> args = ft_split(cmd, ' ');
	data -> cmd = (data -> args)[0];
	(data -> args)++;
	return (data);
}
