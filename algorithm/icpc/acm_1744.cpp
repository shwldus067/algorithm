#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int N, sum=0, i, j;
	scanf("%d", &N);
	int arr[N];
	for(i=0;i<N;i++)	scanf("%d", &arr[i]);
	sort(arr, arr+N);
	for(i=N-1, j=0;j<=i;){
		if(i==j){
			sum+=arr[i];
			break;
		}
		if(arr[i]>0){
			if(arr[i]+arr[i-1]<arr[i]*arr[i-1]){
				sum+=arr[i]*arr[i-1];
				i--;
			}
			else{
				sum+=arr[i];
			}
			i--;
		}
		else{
			if(arr[j]+arr[j+1]<arr[j]*arr[j+1]){
				sum+=arr[j]*arr[j+1];
				j++;
			}
			else{
				sum+=arr[j];
			}
			j++;
		}
	}
	printf("%d\n", sum);
	return 0;
}
