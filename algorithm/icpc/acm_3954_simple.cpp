#include<iostream>
#include<stack>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	const int inf=50000000;
	char code[4100], str[4100];
	int p[4100];
	cin>>t;
	while(t--){
		int sm, sc, si, mdx=0, idx=0, cnt=0;
		cin>>sm>>sc>>si;
		cin>>code;
		cin>>str;
		stack<int> st;
		char arr[100000]={0, };
		for(int i=0;i<sc;++i){
			if(code[i]=='[')	st.push(i);
			else if(code[i]==']'){
				int tp=st.top();
				st.pop();
				p[i]=tp, p[tp]=i;
			}
		}
		bool find=false;
		stack<pair<int, int > > loop;
		loop.push({0, 0});
		for(int i=0;i<sc;++i, ++cnt){
			switch(code[i]){
				case '-':
					if(arr[mdx]==0)	arr[mdx]=255;
					else --arr[mdx];
					break;
				case '+':
					if(arr[mdx]==255)	arr[mdx]=0;
					else	++arr[mdx];
					break;
				case '<':
					if(mdx==0)	mdx=sm-1;
					else	--mdx;
					break;
				case '>':
					++mdx;
					if(mdx==sm)	mdx=0;
					break;
				case ',':
					if(idx==si)	arr[mdx]=255;
					else	arr[mdx]=str[idx++];
					break;
				case '[':
					if(!arr[mdx])	i=p[i];
					break;
				case ']':
					if(arr[mdx]){
						if(loop.top().first!=i)	loop.push({i, cnt});
						else if(cnt-loop.top().second>inf)	find=true;
						i=p[i];
					}else if(loop.top().first==i)	loop.pop();
					break;
			}
			if(find)	break;
		}
		if(find)	cout<<"Loops "<<p[loop.top().first]<<' '<<loop.top().first<<"\n";
		else	cout<<"Terminates\n";
	}
}
