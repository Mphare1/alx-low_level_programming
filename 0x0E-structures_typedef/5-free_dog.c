#include <stdlib.h>
#include "dog.h"

/**
  * a function that frees dogs
  * @d: 
  *
  * Return: nothing
  */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->owner);
		free(d->name);
		free(d);
	}
}
