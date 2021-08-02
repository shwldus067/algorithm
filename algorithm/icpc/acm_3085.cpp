#include<iostream>
using namespace std;
int N;
char arr[50][51];
int sol(){
	int ret=0, cnt;
	for(int i=0;i<N;++i){
		cnt=1;
		for(int j=1;j<N;++j){
			if(arr[i][j]==arr[i][j-1])	++cnt;
			else{
				if(cnt>ret)	ret=cnt;
				cnt=1;
			}
		}
		if(cnt>ret)	ret=cnt;
	}
	for(int i=0;i<N;++i){
		cnt=1;
		for(int j=1;j<N;++j){
			if(arr[j][i]==arr[j-1][i])	++cnt;
			else{
				if(cnt>ret)	ret=cnt;
				cnt=1;
			}
		}
		if(cnt>ret)	ret=cnt;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	int ans=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int r=i, c=j+1, ret;
			char tmp;
			if(c!=N && arr[i][j]!=arr[r][c]){
				tmp=arr[i][j];
				arr[i][j]=arr[r][c];
				arr[r][c]=tmp;
				ret=sol();
				if(ret>ans)	ans=ret;
				tmp=arr[i][j];
				arr[i][j]=arr[r][c];
				arr[r][c]=tmp;
			}
			r=i+1;c=j;
			if(r!=N && arr[i][j]!=arr[r][c]){
				tmp=arr[i][j];
				arr[i][j]=arr[r][c];
				arr[r][c]=tmp;
				ret=sol();
				if(ret>ans)	ans=ret;
				tmp=arr[i][j];
				arr[i][j]=arr[r][c];
				arr[r][c]=tmp;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
