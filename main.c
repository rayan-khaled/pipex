/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:55:21 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/07 12:59:44 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (pipex(argv, envp) == -1)
		return (1);
	return (0);
}
