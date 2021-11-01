#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, d=0, r=50, c=50, mr=50, mc=50, Mr=-1, Mc=-1;
	int dr[4]={1, 0, -1, 0}, dc[4]={0, -1, 0, 1};
	char str[51];
	bool arr[101][101]={0, };
	arr[r][c]=1;
	cin>>N>>str;
	for(int i=0;i<N;++i){
		if(str[i]=='R'){
			d=d==3?0:d+1;
		}else if(str[i]=='L'){
			d=d?d-1:3;
		}else{
			r+=dr[d];c+=dc[d];
		}
		mr=min(mr, r);mc=min(mc, c);
		Mr=max(Mr, r);Mc=max(Mc, c);
		arr[r][c]=1;
	}
	if(Mr!=-1){
		for(int i=mr;i<=Mr;++i){
			for(int j=mc;j<=Mc;++j){
				if(arr[i][j])	cout<<'.';
				else	cout<<'#';
			}
			cout<<"\n";
		}
	}
	return 0;
}
