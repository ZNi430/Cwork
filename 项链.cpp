#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x, index = 1;
        scanf("%d", &x);
        
        // 使用int数组而不是char数组
        int *a = (int*)malloc(x * sizeof(int));
        int *b = (int*)malloc(x * sizeof(int));
        int *c = (int*)malloc(x * sizeof(int));
        
        // 正确读取整数输入
        for(int i = 0; i < x; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < x; i++){
            scanf("%d", &b[i]);
        }
        
        for(int i = 0; i < x; i++){
            // 创建旋转后的序列
            for(int j = 0; j < x; j++){
                c[j] = a[(j + i) % x];
            }
            
            // 比较旋转后的序列
            int match = 1;
            for(int k = 0; k < x; k++){
                if(c[k] != b[k]){
                    match = 0;
                    break;
                }
            }
            if(match){
                printf("Yes\n");
                index = 0;
                break;
            }
            
            // 创建翻转后的序列并比较
            match = 1;
            for(int k = 0; k < x; k++){
                if(c[x - 1 - k] != b[k]){
                    match = 0;
                    break;
                }
            }
            if(match){
                printf("Yes\n");
                index = 0;
                break;
            }
        }
        
        if(index) printf("No\n");
        
        free(a);
        free(b);
        free(c);
    }
    return 0;
}
