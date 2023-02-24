Simple and thoroughly commented shell written in C, just for educative purposes.

Created by Francis Kimani and Peter Njoroge as part of an exercise in ALX SE PROGRAMME .
The shell has the following features
	.prompts user for input with a $ sign and waits for user to enter the command
	*command execution using the execlp()function which searches for command in PATH environment variable
	*handle command lines with arguments
	* handle PATH-fork must not be called if command doesnt exist
	*implements a built in exit function with no arguments
	*implements the env built in that prints current environment
	*implements a custom getline() function
