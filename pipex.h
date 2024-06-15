/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:58:52 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/15 20:29:02 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define EXIT_SUCCES 0
#define EXIT_FAILURE 1
#define USAGE "./pipex infile cmd1 cmd2 cmd.. outfile"
#define MALLOC_FAILED "syscall: malloc failed"
#define USAGE_BONUS "./pipex here_doc LIMITER cmd1 cmd2 cmd... file"
#define PIPE_FAILED "syscall: pipe failed"
#define FORK_FAILED "syscall: fork failed"
#define HERE_DOC_FILE "pipex_heredoc_input.txt"

typedef struct t_data
{
	char	**envp;
	char	**command;
	pid_t	*pid;
	int		fd[2];
	char	*input_file;
	char	*output_file;
	char	*command_path;
	int		previous_pipe;
	char	*limiter;
	int		nb_command;
}	t_data;

void	print_err_and_exit(const char *err, int code, bool fail);
void	free_and_exit(const char *err, int code, t_data *data, bool fail);
void	redirect(t_data *data, int j);
void	fork_command(t_data *data, char **argv, int i);
char	*command_path(char *command, t_data *data);
void	init_struct(t_data *data, int argc, char **argv, char **envp);
void 	input_failed(char *err, char *input, char *input_join, t_data *data);


#endif