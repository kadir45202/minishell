/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:36:38 by kcetin            #+#    #+#             */
/*   Updated: 2022/07/14 19:14:26 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void partition(char *str)
{
	add_history(str);
	printf("\n");
}

void dir()
{
	struct dirent *entry;
	DIR *folder;
	folder = opendir(".");
	while ((entry = readdir(folder)))
		{
			printf("%s\t", entry->d_name);
		}
		printf("\n");
}

int main()
{
	char *inpt;
	int i = 0;
	char *buf;
	
	buf=(char *)malloc(100*sizeof(char));
	getcwd(buf,100);
	buf = ft_strjoin(buf, "$ ");
	while (1)
	{
		inpt = readline(buf);
		if (strcmp(inpt, "ls") == 0)
			dir();
		if (strcmp(inpt, "pwd") == 0)
			printf("%s", buf);
		partition(inpt);
	}
	return (0);
}
