/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <pymousss.dev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:32:29 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/07 10:05:05 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

/* parsing envp */
char	*pipex_find_path(char *argv, char **envp);

/* fork */
void	close_pipe(int *pipe_fd);
void	wait_processes(pid_t pid1, pid_t pid2);
void	execute_command(char *command, char **envp);
int		handle_input_process(char *ifl, char *cmd, char **envp, int *fd);
int		handle_output_process(char *otf, char *cmd, char **envp, int *fd);

/* libft */
void	ft_free_tbl(char **tbl);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif