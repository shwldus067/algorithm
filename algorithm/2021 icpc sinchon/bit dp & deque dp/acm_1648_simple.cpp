#include<iostream>
using namespace std;
const int mod=9901;
int d[15][1<<14];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, L;
	cin>>N>>M;
	K=1<<M;L=N*M;
	d[0][K-1]=1;
	// �� �� �� ä�� 
	for(int i=1;i<=N;++i){
		// i��° �ٱ��� ���� ���̳�� ä�� 
		// �� ���� ä���� ������ ���θ� �� �� ���� 
		// �� ���� ������� �Ʒ� �ٿ��� ä���� ��� ĭ�� ä�� �� ���� 
		for(int j=0;j<K;++j)	d[i][j]=d[i-1][(~j)&(K-1)];
		// ���� ���̳�� ä�� 
		for(int j=3;j<K;j<<=1){
			for(int k=0;k<K;++k){
				if(k&j)	continue;
				// k���¿��� ����ĭ�� �ϳ� �߰��� 
				d[i][k|j]=(d[i][k|j]+d[i][k])%mod;
			}
		}
	}
	cout<<d[N][K-1]<<"\n";
	return 0;
}
