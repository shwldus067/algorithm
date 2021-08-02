#include<iostream>
using namespace std;
int N, x1, x2, y;
int sol(int n, int a1, int a2, int b, int t){
	if(n==1){
		if(t==0){
			if(b==1){
				if(a2-a1==1)	return 1;
				else if(a2-a1==2)	return 2;
			}
		}
		else{
			if(b==1){
				if(a2>=1 && a1==0)	return 1;
			}
		}
		return 0;
	}
	int mid=1<<(n-1);
	if(b==mid){
		if(t==0){
			if(a1==0){
				if(a2==(mid>>1))	return 2;
				return 1;
			}
			if(a2==(mid>>1))	return 1;
			return 0;
		}
		else{
			if(a1<mid && a2>=mid)	return 1;
			return 0;
		}
	}
	int res=0;
	if(t==0){
		if(b<mid){
			if(a1<mid && mid<a2){
				if(mid-a1<=a2-mid){
					res+=sol(n-1, a1, mid, b, t)*2;
					if(mid-a1<a2-mid){
						res+=sol(n-1, mid-a1, a2-mid, b, t);
					}
				}
				else{
					res+=sol(n-1, 0, a2-mid, b, t)*2;
					res+=sol(n-1, a1, (mid<<1)-a2, b, t);
				}
			}
			else if(a1<mid){
				res+=sol(n-1, a1, a2, b, t);
			}
			else if(a2>mid){
				res+=sol(n-1, a1-mid, a2-mid, b, t);
			}
		}
		else{
			if(a1<mid && mid<a2){
				if(mid-a1<=a2-mid){
					res+=sol(n-1, 0, mid-a1, b-mid, t^1)*2;
					if(mid-a1<a2-mid){
						res+=sol(n-1, mid-a1, a2-mid, b-mid, t^1);
					}
				}
				else{
					res+=sol(n-1, 0, a2-mid, b-mid, t^1)*2;
					res+=sol(n-1, a2-mid, mid-a1, b-mid, t^1);
				}
			}
			else if(a1<mid){
				res+=sol(n-1, mid-a2, mid-a1, b-mid, t^1);
			}
			else if(a2>mid){
				res+=sol(n-1, a1-mid, a2-mid, b-mid, t^1);
			}
		}
	}
	else{
		if(b<mid){
			if(a1<mid){
				if(a2<mid)	res+=sol(n-1, a1, a2, b, t);
				else	res+=sol(n-1, a1, mid, b, t);
			}
			if(a2>mid){
				if(a1>mid)	res+=sol(n-1, a1-mid, a2-mid, mid-b, t^1);
				else	res+=sol(n-1, 0, a2-mid, mid-b, t^1);
			}
		}
		else{
			if(a1<mid){
				if(a2<mid)	res+=sol(n-1, a1, a2, b-mid, t);
				else	res+=sol(n-1, a1, mid, b-mid, t);
			}
			if(a2>mid){
				if(a1>mid)	res+=sol(n-1, (mid<<1)-a2, (mid<<1)-a1, b-mid, t^1);
				else	res+=sol(n-1, (mid<<1)-a2, mid, b-mid, t^1);
			}
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(N!=0){
		cin>>x1>>x2>>y;
		cout<<sol(N, x1, x2, y, 0)<<"\n";
		cin>>N;
	}
	return 0;
}
