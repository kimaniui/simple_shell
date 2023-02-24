#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 16

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

		int i = 0;
		char *token = strtok(command, " ");

		while (token != NULL && i < MAX_ARGS -1)
		{
			args[i]= token;
			token =strtok(NULL, " ");
			i++
		}
		args[i] = NULL;

		pid_t pid = fork();
		if (pid < 0)
		{
			fprintf(stderr, "fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			//child process
			execvp(args[0] , args);
			//if execvp returns there was an error
			fprintf(stderr, "%s: command not found\n", args[0]);
			exit(1);
		}
		else
		{
			//parent process
			waitpid(pid, NULL, 0);
		}
	}
	return 0;
}
