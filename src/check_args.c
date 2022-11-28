/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:59:08 by kcetin            #+#    #+#             */
/*   Updated: 2022/11/28 13:59:09 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_args_help(char **lst, int j)
{
	j = 0;
	while (lst[j++])
	{
		if (lst[j] && lst[j + 1])
		{
			if (!(lst[j][0] == '>' && lst[j][0] == '<')
			&& (lst[j + 1][0] == '>' || lst[j + 1][0] == '<') && !lst[j + 2])
			{
				mini_perror(NEW_ERR, NULL, 258);
				return (0);
			}
		}
		if (lst[j] && lst[j + 1] && lst[j + 2])
		{
			if (!(lst[j][0] == '>' && lst[j][0] == '<')
				&& (lst[j + 1][0] == '>' || lst[j + 1][0] == '<' )
				&& (lst[j + 2][0] == '>' || lst[j + 2][0] == '<' )
				&& !lst[j + 3])
			{
				mini_perror(NEW_ERR, NULL, 258);
				return (0);
			}
		}
	}
	return (1);
}

int	check_zero_element(char	**lst)
{
	if (lst[0] && !lst[2])
	{	
		if ((lst[0][0] == '>' || lst[0][0] == '<' || lst[0][0] == '|'))
		{
			mini_perror(NEW_ERR, NULL, 258);
		}
		if ((lst[0][0] == '>' || lst[0][0] == '<' || lst[0][0] == '|'))
			return (0);
	}
	return (1);
}	

int	check_args2(char	**lst)
{
	int	j;

	j = 0;
	if (check_zero_element(lst) == 0)
		return (0);
	if (check_args_help(lst, j) == 0)
		return (0);
	return (1);
}

void	fill_nodehelp(char ***hello, char ***hello2)
{
	ft_free_matrix(hello);
	ft_free_matrix(hello2);
}
