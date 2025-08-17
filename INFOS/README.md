# Simple Shell Project

This is a simple UNIX command interpreter written in C as part of the Holberton School curriculum.

## Description
The shell is a minimal version of the Bourne shell (sh) with basic functionality:
- Displays a prompt and waits for user input
- Executes simple commands
- Handles command lines with arguments
- Supports both interactive and non-interactive modes

## Installation
Clone this repository and compile with:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage
Interactive mode:

bash
./hsh

Non-interactive mode:

bash
echo "command" | ./hsh

Features
Basic command execution

Path handling

Built-in commands (exit, env, etc.)

Signal handling

Error handling

Authors

Holberton Students

License
This project is licensed under the MIT License.
