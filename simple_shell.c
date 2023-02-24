#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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

		pid_t pid = fork();
		if (pid < 0)
		{
			fprintf(stderr, "fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			//child process
			execlp(command , command, (char *) NULL);
			//if execclp returns there was an error
			fprintf(stderr, "%s: command not found\n", command);
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
