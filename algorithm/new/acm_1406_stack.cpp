#include<iostream>
#include<stack>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char ch;
	int N;
	stack<char> left, right;
	while((ch=cin.get())!='\n'){
		left.push(ch);
	}
	cin>>N;
	while(N--){
		char cmd, tmp;
		cin>>cmd;
		switch(cmd){
			case 'L':
				if(!left.empty()){
					tmp=left.top();
					left.pop();
					right.push(tmp);
				}
				break;
			case 'D':
				if(!right.empty()){
					tmp=right.top();
					right.pop();
					left.push(tmp);
				}
				break;
			case 'B':
				if(!left.empty())	left.pop();
				break;
			case 'P':
				cin>>tmp;
				left.push(tmp);
				break;
		}
	}
	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	while(!right.empty()){
		cout<<right.top();
		right.pop();
	}
	cout<<"\n";
	return 0;
}
