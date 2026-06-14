#include<stdio.h>
#include<stdlib.h>

// 辅助函数：求最小值
long long minl(long long a, long long b){ // 权值和可能超过int范围，建议用long long，虽然这题int可能够
	return (a < b) ? a : b;
}

int main(){
	int t;
	if(scanf("%d",&t) != 1) return 0; // 良好的读取习惯
	while(t--){
		int n;
		scanf("%d",&n);
		
		// 申请内存
		int *a = (int *)malloc(n * sizeof(int));
		long long *p = (long long *)malloc(n * sizeof(long long)); // 前缀和建议用 long long 防溢出
		
		long long sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			sum += a[i];
			
			// 正确计算前缀和：p[i] 表示从第0条边加到第i条边的和
			if(i == 0) p[i] = a[i];
			else p[i] = p[i-1] + a[i];
		}

		long long min_ans = -1; // 初始化为一个标记值，或者很大的数

		// 枚举断开第 i 条边 (i 从 0 到 n-1)
		// 断开 a[i] 后：
		// 顺时针距离 D_cw = a[0] + ... + a[i-1] (即 p[i-1])
		// 逆时针距离 D_ccw = 总长度 - D_cw - a[i] (因为 a[i] 被断开了)
		
		for(int i = 0; i < n; i++){
			long long d_cw;
			if(i == 0) d_cw = 0; // 如果断开第0条边，顺时针还没走就断了，距离为0
			else d_cw = p[i-1];

			long long d_ccw = sum - d_cw - a[i]; // 剩下的就是另一边的长度

			// 代价 = 两边之和 + 短的那边 (短边要折返)
			// 即：d_cw + d_ccw + min(d_cw, d_ccw)
			long long current_cost = d_cw + d_ccw + minl(d_cw, d_ccw);
            
            // 更新最小值
			if(min_ans == -1 || current_cost < min_ans){
				min_ans = current_cost;
			}
		}
		
		printf("%lld\n", min_ans);

		// 别忘了释放内存，否则多组数据会内存泄漏
		free(a);
		free(p);
	}
	return 0;
}
