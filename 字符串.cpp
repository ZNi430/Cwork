#include<stdio.h>
#include<string.h>

int main(){
    char s[1001];
    while(scanf("%s",s)!=EOF){
        int len = strlen(s);
        int count[26] = {0};  // 每个字符的当前出现次数
        
        // 预处理：记录每个字符第k次出现的位置
        int first_occurrence[26][1001] = {0}; // first_occurrence[c][k] 表示字符c第k次出现的位置
        
        for(int i=0;i<26;i++){
            for(int j=0;j<=len;j++){
                first_occurrence[i][j] = -1;
            }
        }
        
        // 第一次遍历：预处理每个字符的第k次出现位置
        int temp_count[26] = {0};
        for(int i=0;i<len;i++){
            int c = s[i]-'a';
            temp_count[c]++;
            first_occurrence[c][temp_count[c]] = i;
        }
        
        // 第二次遍历：逐个位置计算答案
        int current_count[26] = {0};
        for(int i=0;i<len;i++){
            int c = s[i]-'a';
            current_count[c]++;
            
            // 找出当前出现次数最多的字符
            int max_count = 0;
            for(int j=0;j<26;j++){
                if(current_count[j] > max_count){
                    max_count = current_count[j];
                }
            }
            
            // 在所有达到max_count的字符中，找最早达到该次数的
            int earliest_pos = len;
            char result;
            for(int j=0;j<26;j++){
                if(current_count[j] == max_count){
                    // 字符j首次达到max_count次的位置
                    int pos = first_occurrence[j][max_count];
                    if(pos < earliest_pos){
                        earliest_pos = pos;
                        result = 'a' + j;
                    }
                }
            }
            
            printf("%c",result);
        }
        printf("\n");
    }
    return 0;
}
