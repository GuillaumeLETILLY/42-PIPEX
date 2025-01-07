/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <pymousss.dev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:03:13 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/07 10:00:02 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	execute_command(char *command, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(command, ' ');
	if (!cmd)
		(perror("malloc error"), exit(1));
	path = pipex_find_path(cmd[0], envp);
	if (!path)
	{
		ft_free_tbl(cmd);
		(perror("command not found"), exit(1));
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_free_tbl(cmd);
		(perror("execve"), exit(1));
	}
}

void	close_pipe(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

int	handle_input_process(char *ifl, char *cmd, char **envp, int *fd)
{
	int	input_fd;

	input_fd = open(ifl, O_RDONLY);
	if (input_fd < 0)
		return (perror(ifl), 1);
	close(fd[0]);
	dup2(input_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(input_fd);
	close(fd[1]);
	execute_command(cmd, envp);
	return (1);
}

int	handle_output_process(char *otf, char *cmd, char **envp, int *fd)
{
	int	output_fd;

	output_fd = open(otf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd < 0)
		return (perror(otf), 1);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	close(fd[0]);
	execute_command(cmd, envp);
	return (1);
}

void	wait_processes(pid_t pid1, pid_t pid2)
{
	int	status;

	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
