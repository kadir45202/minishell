/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:00:13 by kcetin            #+#    #+#             */
/*   Updated: 2022/11/28 14:00:15 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./minishell.h"

extern int	g_status;

void	handle_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 15;
		ioctl(0, TIOCSTI, "\n");
	}
}

void	free_2(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

char	*get_here_str(char *str[2], size_t len, char *limit)
{
	char	*temp;

	while (g_status != 130 && (!str[0] || ft_strncmp(str[0], limit, len) \
		|| ft_strlen(limit) != len) && g_status != -1)
	{
		signal(SIGINT, handle_heredoc);
		if (g_status == 15)
		{	
			free_2 (str[0], str[1]);
			return (0);
		}
		temp = str[1];
		str[1] = ft_strjoin(str[1], str[0]);
		free(temp);
		free(str[0]);
		str[0] = readline("> ");
		if (!str[0])
			break ;
		temp = str[0];
		str[0] = ft_strjoin(str[0], "\n");
		free(temp);
		len = ft_strlen(str[0]) - 1;
	}
	free(str[0]);
	return (str[1]);
}

int	get_here_doc(char *str[2], char *aux[2])
{
	int		fd[2];

	g_status = 0;
	if (pipe(fd) == -1)
	{
		mini_perror(PIPERR, NULL, 1);
		return (-1);
	}
	str[1] = get_here_str(str, 0, aux[0]);
	write(fd[WRITE_END], str[1], ft_strlen(str[1]));
	free(str[1]);
	close(fd[WRITE_END]);
	if (g_status == 130)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}
