#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num[]={1, 2, 3, 4, 5, 6, 7, 8, 9}, ans=1e6;
	int cnt[9][9]={0, };
	char str[100001];
	cin>>str;
	int N=strlen(str);
	for(int i=1;i<N;++i)	cnt[str[i-1]-'1'][str[i]-'1']++;
	int start=str[0]-'1';
	do{
		int sum=0, first=-1;
		for(int i=0;i<9;++i){
			for(int j=0;j<9;++j){
				if(cnt[i][j]==0)	continue;
				if(num[i]<num[j])	sum+=(num[j]-num[i])*cnt[i][j];
				else	sum+=(num[i]-num[j])*cnt[i][j];
			}
			if(num[i]==1)	first=i;
		}
		sum+=(num[start]-num[first]);
		if(ans>sum)	ans=sum;
	}while(next_permutation(num, num+9));
	cout<<ans+N<<"\n";
	return 0;
}
