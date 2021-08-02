#include<iostream>
using namespace std;
int arr[3][3];
bool check(int t){
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(arr[i][j]!=t)	break;
			if(j==2)	return true;
		}
	}
	for(int j=0;j<3;++j){
		for(int i=0;i<3;++i){
			if(arr[i][j]!=t)	break;
			if(i==2)	return true;
		}
	}
	for(int i=0;i<3;++i){
		if(arr[i][i]!=t)	break;
		if(i==2)	return true;
	}
	for(int i=0;i<3;++i){
		if(arr[i][2-i]!=t)	break;
		if(i==2)	return true;
	}
	return false;
}
int sol(int t){
	if(check(3-t))	return -1;
	int ret=2;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(arr[i][j]==0){
				arr[i][j]=t;
				ret=min(ret, sol(3-t));
				arr[i][j]=0;
			}
		}
	}
	if(ret==2 || ret==0)	return 0;
	return -ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tmp, cnt=0;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			cin>>tmp;
			if(tmp!=0)	cnt++;
			arr[i][j]=tmp;
		}
	}
	int turn=1;
	if(cnt%2)	turn=2;
	int ans=sol(turn);
	if(ans==-1){
		cout<<"L\n";
	}
	else if(ans==0){
		cout<<"D\n";
	}
	else{
		cout<<"W\n";
	}
	return 0;
}
