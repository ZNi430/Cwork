#include<stdio.h>
#include <stdlib.h>
#include<string.h> 
//如果名字长度是一样的，我的代码就是对的 
int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		char s[20][17]={0};
		int len;
		for(int i=0;i<20;i++){
			scanf("%s",s[i]);
			if(strcmp(s[i], "END") == 0){
				len=i+1;
				break;
			}
		}
		if(len==1){
			printf("%s\n",s[0]);
			continue;
		}
		char a[20][20][17]={0};
		int index[20]={0};
		int max=-1;
		for(int i=0;i<len;i++){
			int count=0;
			for(int j=i+1;j<len;j++){
				if(strcmp(s[i],s[j])==0){
					count++;
				}
			}
			max=max<count?count:max;
			strcpy(a[count][index[count]],s[i]);
			index[count]++;
		} 
		qsort(a[max], index[max], sizeof(a[max][0]), compare);
		
		
		
		if(strcmp(a[max][0],"START")==0){
			
			if(strcmp(a[max][1],"END")==0){
			printf("%s",a[max][2]);
			continue;
			} 
			printf("%s",a[max][1]);
			continue;
		} 
		if(strcmp(a[max][0],"END")==0){
			if(strcmp(a[max][1],"START")==0){
			printf("%s",a[max][2]);
			continue;
			} 
			printf("%s",a[max][1]);
			continue;
		} 
		printf("%s\n",a[max][0]);
		
		
		
		
	}
} 
