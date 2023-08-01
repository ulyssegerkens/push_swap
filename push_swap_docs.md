# Push Swap documentation

## Table of Contents

1. [Stacks data structure](#stacks-data-structure)
   - [Due to random_to_rank, should I work with a bigger value type than int to accept a dataset with all int?](#due-to-random_to_rank-should-i-work-with-a-bigger-value-type-than-int-to-accept-a-dataset-with-all-int)
   
2. [Error management](#error-management)
   - [Whats the fd 2 in `ft_putendl_fd("Error", 2);`?](#whats-the-fd-2-in-ft_putendl_fderror-2)
   - [Differences between `return()` and `exit()`](#differences-between-return-and-exit)
   
3. [Inputs format](#inputs)
   - [Why do not manage the input `./push_swap "1 2 3 4"`](#why-do-not-manage-the-input-push_swap-1-2-3-4)
   - [Why does it manage `./push_swap 1 2 "3" 4`](#why-does-it-manage-push_swap-1-2-3-4)
   - [How to use `./checker 1 2 3` without giving him an input with the pipe.](#how-to-use-checker-1-2-3-without-giving-him-an-input-with-the-pipe)
   
4. [Checker: Why do not reuse `get_next_line`](#checker-why-we-cannot-reuse-get_next_line)

---
</br>

## Stacks data structure

Two int arrays, [circular buffer](https://en.wikipedia.org/wiki/Circular_buffer).</br>
[42 Stack Overflow Subject: What data structure did you use for your push_swap?](https://stackoverflowteams.com/c/42network/questions/373)

- Due to `random_to_rank()`, should I work with a bigger value type than int to accept a dataset with all int?
    
    Practically absurd :
    
    The space required to store a specific number of integers in an array depends on the size of the integer type on your system.
    
    In C, the `int` type is typically 4 bytes (or 32 bits) on most modern systems, although this can vary. You can verify the size of an `int` in bytes on your specific system by using the `sizeof` operator: `printf("Size of int: %zu bytes\n", sizeof(int));`
    
    Assuming that `int` is 4 bytes, to store `2147483647` integers in an array, you'd need:
    `2147483647 integers * 4 bytes/integer = 8589934588 bytes`
    
    That's approximately 8.59 GB.
    
    Keep in mind that this is a huge amount of memory, and trying to allocate this much space at once could fail on many systems due to insufficient available memory. If you need to work with this many integers, you may need to use a data structure or algorithm that can handle the data in chunks rather than all at once.
    
</br>

## Error management

- Whats the fd 2 in `ft_putendl_fd("Error", 2);` ?
    
    In Unix-like operating systems (which include Linux and MacOS), file descriptors `0`, `1`, and `2` are, by convention, the standard input, standard output, and standard error, respectively.
    
    Here is a brief description of each:
    
    - `0` (`STDIN_FILENO`): Standard input, usually from the keyboard.
    - `1` (`STDOUT_FILENO`): Standard output, usually to the terminal.
    - `2` (`STDERR_FILENO`): Standard error, also usually to the terminal. This is meant for outputting error messages.
    
    Therefore, in this case, `"Error"` will be sent to `stderr`, not `stdout`. This is useful because you can then redirect these streams independently of each other. For instance, you might want to redirect error messages to a log file, but keep regular output going to the terminal.
    
- Differences between `return()` and `exit()`
    
    `return()` and `exit()` are both used to terminate the execution of a program, but they differ in their usage and behavior:
    
    1. `return()`:
        - `return()` is used within a function to return a value to the caller and terminate the function's execution.
        - It is typically used in functions with a return type other than `void`. The return value can be used by the calling code.
        - When `return` is encountered, it transfers control back to the caller, and the program continues executing from where the function was called.
        - `return` allows you to gracefully exit a function and provide a result or status back to the caller.
    2. `exit()`:
        - `exit()` is used to terminate the entire program, regardless of where it is called.
        - It is typically used to indicate a significant error condition or to explicitly terminate the program's execution.
        - When `exit()` is called, the program terminates immediately, and control is handed back to the operating system.
        - `exit()` performs cleanup tasks, such as closing open files and freeing allocated memory, before terminating the program.
        - You can specify an exit status code (an integer value) as an argument to `exit()` to indicate the reason for termination. By convention, a status code of 0 indicates successful execution, while nonzero values represent different error conditions.

</br>

## Inputs

- Why do not manage the input `./push_swap "1 2 3 4"`
    
    [Related threads on slack](https://42born2code.slack.com/archives/CMX2R5JSW/p1657468649909519).</br>
    When you pass a string argument like `"1 2 3 4"` to your program, it gets interpreted as a single argument. Since you're expecting each number to be a separate argument, it throws an error.
    
- Why does it manage `./push_swap 1 2 "3" 4`
    
    When you input `"1"` as an argument in the command line, the 
    shell automatically strips away the double quotes before passing the 
    argument to your program. As a result, your program receives `1` instead of `"1"`.
    
    Unfortunately, there's no built-in way to detect if an argument was originally wrapped in quotes in the command line, because the shell removes those quotes before your program even starts.
    
- How to use `./checker 1 2 3` without giving him an input with the pipe.
    
    **Ctrl+D (EOF)**: In Unix-like systems, you can send an End-of-File (EOF) signal by pressing `Ctrl+D`. This will be recognized as the end of input by many programs. If your program reads from standard input in a loop, sending an EOF signal will break out of the loop.
    
</br>

## Checker: Why we cannot reuse `get_next_line`

This concern the new curriculum version.

The problem  is the following: GNL don’t make the difference between an empty line an an error. It return NULL in both case. So, if we reached the end of the file and we (re)call GNL, it will return NULL, and we’ll not enable to say if this NULL its due to an error in the GNL or due to an empty file.

The GNL from the previous curriculum version place the line in a buffer give as parameter and return an error. So I think it could works. 

Operation in the GNL from the new curriculum version:

```c
if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
```