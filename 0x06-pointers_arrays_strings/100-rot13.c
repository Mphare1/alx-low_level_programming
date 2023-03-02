/**
 * rot13 - Encodes a string using rot13 encryption
 * @s: The string to be encoded
 *
 * Return: A pointer to the resulting string
 */
char *rot13(char *s)
{
  int i, j;
  char *rot = s;

  for (i = 0; s[i] != '\0'; i++)
  {
    for (j = 0; (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'); j++)
    {
      if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
      {
        rot[i] = s[i] + 13;
        break;
      }
      else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
      {
        rot[i] = s[i] - 13;
        break;
      }
    }
  }

  return rot;
}
