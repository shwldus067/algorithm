#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char arr[10][11];
	for(int i=0;i<10;++i)	cin>>arr[i];
	for(int i=0;i<10;++i)for(int j=0;j<10;++j){
		if(arr[i][j]!='.')	continue;
		arr[i][j]='X';
		int r=0, c=0, rc1=0, rc2=0;
		for(int k=i-1;k>=0 && arr[k][j]=='X';--k)	++c;
		for(int k=i+1;k<10 && arr[k][j]=='X';++k)	++c;
		for(int k=j-1;k>=0 && arr[i][k]=='X';--k)	++r;
		for(int k=j+1;k<10 && arr[i][k]=='X';++k)	++r;
		for(int k=i-1, l=j-1;k>=0 && l>=0 && arr[k][l]=='X';--k, --l)	rc1++;
		for(int k=i+1, l=j+1;k<10 && l<10 && arr[k][l]=='X';++k, ++l)	rc1++;
		for(int k=i-1, l=j+1;k>=0 && l<10 && arr[k][l]=='X';--k, ++l)	rc2++;
		for(int k=i+1, l=j-1;k<10 && l>=0 && arr[k][l]=='X';++k, --l)	rc2++;
		if(r>3 || c>3 || rc1>3 || rc2>3){
			cout<<"1\n";
			return 0;
		}
		arr[i][j]='.';
	}
	cout<<"0\n";
	return 0;
}
