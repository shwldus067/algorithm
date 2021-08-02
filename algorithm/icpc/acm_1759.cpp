#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int L, C, a, b, i, j, k;
	cin>>L>>C;
	char c[C], v[5]={'a', 'e', 'i', 'o', 'u'}, res[L];
	bool p[C]={false, }, f;
	for(i=0;i<C;i++)	cin>>c[i];
	for(i=0;i<L;i++)	p[i]=true;
	sort(c, c+C);
	do{
		k=a=b=0;
		for(i=0;i<C;i++){
			if(p[i]){
				f=false;
				for(j=0;j<5;j++){
					if(c[i]==v[j]){
						f=true;
						break;
					}
				}
				if(f)	a++;
				else	b++;
				res[k]=c[i];
				k++;
			}
		}
		if(a>0 && b>1){
			for(i=0;i<L;i++)
				cout<<res[i];
			cout<<"\n";
		}
	}while(prev_permutation(p, p+C));
}
