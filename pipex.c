/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:45:29 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/06 15:31:38 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(char **argv, int *infile, int *outfile)
{
	*infile = open(argv[1], O_RDONLY);
	*outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*infile < 0 || *outfile < 0)
	{
		perror("Error\n");
		return (1);
	}
	return (0);
}

int	create_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("Error\n");
		return (1);
	}
	return (0);
}

int	pipex(char **argv, char **envp)
{
	t_child	c;
	int		fd[2];
	int		fds[4];
	pid_t	pid1;
	pid_t	pid2;

	if (open_files(argv, &c.infile, &c.outfile))
		return (1);
	if (create_pipe(fd))
		return (1);
	fds[0] = c.infile;
	fds[1] = c.outfile;
	fds[2] = fd[0];
	fds[3] = fd[1];
	pid1 = fork();
	if (pid1 == 0)
		run_child1(argv, envp, fds);
	pid2 = fork();
	if (pid2 == 0)
		run_child2(argv, envp, fds);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
