# Everything you need to know to start coding your own shell

This project contains a series of exercises to build a simple UNIX shell. The exercises cover fundamental concepts such as process management, argument parsing, environment variables, and file handling.

### Files

- `shell.h`: The common header file containing includes and function prototypes.
- `pid_exercises.c`: Demonstrates `getppid()` and contains a script to find `pid_max`.
- `arg_and_input.c`: Exercises on command-line arguments and reading user input with `getline`.
- `exec_and_wait.c`: Combines `fork()`, `execve()`, and `wait()` to execute a command.
- `env_functions.c`: Functions to work with environment variables, including a custom `_getenv()`.
- `path_list.c`: Demonstrates how to handle the `PATH` environment variable by printing its directories or building a linked list.
- `env_modifiers.c`: Implements custom `_setenv()` and `_unsetenv()` functions.
- `simple_shell.c`: A basic, functional shell that reads a full path command and executes it.
