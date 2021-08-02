#include<cstdio>
int main(){
	char arr[1001];
	int ans=0;
	scanf("%*d %s", arr);
	for(int i=0;arr[i];++i)if(arr[i]=='E' && arr[i+1]=='W')	++ans;
	printf("%d\n", ans);
	return 0;
}
