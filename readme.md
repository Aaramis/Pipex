# pipex

In this projec't we'll make our own implementation of the pipes we know from shell (``|``). To do so, we will start using set of functions that will introduce to us the concept of multiple processes, using pipes, forks and dups. In this project we are asked to code a program which will immitate the behavior of this shell command:
```shell
$> < file1 cmd1 | cmd2 > file2
```
The idea of the program is that we take an infile and two commands, and pass the infile as the standard input to the first command, and then pipe the output of the first command to the second command, and finally save it all to a second file. 
* ``<``: Used to denote that we will be passing the next argument as the standard input (stdin)
* ``file1``: Path to the file we want to open as the standard input. It must exist and should be opened read-only
* ``cmd1``: First command. It will receive the stdin and run a command with it, if applicable
* ``|``: Transforms the standard output (stdout) of the first command into the standard input (stdin) for the next command
* ``cmd2``: Receives the standard output of the first command as stdin and runs a command with it, if applicable
* ``>``: Redirects whatever is on the standard output (stdout) into a file, creating it if it does not exist
* ``file2``: Path to an output file which may or may not exist. If it exists, it will be truncated (emptied) and should be opened write-only

| Function | Descripton | Return Value |
| :-------:| :---------:| :----------: |
| ``pipe(fd)`` | Recives a ``fd[2]`` and opens ``fd[0]`` for reading and ``fd[1]`` for writing | ``-1`` on error |
| ``fork()`` | Splits process creating a child process with pid ``0`` | Process id of both processess (child = ``0``, parent > ``0``), ``-1`` on error |
| ``dup2(oldfd, newfd)`` | Closes ``newfd`` if needed, then duplicates ``oldfd`` into ``newfd`` | ``-1`` on error |
| ``execve(path, cmd, envp)`` | Receives full path of executable, NULL-terminated array of parameters, and environment. Replaces current process with that of the specified command | ``-1`` on error |

## usage:

It should be executed in this way:
```bash
$> make
$> ./pipex file1 cmd1 cmd2 file2
```

The execution of the pipex program should do the same as the next shell command:
```bash
$> < file1 cmd1 | cmd2 > file2
```

## examples:

```bash
$> ./pipex infile "ls -l" "wc -l" outfile
```
should be the same as:  ```< infile ls -l | wc -l > outfile```

```bash
$> ./pipex infile "grep a1" "wc -w" outfile
```
should be the same as:  ```< infile grep a1 | wc -w > outfile```


## Bonus Part 1:

Bonus part allows to handle multiple pipes 
It should be executed in this way:
```bash
$> make bonus
$>  ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file
```

The execution of the pipex program should do the same as the next shell command:
```bash
$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```