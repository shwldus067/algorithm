#include<iostream>
using namespace std;
int N, d[1<<15][16], w[16][16], b[1<<15], ans=1e9;
int main(){	//d[i][j]:���� �湮 bit�� i�� �� j��° ���� �湮 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>w[i][j];
	for(int i=1;i<N;++i)	d[0][i-1]=w[0][i];	//0��°�� �������� i��° ���� �湮 
	for(int i=0;i<N-1;++i)	b[1<<i]=i+1;	//�� ��° bit���� ���� 
	int i, j, k, ii, jj, last=1<<(N-1);
	for(i=1;i<last;++i){	//i:���� �湮 ����, 0���� ��߷� ������ 0��°�� �湮�ϴ� ���� ������� ���� 
		for(j=i;j;j=k){	//�湮�� ���� ���� 
			k=j&(j-1);	//1�� ������ bit off, ���� �湮 ���¿��� bit�� �ϳ��� ������ ����� bit ���� 
			int l=b[j^k];	//��� ���� ����, ù �湮 ���ýð� ������ �����Ƿ� 0~15�� ° bit�� ���� 
			int x=d[i^j^k][l-1];	//�ٸ� ���÷� �̵��ϱ� �� ��� 
			if(!x)	continue;	//0�� ��� �ش� �湮�� ���� �������� �ǹ� 
			for(ii=~i&(last-1);ii;ii=jj){	//�湮���� ���� ���� ���� 
				jj=ii&(ii-1);	//1�� ������ bit off, ���� �湮�� �� 
				int m=b[ii^jj];	//���� ���� ���� 
				int y=w[l][m];	//�߰� �̵� ��� 
				if(!y)	continue;
				if(!d[i][m-1] || d[i][m-1]>x+y)	d[i][m-1]=x+y;
			}
		}
	}
	--last;
	for(i=0;i<N-1;++i){	//ó�� ���÷� �ٽ� ���ư� 
		int x=w[i+1][0], y=d[last^(1<<i)][i];
		if(x && y && ans>x+y)	ans=x+y;
	}
	cout<<ans<<"\n";
	return 0;
}
