🚀 README - Simple Shell Project
📛 Title
hsh - Holberton Simple Shell

📝 Description
This project is a minimalist UNIX command interpreter written in C, replicating basic shell functionalities like ls, env, help, cd or exit. It handles both interactive and non-interactive modes.

🛠 Requirements
Compiler: gcc 9.4.0 or higher

Authorized Functions:

c
access, chdir, close, execve, exit, fork, free, 
getline, malloc, open, opendir, read, readdir, 
signal, stat, wait, write, isatty, getcwd

🔧 Compilation
bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
🔄 What the Shell Returns
Returns 0 on successful execution

Returns 1 on error or invalid command

Returns 127 when command not found

💡 Examples
Interactive Mode:
bash
$ ./hsh
($) ls
file1 file2 file3
($) exit
Non-Interactive Mode (with pipe):
bash
echo "ls -l" | ./hsh
📖 Man Page Execution
bash
man ./man_1_simple_shell
🔍 Memory Leak Check
bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./hsh
🐛 Known Bugs
Potential memory leaks in command parsing when interrupted by signals

Minor leak in environment variable handling (about 32 bytes)