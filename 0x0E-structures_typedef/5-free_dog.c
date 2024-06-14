#include "dog.h"
/**
 * free_dog - free the pointer from the heap
 * @d: struct of type dog
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
