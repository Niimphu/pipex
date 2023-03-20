/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:52 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/20 18:13:07 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pipex.h"

void	print_array(char **arr)
{
	int i;

	i = 0;
	ft_printf("test2: %s\n", arr[0]);
	while (arr[i])
	{
		ft_printf("arr[%i]: %s\n", i, arr[i]);
		i++;
	}
	ft_printf("arr[%i]: %s\n", i, arr[i]);
	return ;
}

int	pipex(char *argv[], char *envp[], int fd[])
{
	t_cmds *data;
	
	data = struct_init(envp, fd);
	ft_printf(argv[1]);
	return (0);
}

t_cmds *struct_init(char *envp[], int fd_in[])
{
	t_cmds	*data;

	data = malloc(sizeof(t_cmds));
	if (!data)
		return (NULL);
	data -> fd = fd_in;
	data -> cmd = NULL;
	data -> path = find_paths(envp);
	return (data);
}

char **find_paths(char *envp[])
{
	int		i;
	char	**ret;
	
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) && envp[i])
		i++;
	if (!envp[i])
		return (NULL);
	ret = ft_split(envp[i], ':');
	return (ret);
}

// int	parse_command(char *argv[], char *envp[], int *fd[])
// {
// 	int	i;

// 	i = 0;
// 	while ()
// 	//env search
// 	//strncmp 5
// 	//split
// 	//cat cmd
// 	//
// }