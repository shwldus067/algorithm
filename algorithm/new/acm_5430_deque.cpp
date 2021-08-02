#include<iostream>
#include<deque>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int n, tmp;
		bool rev=false, fin=false;
		char c;
		string str;
		deque<int> D;
		cin>>str>>n;
		for(int i=0;i<n;i++){
			cin>>c>>tmp;
			D.push_back(tmp);
		}
		cin>>c;
		if(n==0){
			cin>>c;
		}
		for(int i=0;i<str.length();i++){
			if(str[i]=='R')	rev=!rev;
			else{
				if(D.empty()){
					cout<<"error"<<"\n";
					fin=true;
					break;
				}
				if(rev)	D.pop_back();
				else	D.pop_front();
			}
		}
		if(!fin){
			if(D.empty())	cout<<"[]\n";
			else if(!rev){
				cout<<"["<<D.front();
				D.pop_front();
				while(!D.empty()){
					cout<<","<<D.front();
					D.pop_front();
				}
				cout<<"]\n";
			}
			else{
				cout<<"["<<D.back();
				D.pop_back();
				while(!D.empty()){
					cout<<","<<D.back();
					D.pop_back();
				}
				cout<<"]\n";
			}
		}
	}
	return 0;
}
