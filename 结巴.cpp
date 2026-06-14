#include<stdio.h>
#include<string.h>
int main(){
	int t;
	int tag=0;
	int num_a,num_b,count_a,count_b;
	int cnt_a=0,cnt_b=0;
	scanf("%d",&t);
	while(t--){
		
		char a[100001],b[100001];
		scanf("%s",a);
		scanf("%s",b);
		cnt_a+=count_a;
		cnt_b+=count_b;
		count_a=0;
		count_b=0;
		int len_a=strlen(a);
		int len_b=strlen(b);
		num_a=a[cnt_a]-'a';
		num_b=b[cnt_b]-'b';
		if(num_a!=num_b){
			tag=1;
			break;
		}else{
			for(int i=cnt_a+1;i<len_a;i++){
				if((a[cnt_a]-a[i])==0)count_a++;
				else break;
			}
			for(int i=cnt_b+1;i<len_b;i++){
				if((b[cnt_b]-a[i])==0)count_b++;
				else break;
			}
			int max,min;
			if(count_a>=count_b){
				max=count_a;
				min=count_b;
			}else{
				min=count_a;
				max=count_b;
			}
			if(min*2<max){
				tag=1;
				break;
			}
		}
		if(tag){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
}
