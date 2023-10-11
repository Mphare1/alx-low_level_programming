#include "search_algos.h"

/**
 * interpolation_search - Searches using interpolation search.
 * @array: array to search in.
 * @size: length of the array.
 * @value: value to look for.
 *
 * Return: first index of the value in the array else -1.
 */
int interpolation_search(int *array, size_t size, int value)
{
    size_t low1 = 0, high1 = size - 1, pos1 = 0;
    double tmp2;

    if (!array)
        return (-1);
    while (array[high1] != array[low1])
    {
        tmp2 = (double)(high1 - low1) / (array[high1] - array[low1]);
        pos1 = low1 + (tmp2 * (value - array[low1]));
        if (pos1 >= size)
        {
            printf("Value checked array[%d] is out of range\n", (int)pos1); // Changed variable name here
            break;
        }
        printf("Value checked array[%d] = [%d]\n", (int)pos1, array[pos1]); // Changed variable name here
        if (array[pos1] == value)
            return (pos1);
        else if (array[pos1] < value)
            low1 = pos1 + 1;
        else
            high1 = pos1 - 1;
    }
    return (value == array[low1] ? (int)low1 : -1);
}
