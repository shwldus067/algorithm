#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
struct ss{
	char s[16];
	bool operator<(const ss a)const{
		return strcmp(s, a.s)<0;
	}
};
struct trie{
	map<ss, trie*> next;
	bool finish;
	trie(){
		finish=false;
	}
	~trie(){
		map<ss, trie*>::iterator iter;
		for(iter=next.begin();iter!=next.end();++iter){
			if(iter->second){
				delete iter->second;
			}
		}
	}
	trie* insert(const ss key){
		map<ss, trie*>::iterator it;
		if((it=next.find(key))==next.end()){
			trie* tmp=new trie;
			next.insert({key, tmp});
			return tmp;
		}else{
			return it->second;
		}
	}
	void print(int n){
		if(finish)	return;
		map<ss, trie*>::iterator iter;
		for(iter=next.begin();iter!=next.end();++iter){
			for(int i=0;i<n;++i)	printf("--");
			printf("%s\n", iter->first.s);
			iter->second->print(n+1);
		}
	}
}root;
int main(){
	int N, K;
	ss str;
	trie *cur;
	scanf("%d", &N);
	for(int i=0;i<N;++i){
		scanf("%d", &K);
		cur=&root;
		while(K--){
			scanf("%s", str.s);
			cur=cur->insert(str);
		}
		cur->finish=true;
	}
	root.print(0);
	return 0;
}
