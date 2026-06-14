#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 1000000  
int primes[MAX_N];
int hhh[10000];
bool visited[MAX_N];
int cnt = 0; 
int h=0;

void euler_sieve(int n) {
    memset(visited, false, sizeof(visited));
    
    visited[0] = visited[1] = true;

    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            primes[cnt++] = i;
        }

        for (int j = 0; j < cnt; j++) {
            if (i * primes[j] > n) break;
            visited[i * primes[j]] = true;

            if (i % primes[j] == 0) {
                break; 
            }
        }
    }
}

int main() {
    int n;
	scanf("%d",&n);
    euler_sieve(10000099);
    for(int i=0;primes[i]+primes[i+1]<2000000;i++){
    	if((primes[i]+primes[i+1])%2==0){		
	    	int t=(primes[i]+primes[i+1])/2;
	    	int tag=0;
			for(int j=0;primes[j]>=t;j++){
				if(t==primes[j]){
					tag=1;
					break;
				}
			}
			if(tag==0){
				hhh[h++]=t;
				
			}
		}
	}
	for(int i=0;i<h;i++){
		printf("%d\n",hhh[i]);
	}
    return 0;
}
