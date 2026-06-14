#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char line[1001];
        scanf("%s",line);
        int n=strlen(line);
        if(n==1){
            printf("0\n");
            continue;
        }
        
        int man = n - 1; // 初始化最坏情况
        
        // 从后往前寻找最长的回文后缀
        for(int i = 0; i < n; i++){
            int left = i;
            int right = n - 1;//只是中间有回文串还不够，要末尾也在回文串里面 
            int tag = 1;
            
            // 检查从i到末尾是否为回文
            while(left <= right){
                if(line[left] != line[right]){
                    tag = 0;
                    break;
                }
                left++;
                right--;
            }
            
            if(tag){
                man = i; // 需要添加i个字符
                break;
            }
        }
        
        printf("%d\n",man);
    }
}
