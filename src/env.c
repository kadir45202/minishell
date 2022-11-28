/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:59:14 by kcetin            #+#    #+#             */
/*   Updated: 2022/11/28 13:59:14 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./minishell.h"

int	var_in_envp(char *argv, char **envp, int i[2])
{
	int	pos;

	i[1] = 0;
	pos = ft_strchr_i(argv, '=');
	if (pos == -1)
		return (-1);
	while (envp[i[1]])
	{
		if (!ft_strncmp(envp[i[1]], argv, pos + 1))
			return (1);
		i[1]++;
	}
	return (0);
}

char	*mini_getenv(char *var, char **envp, int n)
{
	int		i;
	int		n2;

	i = 0;
	if (n < 0)
		n = ft_strlen(var);
	while (!ft_strchr(var, '=') && envp && envp[i])
	{
	n2 = n;
		if (n2 < ft_strchr_i(envp[i], '='))
			n2 = ft_strchr_i(envp[i], '=');
		if (!(ft_strncmp(envp[i], var, n2)))
		{
			return (ft_substr(envp[i], n2 + 1, ft_strlen(envp[i])));
		}
	i++;
	}
	return (NULL);
}

int	mini_unset(t_prompt *prompt)
{
	char	**argv;
	char	*aux;
	int		i[2];

	i[0] = 0;
	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(argv) >= 2)
	{
		while (argv[++i[0]])
		{
			if (argv[i[0]][ft_strlen(argv[i[0]]) - 1] != '=')
			{
				aux = ft_strjoin(argv[i[0]], "=");
				free(argv[i[0]]);
				argv[i[0]] = aux;
			}
			if (var_in_envp(argv[i[0]], prompt->envp, i))
				ft_matrix_replace_in(&prompt->envp, NULL, i[1]);
		}
	}
	return (0);
}

int	mini_export(t_prompt *prompt)
{
	char	**argv;
	int		i[2];

	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	if (ft_matrixlen(argv) >= 2)
	{
		if ((argv[1][0] == '?') || (argv[1][0] == '!')
			|| (argv[1][0] > '0' && argv[1][0] < '9'))
			mini_perror(EXP_FAI, argv[0], 127);
		else
		{
			i[0] = 1;
			help_export(i[0], prompt);
		}
	}
	else
		w_export(prompt);
	return (0);
}

char	**mini_setenv(char *var, char *value, char **envp, int n)
{
	int		i [2];
	char	*aux [2];

	if (n < 0)
		n = ft_strlen(var);
	i[0] = -1;
	aux[0] = ft_strjoin(var, "=");
	aux[1] = ft_strjoin(aux[0], value);
	free(aux[0]);
	while (!ft_strchr(var, '=') && envp && envp[++i[0]])
	{
		i[1] = n;
		if (i[1] < ft_strchr_i(envp[i[0]], '='))
			i[1] = ft_strchr_i(envp[i[0]], '=');
		if (!ft_strncmp(envp[i[0]], var, i[1]))
		{
			aux[0] = envp[i[0]];
			envp[i[0]] = aux[1];
			free(aux[0]);
			return (envp);
		}
	}
	envp = ft_extend_matrix(envp, aux[1]);
	free(aux[1]);
	return (envp);
}
