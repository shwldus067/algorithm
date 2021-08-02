#include<stdio.h>
int main(){
    int n;
    int b[210] = {0,};
    int ans = 0;
    int a[210];
    scanf("%d",&n);
    for(int i = 1 ; i <= n; i++)
    {
        scanf("%d",&a[i]);
		b[i] = 1;
		for (int j = 1; j < i; j++)
		    if (a[j] < a[i] && b[i] < b[j]+1)
				b[i]=b[j]+1;
		if (ans < b[i]) 
            ans = b[i];
    }
    printf("%d",n-ans);
}
