

int main(){
	char str[][N]={"hello world",};
	char *p[4];
	int n=sizeof (str)/sizeof(str[0]);
	for(int 	i=0;i<n;i++)p[i]=str[i];
	out_str(n,str);
	out_ptr(n,p);
	qsort(p,n,sizeof(p[0]),cmp);
	out_str(n,str);
	out_ptr(n,p);
}
