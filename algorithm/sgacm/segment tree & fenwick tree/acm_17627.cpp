#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
void update(vi& t, int i, int dx){
	while(i<t.size()){
		t[i]^=dx;
		i+=(i&-i);
	}
}
int query(vi& t, int i){
	int sum=0;
	while(i>0){
		sum^=t[i];
		i-=(i&-i);
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q, a, b, c, res;
	cin>>n>>q;
	int A[n];
	if(n%2){
		a=n/2+1;
		b=n/2;
	}
	else{
		a=b=n/2;
	}
	vi fw_o(a+1, 0);
	vi fw_e(b+1, 0);
	for(int i=1;i<=n;i++){
		cin>>A[i-1];
		if(i%2){
			update(fw_o, i/2+1, A[i-1]);
		}
		else{
			update(fw_e, i/2, A[i-1]);
		}
	}
	while(q--){
		cin>>a>>b>>c;
		if(a==1){
			a=A[b-1]^c;
			A[b-1]=c;
			if(b%2){
				update(fw_o, b/2+1, a);
			}
			else{
				update(fw_e, b/2, a);
			}
		}
		else{
			res=0;
			a=c-b+1;
			if(a%2==0){
				cout<<res<<"\n";
			}
			else{
				a=a/2+1;
				if(b%2){
					res=query(fw_o, b/2+a)^query(fw_o, b/2);
				}
				else{
					res=query(fw_e, b/2+a-1)^query(fw_e, b/2-1);
				}
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}
