#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
typedef struct _node{
	int num;
	_node* next;
}node;
int size=0;
node *S=NULL;
void push(int num){
	node* tmp;
	tmp=(node *)malloc(sizeof(node));
	tmp->num=num;
	tmp->next=S;
	S=tmp;
	size++;
}
int pop(void){
	if(size==0)	return -1;
	int tmp=S->num;
	S=S->next;
	size--;
	return tmp;
}
int top(void){
	if(size==0)	return -1;
	return S->num;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, tmp;
	string cmd;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>cmd;
		if(cmd=="push"){
			cin>>tmp;
			push(tmp);
		}
		else if(cmd=="pop"){
			cout<<pop()<<"\n";
		}
		else if(cmd=="size"){
			cout<<size<<"\n";
		}
		else if(cmd=="empty"){
			if(size==0)	cout<<1<<"\n";
			else	cout<<0<<"\n";
		}
		else if(cmd=="top"){
			cout<<top()<<"\n";
		}
	}
}
