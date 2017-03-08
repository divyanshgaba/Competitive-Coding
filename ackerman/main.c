
#include <stdio.h>
int ack(int m, int n)
{
  if (m == 0) return n+1;
  if (n == 0) return ack( m - 1, 1 );
  return ack( m - 1, ack( m, n - 1 ) );
}

int main()
{ int i,j;
  for (i = 0; i < 6; ++i)
    for (j = 0; j < 6; ++j)
      printf("ack(%d,%d) = %d\n", i, j, ack(i,j));

  return 0;
}
