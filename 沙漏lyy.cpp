#include <stdio.h>

int main(){
    int t,i;
    scanf("%d",&t);
    while(t--){
        int n,r;
        scanf("%d",&n);
        int biaoji[111];
        int i1=2,i2=n-2;
        
        for(i=0;i<111;i++){
            biaoji[i]=0;
        }                //数组清零 
        
        for(i=1;i<n;i++){
            printf("-");
        }                //输出顶面 
        
        printf("\n");        
        printf("\\");
        for(i=0;i<n-3;i++){
            printf(" ");
        }
        printf("/\n");    //输出第二行 
        
        for(r=n/2-2;r>0;r--){
            biaoji[i1]=1;    //这是‘\ ’ 
            biaoji[i2]=2;    //这是‘/’ 
            biaoji[i1-1]=3;    //这个是空格 

            for(i=1;i<n;i++){
                if(biaoji[i]==1){
                    printf("\\");
                }else if(biaoji[i]==2){
                    printf("/");
                    break;
                }else if(biaoji[i]==3){
                    printf(" ");
                }else{
                    printf("*");
                }
            }
            printf("\n");
            biaoji[i1]=0;
            biaoji[i2]=0;
            i1++;
            i2--;
        }                //输出漏斗上半的主体 
        

        for(i=0;i<n;i++){
            biaoji[i]=0;
        }                //再次清零 
        
        biaoji[n/2]=3;
        i1=n/2-1;
        i2=n/2+1;        //用作标记的变量初始化 
        
        for(r=n/2-1;r>0;r--){
            biaoji[i1]=2;
            biaoji[i2]=1;
            for(i=1;i<n;i++){
                if(biaoji[i]==1){
                    printf("\\");
                    break;
                }else if(biaoji[i]==2){
                    printf("/");
                }else if(biaoji[i]==3){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
            printf("\n");
            biaoji[i1]=0;
            biaoji[i2]=0;
            i1--;
            i2++;
        }                //下半的主体 
        
        for(i=1;i<n;i++){
            printf("-");
        }                //最后一行 
        
        printf("\n");
    }
return 0;
}
