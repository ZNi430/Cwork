#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c,t;
	scanf("%lf %lf %lf",&a,&b,&c);
	t=b*b-4*a*c;
	if(t<-0.000001){
		printf("No answer!\n");
	}else if(t<0.000001){
		printf("x1=x2=%f.5\n",-b/(2*a));
	}else{
		double d=sqrt(t);
		printf("x1=%.5f;x2=%.5f\n",(-b+d)/(2*a),-(b+d)/(2*a));
	}
}
