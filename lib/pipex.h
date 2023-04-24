/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:11:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/04/24 17:01:19 by yiwong           ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"

typedef struct s_cmds
{
	int		is_heredoc;
	int		fd[2];
	int		i;
	char	*cmd;
	char	**path;
	char	**args;
	char	**envp;
	char	**argv;
}			t_cmds;

int		heredoc(char *limiter);

int		pipex(t_cmds *data);
int		fork_this(char *cmd, t_cmds *data);
void	child_process(t_cmds *data, int pipe_fd[]);
void	parent_process(t_cmds *data, int pipe_fd[], int pid);
int		execute(t_cmds *data);

t_cmds	*struct_init(char *argv[], char *envp[]);
char	**find_paths(t_cmds *data);
char	*create_path(char *cmd, char *path);
char	*find_exec(t_cmds *data);

void	free_pointer(char *str);
void	free_ppointer(char **str);

void	close_exit(int code);
void	open_error(char *filename, t_cmds *data);
void	cmd_notfound(t_cmds *data);

char	*path_trim(char *str);
t_cmds	*cmd_split(char *cmd, t_cmds *data);
char	**default_path(void);

void	print_array(char **arr);

#endif
