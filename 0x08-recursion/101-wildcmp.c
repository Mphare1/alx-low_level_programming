/**
 * wildcmp - compares two strings and returns 1 if they can be considered identical,
 *           otherwise returns 0. The second string can contain the special character *,
 *           which can replace any string (including an empty string).
 *
 * @s1: the first string to compare
 * @s2: the second string to compare
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
    /* If both strings are empty, they are identical */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    /* If the second string starts with *, try to match the rest of the strings */
    if (*s2 == '*')
    {
        /* Skip the * in the second string */
        s2++;

        /* If the second string is empty, everything matches */
        if (*s2 == '\0')
            return (1);

        /* Try to match the rest of the second string with the first string */
        while (*s1 != '\0')
        {
            if (wildcmp(s1, s2))
                return (1);

            s1++;
        }

        /* If we got here, the second string doesn't match the first string */
        return (0);
    }

    /* If the characters match, continue comparing */
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    /* If the characters don't match and there is no *, the strings are not identical */
    return (0);
}
