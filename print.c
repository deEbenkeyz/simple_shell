#include "main.h"

/**
 * _putchar - write a character
 * @c: the character to write
 * Return: the number of characters written
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _print_data - prints a string
 * @str: the string to print
 * Return: the number of characters printed
 */
int _print_data(const char *str)
{
    int count = 0;

    /* loop through the characters in the string and print them */
    while (*str != '\0')
    {
        _putchar(*str++);
        count++;
    }

    return count;
}

/**
 * _print_d_notfound - prints the command not found message
 * @count: the count
 * @args: the arguments passed to the shell
 * @argv: argument from main function
 * Return: 0
 */
int _print_d_notfound(int count, char **args, char **argv)
{
    int argslen = strlen(args[0]), argvlen = strlen(argv[0]);
    char error[] = ": not found\n";
    char num = count + '0';
    
    /* Calculate the size needed for the message */
    size_t message_size = strlen(argv[0]) + 10 + argslen + argvlen;

    char *message = malloc(message_size);

    if (message == NULL)
        return -1;

    snprintf(message, message_size, "%s: %c: %s%s", argv[0], num, args[0], error);

    write(2, message, _strlen(message));

    free(message);

    return 0;
}
