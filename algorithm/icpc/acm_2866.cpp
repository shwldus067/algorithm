#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int R, C, cnt=-1;
	char inp[1000][1001];
	cin>>R>>C;
	string str[1000];
	for(int i=0;i<R;++i)for(int j=0;j<C;++j){
		cin>>inp[j][R-i-1];
	}
	for(int i=0;i<C;++i){
		inp[i][R]=0;
		str[i]=string(inp[i]);
	}
	sort(str, str+C);
	for(int i=1;i<C;++i){
		for(int j=0;j<R;++j){
			if(str[i][j]!=str[i-1][j]){
				cnt=max(cnt, j);
				break;
			}
		}
	}
	cout<<R-cnt-1<<"\n";
	return 0;
}
