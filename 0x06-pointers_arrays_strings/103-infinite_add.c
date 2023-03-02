/**
 * infinite_add - Adds two numbers
 * @n1: First number to add
 * @n2: Second number to add
 * @r: Buffer to store result
 * @size_r: Size of buffer
 *
 * Return: Pointer to the result, or 0 if result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
        int i, j, k, len1, len2, sum, carry = 0;

        for (len1 = 0; n1[len1]; len1++)
                ;
        for (len2 = 0; n2[len2]; len2++)
                ;
        if (len1 > size_r || len2 > size_r)
                return (0);
        for (i = len1 - 1, j = len2 - 1, k = 0; i >= 0 || j >= 0 || carry; i--, j--, k++)
        {
                sum = carry;
                if (i >= 0)
                        sum += n1[i] - '0';
                if (j >= 0)
                        sum += n2[j] - '0';
                r[k] = sum % 10 + '0';
                carry = sum / 10;
        }
        if (k >= size_r)
                return (0);
        r[k] = '\0';
        for (i = 0, j = k - 1; i < j; i++, j--)
        {
                sum = r[i];
                r[i] = r[j];
                r[j] = sum;
        }
        return (r);
}
