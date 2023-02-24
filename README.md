Simple and thoroughly commented shell written in C, just for educative purposes.

Created by Francis Kimani and Peter Njoroge as part of an exercise in ALX SE PROGRAMME .
The shell has the following features
	.prompts user for input with a $ sign and waits for user to enter the command
	*command execution using the execlp()function which searches for command in PATH environment variable
	*if command not found the child process prints an error message and exits
	*important to note that the implementation does not handle special characters or commands with arguments and does not implement built ins
