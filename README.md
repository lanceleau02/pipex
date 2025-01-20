<div align="center">

![](https://raw.githubusercontent.com/ayogun/42-project-badges/refs/heads/main/badges/pipexe.png)

# **pipex**

**Redirections and Pipes.**

</div>

## Features

- Recreate the functionality of a shell pipeline (`< file1 cmd1 | cmd2 > file2`).
- Handle file redirection for input and output.
- Execute multiple commands in sequence using pipes.
- Manage process creation and inter-process communication (IPC).
- Implement error handling for invalid commands, files, or arguments.
- Support path resolution for executable commands.
- Ensure compliance with system calls like `fork`, `pipe`, `dup2`, and `execve`.

## Installation

1. Clone the repository:

```bash
git clone https://github.com/lanceleau02/pipex.git
```

2. Navigate to the project directory:

```bash
cd pipex
```

3. Compile the program:

```bash
make
```

## Usage

Here's an example of how you can run it:

```bash
./pipex infile "ls -l" "wc -l" outfile
```

## License

This project is licensed under the **42 School** License.

- **Educational Use Only**: This project is intended for educational purposes at the 42 School as part of the curriculum.
- **Non-commercial Use**: The code may not be used for commercial purposes or redistributed outside of the 42 School context.
- **No Warranty**: The project is provided "as-is", without any warranty of any kind.

For more details, see the [LICENSE](https://github.com/lanceleau02/pipex/blob/main/LICENSE) file.

## Resources

- [pipe() system call (GeeksforGeeks)](https://www.geeksforgeeks.org/pipe-system-call/)
- [I/O Redirection (Advanced Bash-Scripting Guide)](https://tldp.org/LDP/abs/html/io-redirection.html)
- [Processes (The GNU C Library)](https://www.gnu.org/software/libc/manual/html_node/Processes.html)
- [perror(3) (Linux manual page)](https://man7.org/linux/man-pages/man3/perror.3.html)
- [pipe(2) (Linux manual page)](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [fork(2) (Linux manual page)](https://man7.org/linux/man-pages/man2/fork.2.html)
- [execve(2) (Linux manual page)](https://man7.org/linux/man-pages/man2/execve.2.html)
- [dup2(2) (Linux manual page)](https://man7.org/linux/man-pages/man2/dup2.2.html)
- [open(2) (Linux manual page)](https://man7.org/linux/man-pages/man2/open.2.html)
