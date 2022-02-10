/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:58:08 by bterral           #+#    #+#             */
/*   Updated: 2022/02/10 14:26:09 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/*ft_strlen*/
# include "libft.h"

/*perror*/
# include <stdio.h>

/*open*/
# include <fcntl.h>

/*exit*/
# include <stdlib.h>

/*write*/
# include <unistd.h>

# define ARG_ERROR "Expected format error is: ./pipex file1 cmd1 cmd2 file2"
# define PIPE_ERROR "Pipe creation failed"
# define CMD_ERROR "Command not found"
# define PID_ERROR "Fail to create process"
# define FAIL_PATHS "Could not retrieve the PATH variable correctly"
# define WAITPID_FAILED "Waiting for child(ren) processes(es) failed"
# define CLOSE_FAILED "Program failed to close a file descriptor"
# define DUP_FAILED "DUP function failed"
# define EXECVE_FAILED "command execution failed"
# define INFILE_READ_FAILED "An error occured while reading the infile"
# define WRITE_ERROR "ERROR while retrieving/writing data from input/to STDOUT"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**paths;
	int		input;
	int		fd[2];
	pid_t	pid;
	char	**cmd_args;
	char	*cmd;
	int		argc;
	int		here_doc;
}	t_pipex;

/*files and paths*/
char	**get_paths(char **envp);
int		open_file(char *file_name, int rights);
void	free_paths(char **strings);
void	heredoc_infile(t_pipex *pipex, char *argv[], int argc);

/*Error functions*/
int		return_error(char *err_msg);
void	perror_exit(char *error_msg);

/*children processes*/
char	*get_cmd(t_pipex	*pipex);
int		read_input(t_pipex *pipex);
int		execute_cmd(t_pipex *pipex, char **argv, char **envp, int argv_count);
void	write_output(t_pipex *pipex);
void	open_outfile(t_pipex *pipex, char **argv, int argv_count);

#endif