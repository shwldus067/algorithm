#include<iostream>
#include<string>
using namespace std;
int main(){
	string first, second;
	cin>>first>>second;
	int f_len, s_len;
	f_len=first.length();
	s_len=second.length();
	int lcs[f_len+1][s_len+1];
	for(int i=0;i<=s_len;i++){
		lcs[0][i]=0;
	}
	for(int i=1;i<=f_len;i++){
		lcs[i][0]=0;
	}
	for(int i=1;i<=f_len;i++){
		for(int j=1;j<=s_len;j++){
			if(first[i-1]==second[j-1]){
				lcs[i][j]=lcs[i-1][j-1]+1;
			}
			else{
				lcs[i][j]=lcs[i-1][j]>lcs[i][j-1] ? lcs[i-1][j]:lcs[i][j-1];
			}
		}
	}
	cout<<lcs[f_len][s_len];
	return 0;
}
