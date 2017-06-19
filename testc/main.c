#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int c = 1;
    printf("%d\n",scanf("%lld",&c));
    printf("%lld %c\n",c,(char)c);
    while(c==0)
    {
        fseek(stdin,0,SEEK_END);
        scanf("%lld",&c);
        printf("%lld\n",c);
    }
    return 0;
}
