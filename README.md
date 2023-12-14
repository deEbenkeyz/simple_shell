# Simple Shell Project

## Overview

This is a simple shell project written in C. The shell supports basic functionalities, including executing commands, built-in commands, and handling signals.

## Features

- Execute commands with or without specifying a path.
- Handle built-in commands like `exit`, `cd`, and `env`.
- Display a prompt when the shell is in interactive mode.
- Signal handling for SIGINT (Ctrl+C).

## Getting Started

### Prerequisites

- Linux-based operating system.
- GCC compiler.

### Compilation

To compile the shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o shell



