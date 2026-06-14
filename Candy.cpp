#include <stdio.h>
 
const int Mod = 1e9+7;
int compute(__int64 s){                         // 组合数公式 C(n,3)
    return (s*(s-1)*(s-2)/6) % Mod;
}
 
int main()
{
    int n,N;
    __int64 x,y,z;
    __int64 ans1,ans2,ans3,ans;
    while (scanf("%d",&N) != EOF && N != 0)
    {
        x = N/3;                                // x:3的倍数的 个数
        y = z = x;
        n = N%3;
        if (n == 1)         y += 1;             // y:模3余1的数 的个数
        else if (n == 2)    y += 1, z += 1;     // z:模3余2的数 的个数
        ans1 = compute(x);
        ans2 = compute(y);
        ans3 = compute(z);
        ans = (ans1+ans2+ans3+x*y*z) % Mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
