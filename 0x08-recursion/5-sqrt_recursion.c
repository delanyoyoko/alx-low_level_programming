/**
 * _sqrt_recursion_helper - performs the actual recursive calculation
 * @n: an integer
 * @start: the start index
 * @end: the end index
 *
 * Return: Natural square root of a number or Error
 */
int _sqrt_recursion_helper(int n, int start, int end)
{
int mid;
int square;

if (start > end)
{
return (-1);
}

mid = (start + end) / 2;
square = mid *mid;

if (square == n)
{
return (mid);
}

if (square < n)
{
return (_sqrt_recursion_helper(n, mid + 1, end));
}
return (_sqrt_recursion_helper(n, start, mid - 1));
}

/**
 * _sqrt_recursion - determines the value of x raised to the power of y
 * @n: an integer
 *
 * Return: Natural square root of a number, or Error
 */
int _sqrt_recursion(int n)
{
if (n < 0)
{
return (-1);
}

if (n == 0 || n == 1)
{
return (n);
}
return (_sqrt_recursion_helper(n, 0, n));
}
