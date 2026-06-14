#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 增加一个辅助函数，用来获取点数的优先级值，方便比较
// 1点最大(设为7)，其他保持原值即可(6是6, 5是5...)，这样 1 > 6 > 5...
int get_priority(int val) {
    if (val == 1) return 7;
    return val;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a[3],b[3];
        for(int i=0;i<3;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<3;i++){
            scanf("%d",&b[i]);
        }
        
        int A1, B1; // 用于存对子的优先级
        int cnta=0, cntb=0;
        
        qsort(a,3,sizeof(int),cmp);
        qsort(b,3,sizeof(int),cmp);
        
        for(int i=1;i<3;i++){
            if(a[i-1]==a[i]) cnta++;
            if(b[i-1]==b[i]) cntb++;            
        }
        
        if(cnta > cntb){
            printf("Alice\n");
        } else if(cnta < cntb){
            printf("Bob\n");
        } else {
            // 两人牌型等级相同
            if(cnta != 0){ // 都是对子 (或者是豹子，但豹子点数不同肯定分胜负，只有点数同才进这里)
                // 你的原逻辑处理对子优先级
                if(a[1]==1) A1=6; else A1=a[1]-1;
                if(b[1]==1) B1=6; else B1=b[1]-1;
                
                if(B1 < A1) printf("Alice\n");
                else if(B1 > A1) printf("Bob\n");
                else {
                    // --- 修改开始：处理对子相同的情况，比较单牌 ---
                    
                    // 找出单牌：三个数的和 减去 两个对子数的和
                    int singleA = a[0] + a[1] + a[2] - 2 * a[1];
                    int singleB = b[0] + b[1] + b[2] - 2 * b[1];
                    
                    // 获取单牌的优先级 (1最大)
                    int pA = (singleA == 1 ? 7 : singleA);
                    int pB = (singleB == 1 ? 7 : singleB);
                    
                    if (pA > pB) printf("Alice\n");
                    else if (pA < pB) printf("Bob\n");
                    else printf("Draw\n");
                    // --- 修改结束 ---
                }
            } else { // 都是散牌(点子)
                // 题目说按“点数和”比较，这里保持你原本的逻辑
                A1 = a[0] + a[1] + a[2];
                B1 = b[0] + b[1] + b[2];
                if(A1 > B1) printf("Alice\n");
                else if(A1 < B1) printf("Bob\n");
                else printf("Draw\n");
            }
        }
    }
}
