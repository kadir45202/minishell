/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayyildi <ayyildiz_enes66@hotmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:35:13 by eayyildi          #+#    #+#             */
/*   Updated: 2022/10/31 13:16:02 by eayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

extern int	g_status;

void	get_params_control(char **a[2], int *i)
{
	if ((a[0][*i][0] == '>' || a[0][*i][0] == '<') \
	&& (a[0][*i + 1][0] == '>' || a[0][*i + 1][0] == '<') \
	&& (a[0][*i + 2][0] == '>' || a[0][*i + 2][0] == '<'))
	{
		mini_perror(RED_NOT, NULL, 2);
		g_status = 258;
	}	
}

void	single_control(char **a[2])
{
	if ((a[0][0][0] == '>' || a[0][0][0] == '<' \
		|| a[0][0][0] == '|'))
	{
		mini_perror(RED_NOT, NULL, 2);
		g_status = 258;
	}	
}

void	help_export(int j, t_prompt *prompt)
{
	char	**argv;
	int		i[2];
	int		pos;

	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	i[0] = j;
	while (argv[i[0]])
	{
		pos = var_in_envp(argv[i[0]], prompt->envp, i);
		if (pos == 1)
		{
			free(prompt->envp[i[1]]);
			prompt->envp[i[1]] = ft_strdup(argv[i[0]]);
		}
		else if (!pos)
			prompt->envp = ft_extend_matrix(prompt->envp, argv[i[0]]);
		i[0]++;
	}
}
