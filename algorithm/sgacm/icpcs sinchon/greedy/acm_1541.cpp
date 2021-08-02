#include<iostream>
#include<cstring>
using namespace std;
char str[60];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	int ans=0, tmp, i=0, size=strlen(str);
	bool minus=false;
	while(i<size){
		if(str[i]>='0' && str[i]<='9'){
			tmp=0;
			for(;str[i]>='0' && str[i]<='9';++i)
				tmp=tmp*10+(str[i]-'0');
			if(minus)	ans-=tmp;
			else	ans+=tmp;
		}
		else if(str[i++]=='-')	minus=true;
	}
	cout<<ans<<"\n";
	return 0;
}
