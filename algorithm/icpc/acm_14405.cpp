#include<iostream>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char str[50001];
	cin>>str;
	for(int i=0;str[i];++i){
		if(str[i]=='p'){
			if(str[i+1]!='i'){
				cout<<"NO\n";
				return 0;
			}
			i++;
		}else if(str[i]=='k'){
			if(str[i+1]!='a'){
				cout<<"NO\n";
				return 0;
			}
			i++;
		}else if(str[i]=='c'){
			if(str[i+1]!='h' || str[i+2]!='u'){
				cout<<"NO\n";
				return 0;
			}
			i+=2;
		}else{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}
