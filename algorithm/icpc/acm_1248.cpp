#include<iostream>
using namespace std;
int N, ret[10];
char S[10][10];
bool check(int i){
	int t=ret[i];
	for(int k=i-1;k>=0;k--){
		t+=ret[k];
		if(t<0){
			if(S[k][i]!='-')	return false;
		}
		else if(t>0){
			if(S[k][i]!='+')	return false;
		}
		else{
			if(S[k][i]!='0')	return false;
		}
	}
	return true;
}
bool func(int i){
	if(i==N)	return true;
	if(S[i][i]=='+'){
		for(int p=1;p<=10;p++){
			ret[i]=p;
			if(check(i)){
				if(func(i+1))	return true;
			}
		}
	}
	else if(S[i][i]=='-'){
		for(int p=-1;p>=-10;p--){
			ret[i]=p;
			if(check(i)){
				if(func(i+1))	return true;
			}
		}
	}
	else{
		ret[i]=0;
		if(check(i)){
			if(func(i+1))	return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			cin>>S[i][j];
		}
	}
	func(0);
	for(int i=0;i<N;i++)	cout<<ret[i]<<" ";
	cout<<"\n";
	return 0;
}
