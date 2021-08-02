#include<iostream>
using namespace std;
int main(){
	int T, H, W, N, h, w;
	cin>>T;
	while(T--){
		cin>>H>>W>>N;
		h=N%H;
		if(h==0){
			h=H;
			w=N/H;
		}
		else{
			w=N/H+1;
		}
		cout<<h;
		cout.width(2);
		cout.fill('0');
		cout<<w<<"\n";
	}
	return 0;
}
