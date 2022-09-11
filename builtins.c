/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:37:12 by kcetin            #+#    #+#             */
/*   Updated: 2022/07/25 13:59:42 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	partition(char *str)
{
	add_history(str);
}

void    enviroment(char **str)
{
	while (*str != NULL)
	{
		printf("%s\n", *str);
		*str++;
	}
}

char	*space_jumper(char *str)
{
	if(str == NULL)
		return NULL;
	int	i;
	int j;
	char *new;

	j = 0;
	i = 0;
	new = malloc(ft_strlen(str) + 1 * sizeof(char));
	while(str[i] < 33)
		i++;
	while(str[i] != '\0')
	{
		new[j] = str[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}