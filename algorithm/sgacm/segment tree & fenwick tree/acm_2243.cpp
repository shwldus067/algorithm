#include<iostream>
#include<vector>
using namespace std;
const int MAX=1000000;
typedef vector<int> vi;
void update(vi& t, int i, int dx){
	while(i<=MAX){
		t[i]+=dx;
		i+=(i&-i);
	}
}
int sum(vi& t, int i){
	int res=0;
	while(i>0){
		res+=t[i];
		i-=(i&-i);
	}
	return res;
}
int search(vi& t, int i, int b){
	int start=1, tmp;
	int end=i, mid;
	while(end>start){
		mid=(start+end)/2;
		tmp=sum(t, mid);
		if(tmp<b){
			start=mid+1;
		}
		else{
			end=mid;
		}
	}
	return end;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, c, t, last=0;
	cin>>n;
	vi fw(MAX+1, 0);
	while(n--){
		cin>>a;
		if(a==1){
			cin>>b;
			t=search(fw, last, b);
			cout<<t<<"\n";
			update(fw, t, -1);
		}
		else{
			cin>>b>>c;
			last=max(last, b);
			update(fw, b, c);
		}
	}
	return 0;
}
