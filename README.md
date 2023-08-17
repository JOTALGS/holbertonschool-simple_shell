#  Simple Shell

This program is a simple implementation of a shell that can accept user input, parse the input into separate commands and arguments, and execute the specified command.
It uses the getpatharray function to retrieve the directories specified by the PATH environment variable and it uses the check_cmd function to search for the specified command in those directories.

## Showcase
Here is a quick demonstration of _printf in action:

```
 ./hsh
 $ls
 bin  boot  dev  etc  hello_world  home  lib  lib32  lib64  libx32  media  mnt  opt  preprocessor  proc  root  run  sbin  srv  sys  tmp  usr  var  welcome  y
 $
```


```
 ./hsh
 $pwd
 root@bd5438578880:~/holbertonschool-simple_shell#
 $
```


```
 ./hsh
 $/bin/ls
 bin  boot  dev  etc  hello_world  home  lib  lib32  lib64  libx32  media  mnt  opt  preprocessor  proc  root  run  sbin  srv  sys  tmp  usr  var  welcome  y
 $
```


## Prerequisites
Compiled on Ubuntu 20.04 LTS* Compile code with: "gcc -Wall -Werror -Wextra-pedantic -std=gnu89 *.c -o hsh"

* Include the "shell.h" header file in main program. Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* Hndling the “end of file” condition (Ctrl+D).
* Hanling the command line with arguments.
* Handle the PATH.
* Support the exit features and the exit status.
* Handling the command seperator.
* Support the file input.

###   Features

    Accepts user input and parses it into separate commands and arguments
    Retrieves the directories specified by the PATH environment variable using the getpatharray function
    Searches for the specified command in the directories using the check_cmd function
    Creates a child process to execute the specified command
    Handles errors and provides feedback to the user, such as printing an error message when a command is not found

## Requirements
- Allowed editors: vi, vim, emacs
- All the files will be compiled on Ubuntu 20.04 LTS
- No more than 5 functions per file

### Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### Usage

 Enter any valid command, such as ls or pwd, and the program will search for it in the directories specified by the PATH environment variable.
If the command is found, the program will create a child process to execute it. If the command is not found, an error message will be printed.

To exit the program, the user can enter the exit command at the prompt, or pressing the combination **Ctrl. + d** . This will cause the program to terminate and free any allocated memory.

## Authors

* **Franco Musso** - *Holberton Student* - [Franco Musso](https://github.com/FrancoMuVa)
* **Jose Gil** - *Holberton Student* - [Jose Gil](https://github.com/JOTALGS)
