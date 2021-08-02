#include<iostream>
using namespace std;
int N, dp[10000][10];
char cur[10000], des[10000];
int sol(int s, int n){
	if(s==N)	return 0;
	int &ret=dp[s][n];
	if(ret!=-1)	return ret;
	int t=((int)cur[s]+n)%10;
	ret=~(1<<31);
	for(int i=0;i<10;i++){
		if((t+i)%10==(int)des[s]){
			ret=min(ret, sol(s+1, (n+i)%10)+i);
			ret=min(ret, sol(s+1, n)+10-i);
			break;
		}
	}
	return ret;
}
void print(int s, int n){
	if(s==N)	return;
	int t=((int)cur[s]+n)%10;
	for(int i=0;i<10;i++){
		if((t+i)%10==(int)des[s]){
			int l=sol(s+1, (n+i)%10)+i;
			int r=sol(s+1, n)+10-i;
			if(l<=r){
				cout<<s+1<<" "<<i<<"\n";
				print(s+1, (n+i)%10);
			}
			else{
				cout<<s+1<<" "<<i-10<<"\n";
				print(s+1, n);
			}
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>cur[i];
		cur[i]-='0';
	}
	for(int i=0;i<N;i++){
		cin>>des[i];
		des[i]-='0';
	}
	fill(&dp[0][0], &dp[9999][10], -1);
	cout<<sol(0, 0)<<"\n";
	print(0, 0);
	return 0;
}
