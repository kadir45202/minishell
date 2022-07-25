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

void	partition(char *str)
{
	add_history(str);
	printf("\n");
}

void	dir(void)
{
	struct dirent	*entry;
	DIR				*folder;

	folder = opendir(".");
	while ((entry = readdir(folder)))
	{
		printf("%s\t", entry->d_name);
	}
}

int	main(void)
{
	char	*input;
	char	*buf;

	buf = (char *)malloc(100 * sizeof(char));
	getcwd(buf, 100);
	input = readline(ft_strjoin(buf, " sahte $ "));
	if (strcmp(input, "ls") == 0)
		dir();
	else if (strcmp(input, "pwd") == 0)
		printf("%s", buf);
	else if (strstr(input, "echo "))
		printf("%s", strchr(input, 32) + 1);
	else
		printf("bilinmeyen argüman : %s", input);
	partition(input);
	free(input);
	main();
}
