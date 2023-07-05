/**
 * is_prime_number_helper - performs the actual
 * recursive calculation
 * @n: an integer
 * @divisor: a divisor
 *
 * Return: Natural square root of a number or Error
 */
int is_prime_number_helper(int n, int divisor)
{
if (n <= 2)
{
return ((n == 2) ? 1 : 0);
}

if (n % divisor == 0)
{
return (0);
}

if (divisor * divisor > n)
{
return (1);
}

return (is_prime_number_helper(n, divisor + 1));
}

/**
 * is_prime_number - determines prime numbers
 * @n: an integer
 *
 * Return: 1 if the input integer is a prime number,
 * otherwise return 0
 */
int is_prime_number(int n)
{
return (is_prime_number_helper(n, 2));
}
