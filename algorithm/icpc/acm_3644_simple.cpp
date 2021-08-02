#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
string c[10001];
void add(string& res, string a, string b){
	b=b+'0';
	res=a;
	int t=0;
	for(int i=0;i<a.size();i++){
		t+=a[i]-'0'+b[i]-'0';
		res[i]=(t%10)+'0';
		t/=10;
	}
	if(t){
		char x=t+'0';
		res=res+x;
	}
}
int main(){
	c[3]="4";
	c[4]="7";
	for(int i=5;i<=10000;i++){
		add(c[i], c[i-1], c[i-2]);
	}
	while(cin>>n){
		reverse(c[n].begin(), c[n].end());
		cout<<c[n]<<"\n";
		reverse(c[n].begin(), c[n].end());
	}
	return 0;
}
