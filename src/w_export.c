/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:59:44 by kcetin            #+#    #+#             */
/*   Updated: 2022/11/28 13:59:45 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./minishell.h"

int	w_export(t_prompt *e)
{
	int	i;

	i = 0;
	while (e->envp[i])
	{
		printf("declare -x %s\n", e->envp[i]);
		i++;
	}
	return (0);
}
