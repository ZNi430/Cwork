#include<stdio.h>
int main()
{
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++) printf("-");
        printf("\n");
        printf("%c",92);//打印'\'符号； 
        for(int i=1;i<=n-3;i++)    printf(" ");
        printf("/\n");//以上为顶部打印 ； 
        for(int i=1;i<=n/2-2;i++){
            for(int j=0;j<i;j++)    printf(" ");
            printf("%c",92);//打印'\'符号；
            for(int j=(n/2-2-i)*2+1;j>0;j--)         printf("*"); 
            printf("/\n");
        }
        //以上为上一半打印 ；
        for(int i=1;i<=n/2-1;i++){
            for(int j=1;j<=n/2-1-i;j++){
                printf(" ");
            }
            printf("/");
            for (int j=1;j<i;j++) printf(" ");
            printf("*");
            for (int j=1;j<i;j++) printf(" ");
            printf("%c\n",92);//打印'\'符号； 
        } 
        for(int i=1;i<n;i++) printf("-");
        printf("\n");
        printf("\n");
    }
    return 0;
}
