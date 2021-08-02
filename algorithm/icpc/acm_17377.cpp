#include<iostream>
#include<string>
#include<map>
using namespace std;
int A, B, C, N, K;
string str, name;
map<string, int> node;
int arr[100][3], cur, p, money, start;
long long fuel[2], full;
int passenger[3][2]={{-1, 0}, {-1, 0}, {-1, 0}};
long long lcm(long long f, long long s){
	long long a=f, b=s, res=0;
	while(1){
		res=a%b;
		if(res==0)	break;
		a=b;
		b=res;
	}
	return f*s/b;
}
bool sol(int next){
	int distance=abs(arr[cur][0]-arr[next][0])+abs(arr[cur][1]-arr[next][1]);
	long long l=lcm(fuel[1], (long long)C);
	fuel[0]=fuel[0]*(l/fuel[1])-(long long)distance*(l/C);
	fuel[1]=l;
	if(fuel[0]<0){
		cout<<"OUT OF GAS\n";
		return true;
	}
	for(int i=0;i<3;++i){
		if(passenger[i][0]!=-1){
			passenger[i][1]+=distance;
			if(passenger[i][0]==next){
				money+=passenger[i][1]*B;
				passenger[i][0]=-1;
				passenger[i][1]=0;
				p--;
			}
		}
	}
	int pay;
	if(arr[next][2]!=0 && money>0){
		pay=(full*fuel[1]-fuel[0])*1ll*arr[next][2]/fuel[1];
		if(pay<=money){
			money-=pay;
			fuel[0]=full;
			fuel[1]=1;
		}
		else{
			long long cost=(long long)arr[next][2];
			l=lcm(fuel[1], cost);
			fuel[0]=fuel[0]*(l/fuel[1])+(long long)money*(l/cost);
			fuel[1]=l;
			money=0;
		}
	}
	cur=next;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B>>C>>N;
	fuel[0]=A, fuel[1]=1;
	full=A;
	for(int i=0;i<N;++i){
		cin>>str;
		name.clear();
		while(str[0]<'0' || str[0]>'9'){
			name+=str;
			name+=" ";
			cin>>str;
		}
		node.insert(make_pair(name, i));
		arr[i][0]=stoi(str);
		cin>>str;
		arr[i][1]=stoi(str);
	}
	for(int i=0;i<3;++i){
		cin>>str;
		name.clear();
		while(str[0]<'0' || str[0]>'9'){
			name+=str;
			name+=" ";
			cin>>str;
		}
		arr[node.find(name)->second][2]=stoi(str);
	}
	cin>>K;
	start=cur=node.find("Taxi Garage ")->second;
	for(int i=0;i<K;++i){
		cin>>str;
		if(str[0]=='G'){
			cin>>str>>str;
			name.clear();
			while(str.back()!='.'){
				name+=str;
				name+=" ";
				cin>>str;
			}
			str.pop_back();
			name+=str;
			name+=" ";
			if(sol(node.find(name)->second))
				return 0;
		}
		else{
			cin>>str>>str>>str>>str>>str;
			name.clear();
			while(str.back()!='.'){
				name+=str;
				name+=" ";
				cin>>str;
			}
			str.pop_back();
			name+=str;
			name+=" ";
			if(p==3){
				cout<<"CAPACITY FULL\n";
				return 0;
			}
			p++;
			int goal=node.find(name)->second;
			for(int i=0;i<3;++i){
				if(passenger[i][0]==-1){
					passenger[i][0]=goal;
					break;
				}
			}
		}
	}
	if(cur==start){
		if(p>0){
			cout<<"REMAINING PASSENGER\n";
		}
		else{
			cout<<money<<"\n";
		}
	}
	else{
		cout<<"NOT IN GARAGE\n";
	}
	return 0;
}
