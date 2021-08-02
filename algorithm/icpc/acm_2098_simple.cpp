#include<iostream>
using namespace std;
int N, d[1<<16][16], w[16][16], b[1<<16];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>w[i][j];
	for(int i=0;i<N;++i)	b[1<<i]=i;	//�� ��° bit�� ���� �ִ��� ���� 
	int last=(1<<N)-1;	//��� �湮���� ���� bit 
	fill(&d[0][0], &d[last][16], 1e9);	//�ּҰ��� ã�� ���� ū ������ �ʱ�ȭ 
	d[1][0]=0;	//ù �湮�ϴ� ���ø� index 0�� ���÷� �ϰ� �� ���� ����� 0 
	for(int i=1;i<=last;++i){
		for(int j=i;j;j&=j-1){	//���� �湮�� ���� ���ʷ� ����  //j&=j-1 -> 1�� bit �� ���� ���� bit off 
			int k=j&(-j);	//1�� bit�� ���� ���� bit ���� 
			k=b[k];	//�� bit�� �� ��° bit���� 
			if(d[i][k]!=1e9){
				for(int jj=last&~i;jj;jj&=jj-1){	//�湮���� ���� ���� ���� 
					int kk=jj&(-jj);	//1�� bit�� ���� ���� bit ���� 
					kk=b[kk];	//�� bit�� �� ��° bit���� 
					int l=i|(1<<kk);	//�湮�� ������ bit ���� 
					if(w[k][kk])	d[l][kk]=min(d[l][kk], d[i][k]+w[k][kk]);	//k���ÿ��� kk���ø� �湮���� ���� dp�� update 
				}
			}
		}
	}
	int ans=1e9;
	for(int i=1;i<N;++i){
		if(w[i][0])	ans=min(ans, d[last][i]+w[i][0]);
	}
	cout<<ans<<"\n";
	return 0;
}
