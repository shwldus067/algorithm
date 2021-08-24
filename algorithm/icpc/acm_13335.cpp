#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, w, L, a[1000];
	cin>>n>>w>>L;
	for(int i=0;i<n;++i)	cin>>a[i];
	int sum=a[0], time[1000]={0, }, l=0;
	time[0]=1;
	for(int i=1;i<n;++i){
		if(i-l==w){
			sum-=a[l];
			l++;
		}
		while(sum+a[i]>L){
			sum-=a[l];
			l++;
		}
		sum+=a[i];
		if(l==0)	time[i]=time[i-1]+1;
		else	time[i]=max(time[i-1]+1, time[l-1]+w);
	}
	cout<<time[n-1]+w<<"\n";
	return 0;
}
