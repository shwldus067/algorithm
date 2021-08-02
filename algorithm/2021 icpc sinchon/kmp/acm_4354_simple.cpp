#include<cstdio>
int n, f[1000001];
int main(){
	char str[1000001];
	while(1){
		scanf("%s", str);
		if(str[0]=='.')	break;
		int i, j;
		for(i=1, j=0;str[i];++i){
			while(j && str[i]!=str[j])	j=f[j-1];
			if(str[i]==str[j])	f[i]=++j;
			else	f[i]=0;
		}
		printf("%d\n", (i%(i-f[i-1])?1:i/(i-f[i-1])));
	}
	return 0;
}
