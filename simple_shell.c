#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 16
/**
  *This updated interpreter first tries to find the command in each directory listed in the PATH environment variable using access() to check if the file is executable. If the command is found, the interpreter uses the full path to the command when calling execv(). If the command is not found, the interpreter prints an error message and continues to the next iteration of the loop.

Note that fork() is not used in this updated implementation, as it is not necessary to create a separate process to execute the command. Instead, the command is executed directly using execv(). If execv() returns, there was an error executing the command, so an error message is printed and the interpreter exits with a status of 1.
  */

int main(void)
{
	char command[256];

	while (1)
	{
		//display prompt and wait for user input
		printf("$");
		fgets(command, 256, stdin);
		//check for end of file condition 
		if (feof(stdin))
		{
			break;
		}
		//remove newline character from user input
		command[strcspn(command, "\n")] = "\0";
		//try to find command in PATH
		char *path = getenv("PATH");
		char *path_copy = strdup(path);
		char *dir = strtok(path_copy, ":");

		while (dir != NULL)
		{
			char *full_path = malloc(strlen(dir) + strlen(command)+2);
			sprintf(full_path, "%s/%s", dir ,command);

			if (access(full_path, X_OK) == 0)
			{
				args[0] = full_path;
				break;
			}
			free(full_path);
			dir = strtok(NULL, ":");
		}
		free(path_copy);
		if (args[0] == NULL)
		{
			fprintf(stderr, "%s: command not found\n",command);
			continue;
		}
		//update 0.2
		int i = 1;
		char *token = strtok(NULL, " ");

		while (token != NULL && i < MAX_ARGS -1)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		//EXECUTE the command

		execv(args[0], args);
		 fprintf(stderr, "%s: command not found\n", command);
		 exit(1);
	}
	return 0;
}
