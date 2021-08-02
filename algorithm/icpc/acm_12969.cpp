#include<iostream>
using namespace std;
int N, K;
bool ch[31][31][31][450];
char s[31];
bool fun(int i, int cur, int a, int b){
	if(cur>K)	return false;
	if(cur==K){
		for(int a=i;a<N;a++){
			s[a]='A';
		}
		return true;
	}
	if(i==N)	return false;
	if(ch[i][a][b][cur])	return false;
	ch[i][a][b][cur]=true;
	s[i]='A';
	if(fun(i+1, cur, a+1, b))	return true;
	s[i]='B';
	if(fun(i+1, cur+a, a, b+1))	return true;
	s[i]='C';
	if(fun(i+1, cur+a+b, a, b))	return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>K;
	if(fun(0, 0, 0, 0)){
		cout<<s<<"\n";
	}
	else{
		cout<<-1<<"\n";
	}
	return 0;
}
