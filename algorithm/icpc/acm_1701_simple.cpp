#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, sa[5001], lcp[5001], cnt[5001], x[5001], y[5001];
char str[5001];
void getsa(){
	int i, j, k, p, m=26;
	//i��° ���ڸ� ���ĺ� ���� ��ȣ�� �ٲٸ鼭 ���ĺ� ���� �� 
	for(i=1;i<=n;++i)	cnt[x[i]=str[i]-'a'+1]++;
	//i��° ���ĺ������� ���� �� 
	for(i=1;i<=m;++i)	cnt[i]+=cnt[i-1];
	//������ ���ں��� counting sort
	//sa[i]:sorting�� i��° suffix�� ���� ��ġ 
	for(i=n;i;--i)	sa[cnt[x[i]]--]=i;
	//k�� 2�辿 �÷����鼭 �տ������� k*2���ڸ� ���� ���� 
	for(k=1, p=1;p<n;k<<=1, m=p){
		//y:���� sa���� ����Ű�� suffix�� k�� ���� ���� idx 
		//k���� suffix�� k�� ���� ���ڰ� �����Ƿ� ���̰� ª���� 
		//		�� �տ� �������� 1~k�� y���� n-k+1~n���� ���� 
		for(p=0,i=n-k;++i<=n;)	y[++p]=i;
		//sa ������� sa index�� ���� ���� �� �տ� �������� 
		//1~n-k+1�� y���� ���� 
		for(i=1;i<=n;++i)if(sa[i]>k)	y[++p]=sa[i]-k;
		//y�迭�� counting sort 
		for(i=0;i<=m;++i)	cnt[i]=0;
		for(i=1;i<=n;++i)	cnt[x[y[i]]]++;
		for(i=1;i<=m;++i)	cnt[i]+=cnt[i-1];
		for(i=n;i;--i)	sa[cnt[x[y[i]]]--]=y[i];
		swap(x, y);
		//i��° ������ suffix array�� �� ���� ������ 
		p=1;x[sa[1]]=1;
		for(i=1;i<n;++i){
			//i��°, i+1��° suffix�� k��° ���ڸ� ����,
			// suffix�� �տ������� k���� ���� ������ �������� �� 
			// ù ���ڸ� �������� �ϴ� suffix�� 
			// k��° ���ڸ� �������� �ϴ� suffix�� ���� ���  
			//	��, k*2�� ���ڰ� ���� ���, ���� ������ ���´� 
			if(sa[i]+k<=n && sa[i+1]+k<=n && y[sa[i]]==y[sa[i+1]] && y[sa[i]+k]==y[sa[i+1]+k])
				x[sa[i+1]]=p;
			//�ƴ� ���� �ٸ� ������ �и� 
			else
				x[sa[i+1]]=++p;
		}
	}
}
void getlcp(){
	int i, j, k=0;
	int rank[5001]={0, };
	for(i=1;i<=n;++i)	rank[sa[i]]=i;
	for(i=1;i<n;lcp[rank[i++]]=k)
		for(k?k--:0, j=sa[rank[i]-1];str[i+k]==str[j+k];++k);
}
int main(){
	scanf("%s", str+1);
	n=strlen(str+1);
	getsa();
	getlcp();
	int ans=0;
	for(int i=2;i<=n;++i)	ans=max(ans, lcp[i]);
	printf("%d\n", ans);
	return 0;
}
