#include "dog.h"

/**
 * print_dog - prints the elemnts of dog struct
 * @d: struct of type dog
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		printf("Name: %s\n", "(nil)");
	printf("Name: %s\n", d->name);

	if (d->age <= 0)
		printf("Age: %s\n", "(nil)");
	printf("Age: %f\n", d->age);

	if (d->owner == NULL)
		printf("Owner: %s\n", "(nil)");
	printf("Owner: %s\n", d->owner);
}
