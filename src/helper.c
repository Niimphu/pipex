/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:17:11 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/20 18:39:32 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

char	*path_trim(char *str)
{
	char	*ret;

	ret = strdup(str + 5);
	free(str);
	str = NULL;
	return (ret);
}

void	print_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_printf("arr[%i]: %s\n", i, arr[i]);
		i++;
	}
	return ;
}
