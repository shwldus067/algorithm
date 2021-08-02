#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<string> str;
bool compare(string a, string b){
	if(a.length()!=b.length())	return a.length()<b.length();
	return a<b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	string tmp;
	cin>>N;
	if(N<=0)	return 0;
	for(int i=0;i<N;i++){
		cin>>tmp;
		str.push_back(tmp);
	}
	sort(str.begin(), str.end(), compare);
	cout<<str[0]<<"\n";
	for(int i=1;i<N;i++){
		tmp=str[i-1];
		if(tmp!=str[i])	cout<<str[i]<<"\n";
	}
	return 0;
}
