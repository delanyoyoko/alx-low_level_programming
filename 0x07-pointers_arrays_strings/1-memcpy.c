/**
 * _memcpy - copies memory area
 * @dest: the destination array
 * @src: the source array
 * @n: the given length
 *
 * Return: A pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
char *p_dest = dest;
char *p_src = src;
unsigned int i = 0;

while (i < n)
{
p_dest[i] = p_src[i];
i++;
}
return (dest);
}
