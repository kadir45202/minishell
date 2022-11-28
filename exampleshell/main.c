/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:36:38 by kcetin            #+#    #+#             */
/*   Updated: 2022/07/25 15:14:30 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*input;
	char	*dir;
	char	*new;
	dir = (char *)malloc(100 * sizeof(char));
	getcwd(dir, 100);
	input = readline(ft_strjoin(dir, " sahte $ "));
	new = space_jumper(input);
	if (strcmp(input, "pwd") == 0)
		printf("%s\n", dir);
	else if (ft_strstr(input, "echo -n"))
		printf("%s", ft_strchr(input, 'n') + 2);
	else if (ft_strstr(input, "echo "))
		printf("%s\n", ft_strchr(new, 32) + 1);
	else if (ft_strstr(input, "cd "))
		chdir(ft_strchr(input, 32) + 1);
	else if (ft_strstr(input, "env"))
		enviroment(env);
	else
		printf("bilinmeyen argüman : %s\n", input);
	partition(input);
	free(input);
	main(argc, argv, env);
}
