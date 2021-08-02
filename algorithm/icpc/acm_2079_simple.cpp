#include<stdio.h>
#include<string.h>
int dp[2010];
int min(int x, int y){
	if(x==0)	return y;
	if(y==0)	return x;
	return x<y?x:y;
}
int main(){
	char str[2010];
	str[0]=1;
	scanf("%s", str+1);
	int n=strlen(str);
	for(int i=1;i<n;++i){
		for(int j=0;j<i && i+j<n;++j){
			if(str[i-j]!=str[i+j])	break;
			dp[i+j]=min(dp[i+j], dp[i-j-1]+1);
		}
		for(int j=1;j<=i && i+j<n;++j){
			if(str[i-j+1]!=str[i+j])	break;
			dp[i+j]=min(dp[i+j], dp[i-j]+1);
		}
	}
	printf("%d\n", dp[n-1]);
	return 0;
}
