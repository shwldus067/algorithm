#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int front=0, back;
		bool rev=false, fin=false;
		char c;
		string str;
		cin>>str>>back;
		int ary[back];
		for(int i=0;i<back;i++){
			cin>>c;
			cin>>ary[i];
		}
		cin>>c;
		if(back==0){
			cin>>c;
		}
		back--;
		for(int i=0;i<str.length();i++){
			if(str[i]=='R'){
				rev=!rev;
			}
			else{
				if(back-front<0){
					cout<<"error"<<"\n";
					fin=true;
					break;
				}
				if(rev==false){
					front++;
				}
				else{
					back--;
				}
			}
		}
		if(fin==false){
			if(back-front<0)	cout<<"[]\n";
			else if(rev==false){
				cout<<"["<<ary[front];
				for(int i=front+1;i<=back;i++){
					cout<<","<<ary[i];
				}
				cout<<"]\n";
			}
			else{
				cout<<"["<<ary[back];
				for(int i=back-1;i>=front;i--){
					cout<<","<<ary[i];
				}
				cout<<"]\n";
			}
		}
	}
	return 0;
}
