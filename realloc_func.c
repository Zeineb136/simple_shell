#include "main.h"
#include <stdlib.h>

/**
*_realloc - function that reallocates a memory block using malloc and free
*@old_size: is the size, in bytes, of the allocated space for ptr
*@new_size: is the new size, in bytes of the new memory block.i
*@ptr: pointer
*Return: a pointer to the allocated memory.
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *m, *cp;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
		{
			return (NULL);
		}
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	cp = ptr;
	ptr = malloc(new_size);
	if (ptr == NULL)
		return (NULL);
	m = ptr;

	for (i = 0; i < old_size && i < new_size; i++)
		m[i] = cp[i];

	free(ptr);
	return (m);
}
