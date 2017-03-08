
#include <stdio.h>

int main(){
    int a[3],b[3],ascore=0,bscore=0,i,k;
    for (i=0;i<3;i++) scanf("%d",&a[i]);
    for (i=0;i<3;i++) {
        scanf("%d",&b[i]);
    k=a[i]>b[i]?ascore++:(a[i]<b[i]?bscore++:1);
    }
    printf("%d %d\n",ascore,bscore);

    return 0;
}
