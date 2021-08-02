#include<iostream>
#include<string>
using namespace std;
int N, p[27];
string str;
int condition(char val1, char val2){	//결과가 참일 때 경우 수 
	if(val1>='a' && val1<='z'){
		if(val2>='a' && val2<='z')	return 2;
		else	return 1;
	}
	else if(val2>='a' && val2<='z')	return 1;
	else if(val1==val2)	return 1;
	return 0;
}
int expression(string exp){
	int i=0, size=exp.size();
	char val1, val2;
	val1=exp[i++];
	if(i>=size){
		if(val1=='0')	return 1;
		else if(val1>='a' && val1<='z')	return 1;
		else	return 0;
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>str;
	p[0]=1;
	for(int i=1;i<=N;++i)	p[i]=p[i-1]*2;
	int i=0, size=str.length();
	val1=str[i++];
	if(i<size){
		if(str[i]=='?'){
			
		}
		else if(str[i]=='='){
			
		}
	}
	else{
		if(val1=='0')	cout<<p[N]<<"\n";
		else if(val1>='a' && val1<='z')	cout<<"1\n";
		else	cout<<0<<"\n";
	}
	
}
