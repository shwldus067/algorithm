#include<iostream>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, pair<int, int> > line;
int T, square[4], cnt, dup;
int x[]={0, 0, 2, 2, 0}, y[]={1, 3, 3, 1, 1};
bool inf;
int ccw(pii &a, pii &b, pii& c){
	int x1=b.first-a.first, y1=b.second-a.second;
	int x2=c.first-a.first, y2=c.second-a.second;
	int ret=x1*y2-y1*x2;
	if(ret>0)	return 1;
	else if(ret==0)	return 0;
	else	return -1;
}
bool cross(line &a, line &b){
	pii p1, p2, p3, p4;
	p1=a.first, p2=a.second, p3=b.first, p4=b.second;
	int p=ccw(p1, p2, p3)*ccw(p1, p2, p4), r, s;
	int q=(r=ccw(p3, p4, p1))*(s=ccw(p3, p4, p2));
	if(p==0 && q==0){
		if(p1>p2)	swap(p1, p2);
		if(p3>p4)	swap(p3, p4);
		if(p1<p4 && p3<p2 && r==0 && s==0){
			cnt=4;
			inf=true;
			return true;
		}
		if(p1==p4 || p2==p3 || p1==p3 || p2==p4){
			cnt++;
		}
	}
	else if(p<=0 && q<=0)	cnt++;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		line f, s;
		int a, b, c, d;
		for(int j=0;j<4;j++)
			cin>>square[j];
		cin>>a>>b>>c>>d;
		s={{a, b}, {c, d}};
		cnt=0;
		inf=false;
		dup=0;
		for(int i=0;i<4;i++){
			f={{square[x[i]], square[y[i]]}, {square[x[i+1]], square[y[i+1]]}};
			if(cross(f, s))	break;
		}
		if(inf)	cout<<"4\n";
		else{
			for(int i=0;i<4;i++){
				pii sp=make_pair(square[x[i]], square[y[i]]);
				if(ccw(s.first, s.second, sp)==0){
					if(s.first>s.second)
						swap(s.first, s.second);
					if(s.first<=sp && sp<=s.second)	dup++;
				}
			}
			cout<<cnt-dup<<"\n";
		}
	}
	return 0;
}
