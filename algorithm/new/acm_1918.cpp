#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> S;
int main(){
	string str, result;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='A' && str[i]<='Z'){
			result+=str[i];
		}
		else{
			switch(str[i]){
				case '(':
					S.push(str[i]);
					break;
				case '*':
				case '/':
					while(!S.empty() && (S.top()=='*' || S.top()=='/')){
						result+=S.top();
						S.pop();
					}
					S.push(str[i]);
					break;
				case '+':
				case '-':
					while(!S.empty() && S.top()!='('){
						result+=S.top();
						S.pop();
					}
					S.push(str[i]);
					break;
				case ')':
					while(!S.empty() && S.top()!='('){
						result+=S.top();
						S.pop();
					}
					S.pop();
					break;
			}
		}
	}
	while(!S.empty()){
		result+=S.top();
		S.pop();
	}
	cout<<result<<"\n";
	return 0;
}
