#include "dog.h"
/**
 * new_dog - create a new struct of type dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to the new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int name_len = strlen(name);
	int owner_len = strlen(owner);

	d = malloc(sizeof(struct dog));
	if (d == NULL)
		return (NULL);

	d->name = malloc(sizeof(char) * (name_len + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(sizeof(char) * (owner_len + 1));
	if (d->owner == NULL)
	{
		free(d);
		free(d->name);
		return (NULL);
	}
	strcpy(d->name, name);
	strcpy(d->owner, owner);
	d->age = age;

	return (d);
}
