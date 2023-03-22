/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:14:13 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/21 03:14:13 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	error_exit(t_cmds *data, char *strerr)
{
	free_cmds(data);
	perror(strerr);
	exit(errno);
}
