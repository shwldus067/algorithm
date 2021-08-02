#include<iostream>
#include<stack>
using namespace std;
const int inf=50000000;
char code[4100], str[4100];
int p[4100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int sm, sc, si, mdx=0, idx=0, cnt=0;
		cin>>sm>>sc>>si;
		cin>>code;
		cin>>str;
		stack<int> st;
		for(int i=0;i<sc;++i){
			if(code[i]=='[')	st.push(i);
			else if(code[i]==']'){
				int tp=st.top();
				st.pop();
				p[i]=tp, p[tp]=i;
			}
		}
		char arr[100000]={0, };
		bool fin=false;
		int cdx=sc;
		for(int i=0;i<sc;++i){
			if(code[i]=='+'){
				if(arr[mdx]==255)	arr[mdx]=0;
				else	++arr[mdx];
			}
			else if(code[i]=='-'){
				if(arr[mdx]==0)	arr[mdx]=255;
				else	--arr[mdx];
			}
			else if(code[i]=='<'){
				if(mdx==0)	mdx=sm-1;
				else	--mdx;
			}
			else if(code[i]=='>'){
				++mdx;
				if(mdx==sm)	mdx=0;
			}
			else if(code[i]=='['){
				if(cnt>=inf*2){
					fin=true;
					break;
				}
				else if(cnt>=inf)
					cdx=min(cdx, i);
				if(arr[mdx]==0){
					i=p[i];
				}
			}
			else if(code[i]==']'){
				if(arr[mdx]){
					i=p[i]-1;
					--cnt;
				}
			}
			else if(code[i]==','){
				if(idx==si)	arr[mdx]=255;
				else	arr[mdx]=str[idx++];
			}
			cnt++;
		}
		if(fin)	cout<<"Loops "<<cdx<<" "<<p[cdx]<<"\n";
		else	cout<<"Terminates\n";
	}
	return 0;
}
