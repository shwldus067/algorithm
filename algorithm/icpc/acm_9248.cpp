#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, sa[500001], lcp[500001], cnt[500001], x[500001], y[500001];
char str[500001];
void getsa(){
	int i, k, p, m=26;
	for(i=1;i<=n;++i)	cnt[x[i]=str[i]-'a'+1]++;
	for(i=1;i<=m;++i)	cnt[i]+=cnt[i-1];
	for(i=n;i;--i)	sa[cnt[x[i]]--]=i;
	for(k=1, p=1;p<n;k<<=1, m=p){
		for(p=0,i=n-k;++i<=n;)	y[++p]=i;
		for(i=1;i<=n;++i)if(sa[i]>k)	y[++p]=sa[i]-k;
		for(i=0;i<=m;++i)	cnt[i]=0;
		for(i=1;i<=n;++i)	cnt[x[y[i]]]++;
		for(i=1;i<=m;++i)	cnt[i]+=cnt[i-1];
		for(i=n;i;--i)	sa[cnt[x[y[i]]]--]=y[i];
		swap(x, y);
		p=1;x[sa[1]]=1;
		for(i=1;i<n;++i){
			if(sa[i]+k<=n && sa[i+1]+k<=n && y[sa[i]]==y[sa[i+1]] && y[sa[i]+k]==y[sa[i+1]+k])
				x[sa[i+1]]=p;
			else
				x[sa[i+1]]=++p;
		}
	}
}
void getlcp(){
	int i, j, k=0;
	int rank[500001]={0, };
	for(i=1;i<=n;++i)	rank[sa[i]]=i;
	for(i=1;i<n;lcp[rank[i++]]=k)
		for(k?k--:0, j=sa[rank[i]-1];str[i+k]==str[j+k];++k);
}
int main(){
    scanf("%s", str+1);
	n=strlen(str+1);
	getsa();
	getlcp();
	for(int i=1;i<=n;++i)	printf("%d ", sa[i]);
	printf("\nx");
	for(int i=2;i<=n;++i)	printf(" %d", lcp[i]);
	printf("\n");
	return 0;
}
