#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, t, cur=1;
	stack<int> S;
	vector<char> task;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		for(;cur<=t;cur++){
			S.push(cur);
			task.push_back('+');
		}
		if(!S.empty() && S.top()==t){
			S.pop();
			task.push_back('-');
		}
		else{
			cout<<"NO\n";
			return 0;
		}
	}
	for(int i=0;i<task.size();i++)
		cout<<task[i]<<"\n";
	return 0;
}
