/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/20 20:36:09 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define LAST 0

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_cmds
{
	int		fd[2];
	int		i;
	char	*cmd;
	char	**path;
	char	**args;
	char	**envp;
	char	**argv;
}			t_cmds;

int		pipex(char *argv[], char *envp[], int fd[]);
int		fork_this(char *cmd, t_cmds *data);
void	child_process(t_cmds *data, int pipe_fd[]);
void	parent_process(t_cmds *data, int pipe_fd[], int pid);
int		execute(t_cmds *data);

t_cmds	*struct_init(char *argv[], char *envp[], int fd_in[]);
char	**find_paths(t_cmds *data);
char	*create_path(char *cmd, char *path);
char	*find_exec(t_cmds *data);

void	free_cmds(t_cmds *data);
void	free_pointer(char *str);
void	free_ppointer(char **str);

void	error_exit(t_cmds *data, char *str);
void	open_error(char *filename, int fd[]);
void	cmd_notfound(t_cmds *data);

char	*path_trim(char *str);
t_cmds	*cmd_split(char *cmd, t_cmds *data);
char	**default_path(void);

void	print_array(char **arr);

#endif
