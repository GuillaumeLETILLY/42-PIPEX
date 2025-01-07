/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <pymousss.dev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:49:01 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/07 09:59:34 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	(void)argc;
	if (pipe(pipe_fd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (close_pipe(pipe_fd), perror("fork"), 1);
	if (pid1 == 0)
		handle_input_process(argv[1], argv[2], envp, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		return (close_pipe(pipe_fd), perror("fork"), 1);
	if (pid2 == 0)
		handle_output_process(argv[4], argv[3], envp, pipe_fd);
	close_pipe(pipe_fd);
	wait_processes(pid1, pid2);
	return (0);
}
