# The Simple Shell Project - Olaf Shell

## Synopsis
This is a humble and simple implementation of a UNIX command line interpreter.

## Description
Olaf can interpret and execute command line arguments read from the standard input. It reads line by line from a file or the terminal line. It then interprets the lines and executes it if the line is a valid command.

## Usage
All the files are to be compiled on an Ubuntu 14.04 LTS machine with:    
```gcc -Wall -Werror -Wextra -pedantic *.c -o olaf```  
  
Once compiled, to start the program, run:    
```./olaf```  
  
To exit the program, run:  
```Olaf $ exit```  
  
The Olaf shell supports most shell commands, such as ```cat```, ```pwd```, ```ls -la``` and more.  

## Built-Ins  
The following built-ins are supported by the Olaf shell:   
+ **env** - Print the current environment    
+ **setenv VARIABLE VALUE** - Initialize  a new environment ```VARIABLE```  with ```VALUE```, or modify an existing ```VARIABLE``` with ```VALUE```  
+ **unsetenv VARIABLE** - Remove a environment ```VARIABLE```  

## Return Value  
Olaf shell will exit with status 0 unless status is specified with the syntax ```exit VALUE```.  

