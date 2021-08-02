#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, sa[5001], lcp[5001], cnt[5001], x[5001], y[5001];
char str[5001];
void getsa(){
	int i, j, k, p, m=26;
	//i번째 문자를 알파벳 순서 번호로 바꾸면서 알파벳 수를 셈 
	for(i=1;i<=n;++i)	cnt[x[i]=str[i]-'a'+1]++;
	//i번째 알파벳까지의 누적 합 
	for(i=1;i<=m;++i)	cnt[i]+=cnt[i-1];
	//마지막 문자부터 counting sort
	//sa[i]:sorting한 i번째 suffix의 문자 위치 
	for(i=n;i;--i)	sa[cnt[x[i]]--]=i;
	//k를 2배씩 늘려가면서 앞에서부터 k*2글자만 보고 정렬 
	for(k=1, p=1;p<n;k<<=1, m=p){
		//y:현재 sa값이 가리키는 suffix의 k개 앞의 문자 idx 
		//k개의 suffix는 k개 앞의 문자가 없으므로 길이가 짧으면 
		//		더 앞에 나오도록 1~k의 y값을 n-k+1~n으로 지정 
		for(p=0,i=n-k;++i<=n;)	y[++p]=i;
		//sa 순서대로 sa index가 작을 수록 더 앞에 나오도록 
		//1~n-k+1의 y값을 지정 
		for(i=1;i<=n;++i)if(sa[i]>k)	y[++p]=sa[i]-k;
		//y배열의 counting sort 
		for(i=0;i<=m;++i)	cnt[i]=0;
		for(i=1;i<=n;++i)	cnt[x[y[i]]]++;
		for(i=1;i<=m;++i)	cnt[i]+=cnt[i-1];
		for(i=n;i;--i)	sa[cnt[x[y[i]]]--]=y[i];
		swap(x, y);
		//i번째 문자의 suffix array에 들어갈 순서 재정의 
		p=1;x[sa[1]]=1;
		for(i=1;i<n;++i){
			//i번째, i+1번째 suffix가 k번째 문자를 갖고,
			// suffix의 앞에서부터 k개에 대한 순서가 정해졌을 때 
			// 첫 문자를 시작으로 하는 suffix와 
			// k번째 문자를 시작으로 하는 suffix가 같을 경우  
			//	즉, k*2개 문자가 같을 경우, 같은 순서를 갖는다 
			if(sa[i]+k<=n && sa[i+1]+k<=n && y[sa[i]]==y[sa[i+1]] && y[sa[i]+k]==y[sa[i+1]+k])
				x[sa[i+1]]=p;
			//아닐 경우는 다른 순서로 분리 
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
