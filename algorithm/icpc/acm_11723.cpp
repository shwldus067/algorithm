#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int M, k;
	char str[20];
	bool chk[21]={0, };
	cin>>M;
	while(M--){
		cin>>str;
		if(str[2]=='d'){
			cin>>k;
			chk[k]=1;
		}else if(str[2]=='m'){
			cin>>k;
			chk[k]=0;
		}else if(str[2]=='e'){
			cin>>k;
			if(chk[k])	cout<<"1\n";
			else	cout<<"0\n";
		}else if(str[2]=='g'){
			cin>>k;
			chk[k]^=1;
		}else if(str[2]=='l'){
			for(int i=1;i<21;++i)	chk[i]=1;
		}else if(str[2]=='p'){
			for(int i=1;i<21;++i)	chk[i]=0;
		}
	}
	return 0;
}
