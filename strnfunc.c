#include "main.h"

/* BELOW ARE THE CUSTOM BUILTIN FUNCTIONS FOR MANIPULATING STRINGS */

/**
 * _strlen - returns the length of a string
 * @s: string to get the length of
 * Return: the length of the string
 */
size_t _strlen(const char *s)
{
	size_t length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: the concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strcpy - copies a string to another
 * @dest: destination string
 * @src: source string
 * Return: the number of characters copied
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
