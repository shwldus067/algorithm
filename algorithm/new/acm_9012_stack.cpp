#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	bool check;
	string str;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>str;
		stack<char> S;
		check=false;
		for(int i=0;i<str.length();i++){
			if(str[i]=='('){
				S.push('(');
			}
			else if(str[i]==')'){
				if(S.size()!=0 && S.top()=='('){
					S.pop();
				}
				else{
					cout<<"NO\n";
					check=true;
					break;
				}
			}
		}
		if(check==false){
			if(S.size()==0){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
	}
}
