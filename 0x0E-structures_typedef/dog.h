#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a struct representing a dog
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the owner's name
 */
typedef struct dog
{
    char *name;
    float age;
    char *owner;
} dog_t;

#endif /* DOG_H */
