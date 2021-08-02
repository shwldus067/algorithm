#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, res;
	bool check;
	string str;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>str;
		res=0;
		check=false;
		for(int i=0;i<str.length();i++){
			if(str[i]=='('){
				res+=1;
			}
			else if(str[i]==')'){
				res-=1;
			}
			if(res<0){
				res=0;
				check=true;
				cout<<"NO"<<"\n";
				break;
			}
		}
		if(check==false){
			if(res==0){
				cout<<"YES"<<"\n";
			}
			else{
				cout<<"NO"<<"\n";
			}
		}
	}
}
