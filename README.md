# The Shell Project - Olaf The Simple Shell

## Synopsis
This is a humble and simple implementation of a UNIX command line interpreter.

## Description
Olaf can interpret and execute command line arguments read from the standard input. It reads line by line from a file or the terminal line. It then interprets the lines and executes it if the line is a valid command.

## Usage
All the files are to be compiled on an Ubuntu 14.04 LTS machine with:    
```
gcc -Wall -Werror -Wextra -pedantic *.c -o olaf
```  
  
Once compiled, to start the program, run:    
```./olaf```  
  
To exit the program, run:  
```Olaf $ exit```  
  
The Olaf shell supports most shell commands, such as ```cat```, ```pwd```, ```ls -la``` and more.  

## Built-Ins  
The following built-ins are supported by the Olaf shell:   
  
+ ```env``` - Print the current environment    
+ ```setenv VARIABLE VALUE``` - Initialize  a new environment VARIABLE  with VALUE, or modify an existing VARIABLE with VALUE  
+ ```unsetenv VARIABLE``` - Remove an environment VARIABLE   

## Return Value  
Olaf shell will exit with status 0 unless status is specified with syntax ```exit VALUE```.  

## List of functions.

| Function Name | Description |
|---------------- | -----------|
|[parse_line](https://github.com/stvngrcia/simple_shell/blob/master/parsing_functions.c)    | Parses the command line looking for commands and argumements.|
|[create_Child](https://github.com/stvngrcia/simple_shell/blob/master/parsing_functions.c) | Forks the current process in order to execute another program.|
|[tokenize](https://github.com/stvngrcia/simple_shell/blob/master/parsing_functions.c) | Separates a string in to an array of tokens based on a delimiter passed to the function. |
|[count_token](https://github.com/stvngrcia/simple_shell/blob/master/parsing_functions.c) | Counts how many tokens are on a given string that is separated by a delimeter. |
|[find_path](https://github.com/stvngrcia/simple_shell/blob/master/find_path.c)|Looks through the environmental variables untill it finds the PATH variable, It then returns the index of its possition.|
|[tokenize_path](https://github.com/stvngrcia/simple_shell/blob/master/find_path.c) | Separates the PATH variable into separate strings each containing a directory in the PATH. |
|[search_directories](https://github.com/stvngrcia/simple_shell/blob/master/find_path.c) | Looks through directories stored in path_tokens for a specifc file name which represents a command. |
|[build_path](https://github.com/stvngrcia/simple_shell/blob/master/find_path.c) | Combines two strings, one representing the path directory and the other representing the command file. |
|[_strcmp](https://github.com/stvngrcia/simple_shell/blob/master/hbtlib.c) | Compares two strings and if they match the function returns 0.|
|[_strdup](https://github.com/stvngrcia/simple_shell/blob/master/hbtlib.c) | Duplicates a string.|
|[print_str](https://github.com/stvngrcia/simple_shell/blob/master/hbtlib.c)| Prints a string character by character.|
|[cd_b](https://github.com/stvngrcia/simple_shell/blob/master/builtins.c) | Changes the current working directory to the parameter passed to the command cd. |
|[env_b](https://github.com/stvngrcia/simple_shell/blob/master/builtins.c) | Prints all environmental variables available in the current shell.
|[check_built_ins](https://github.com/stvngrcia/simple_shell/blob/master/builtins.c) | Checks if a command exitst as a builtin funcition and then it returns a pointer to the right function.|
