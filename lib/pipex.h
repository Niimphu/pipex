/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/03/21 19:06:32 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_cmds
{
	int		fd[2];
	char	*cmd;
	char	**path;
	char	**args;
	char	**envp;
}			t_cmds;

int		pipex(char *argv[], char *envp[], int fd[]);
t_cmds	*struct_init(char *envp[], int fd_in[]);
char	**find_paths(char *envp[]);
char	*path_trim(char *str);

void	free_cmds(t_cmds *data);
void	free_pointer(char *str);
void	free_ppointer(char **str);

int		pipe_fork(char *cmd, t_cmds *data);
int		execute(t_cmds *data);
char	*find_exec(char *cmd, char **paths);
char	*create_path(char *cmd, char *path);

void	print_array(char **arr);

#endif
