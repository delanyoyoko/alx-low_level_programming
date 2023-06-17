#include <stdlib.h> 
 #include <time.h> 
 /* more headers goes there */ 
  
 /* betty style doc for function main goes there */ 
 int main(void) 
{
int n;
int last;
  
srand(time(0)); 
n = rand() - RAND_MAX / 2;
last = n % 10;
/* your code goes there */
if (last == 0)
{
  printf("Last digit of %d and is 0", n);
} else if (last < 6)
{
  printf("Last digit of %d and is less than 6 and not 0", n)
} else if (last > 5)
{
  printf("Last digit of %d and is greater than 5", n)
}

return (0);
}
