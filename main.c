#include <stdio.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>


void partition(char *str)
{
	add_history(str);
	printf("%s", str);
	printf("\n");
}

int main()
{
	DIR *folder;
	char *inpt;
	struct dirent *entry;

	folder = opendir(".");
	int i = 0;
	if (folder == NULL)
	{
		perror("Unable to read directory");
		return (1);
	}

	while (1)
	{
		inpt = readline(">");
		partition(inpt);
	}

	return 0;
}