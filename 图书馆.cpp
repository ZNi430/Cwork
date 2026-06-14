#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

long long calculate_total_sum(int *pos, int *l_array, int n)
{
    long long total_sum = 0;
    l_array[0] = pos[0];
    total_sum += (l_array[0] + 1);
    for (int m = 1; m < n; m++)
    {
        l_array[m] = MIN(l_array[m - 1], pos[m]);
        total_sum += (l_array[m] + 1);
    }
    return total_sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        int *p = (int *)calloc(n, sizeof(int));
        int *pos = (int *)calloc(n, sizeof(int));
        int *l_array = (int *)calloc(n, sizeof(int));

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &p[i]);
            pos[p[i]] = i;
        }

        long long total_sum = calculate_total_sum(pos, l_array, n);
        printf("%lld\n", total_sum);

        for (int k_i = 0; k_i < k; k_i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);

            int v_a = p[a];
            int v_b = p[b];
            
            int v_min = MIN(v_a, v_b);

            for (int m = v_min; m < n; m++)
            {
                total_sum -= (l_array[m] + 1);
            }

            p[a] = v_b;
            p[b] = v_a;
            pos[v_a] = b;
            pos[v_b] = a;

            l_array[v_min] = (v_min == 0) ? pos[0] : MIN(l_array[v_min - 1], pos[v_min]);
            total_sum += (l_array[v_min] + 1);

            for (int m = v_min + 1; m < n; m++)
            {
                l_array[m] = MIN(l_array[m - 1], pos[m]);
                total_sum += (l_array[m] + 1);
            }
            
            printf("%lld\n", total_sum);
        }

        free(p);
        free(pos);
        free(l_array);
    }
    return 0;
}
