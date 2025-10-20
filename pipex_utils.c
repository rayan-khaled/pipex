/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:59:20 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/07 13:15:18 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_error(char **args, char *path)
{
	perror("Error");
	free(path);
	free_arr(args);
	exit(1);
}

void	redirect_fd(int infile, int outfile, int fd[2], int is_first)
{
	if (is_first)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
	}
	close(fd[0]);
	close(fd[1]);
}

void	exec_child(t_child c)
{
	char	**args;
	char	*path;

	path = NULL;
	args = ft_split(c.cmd, ' ');
	if (!args || !args[0])
		child_error(args, path);
	path = find_path(args[0], c.envp);
	if (!path)
		child_error(args, path);
	redirect_fd(c.infile, c.outfile, c.fd, c.is_first);
	execve(path, args, c.envp);
	child_error(args, path);
}

void	run_child1(char **argv, char **envp, int fds[3])
{
	t_child	c;

	c.cmd = argv[2];
	c.envp = envp;
	c.infile = fds[0];
	c.outfile = fds[1];
	c.fd = &fds[2];
	c.is_first = 1;
	exec_child(c);
}

void	run_child2(char **argv, char **envp, int fds[3])
{
	t_child	c;

	c.cmd = argv[3];
	c.envp = envp;
	c.infile = fds[0];
	c.outfile = fds[1];
	c.fd = &fds[2];
	c.is_first = 0;
	exec_child(c);
}
