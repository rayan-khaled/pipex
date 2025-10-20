/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:55:24 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/07 12:30:56 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_child
{
	char	*cmd;
	char	**envp;
	int		infile;
	int		outfile;
	int		*fd;
	int		is_first;
}			t_child;

int			word_count(char *s, char c);
int			word_len(char *s, char c);
int			fill(char **result, const char *s, char c, int words);
char		**ft_split(const char *s, char c);
char		*iterate_path(char **paths, char *part_path, char *full_path,
				char *cmd);
char		*find_path(char *cmd, char **envp);
void		child_error(char **args, char *path);
void		redirect_fd(int infile, int outfile, int fd[2], int is_first);
void		exec_child(t_child c);
void		run_child1(char **argv, char **envp, int fds[3]);
void		run_child2(char **argv, char **envp, int fds[3]);
int			open_files(char **argv, int *infile, int *outfile);
int			create_pipe(int fd[2]);
int			pipex(char **argv, char **envp);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		**free_arr(char **arr);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);

#endif