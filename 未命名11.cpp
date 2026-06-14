#include<stdio.h>

int gcd(int a, int b);
long long X[100], Y[100];

int main()
{
	int o;
	scanf("%d", &o);
	while (o--)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int cnt = 0;
		
		if (a == 1 && c == 1)
		{
			long long lcm = (long long)b * d / gcd(b, d);
			if (lcm > 0) 
			{
				cnt = 1000000000 / lcm;
			}
		}
		else if (a == 1 || c == 1)
		{
			if (c == 1)
			{
				int t = a, T = b;
				a = 1; c = t; b = d; d = T;
			}
			long long y = d;
			while (y <= 1000000000)
			{
				if (y % b == 0) cnt++;
				y = y * c + d;
			}
		}
		else if (a != 1 && c != 1)
		{
			long long x = b, y = d;
			int q1 = 1, q2 = 1;
            
			while (x <= 1000000000)
			{
				X[q1] = x;
				x = x * a + b;
				q1++;
			}
			while (y <= 1000000000)
			{
				Y[q2] = y;
				y = y * c + d;
				q2++;
			}
			
			for (int i = 1; i < q1; i++)
			{
				for (int j = 1; j < q2; j++)
				{
					if (X[i] == Y[j]) cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
