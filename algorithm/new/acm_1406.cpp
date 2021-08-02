#include<iostream>
#include<string>
using namespace std;
typedef struct _node{
	char ch;
	_node *pre=NULL;
	_node *next=NULL;
}node;
int main(){
	int N;
	string str;
	char cmd, tmp;
	node *current=new node;
	node *top=current;
	cin>>str;
	for(int i=0;i<str.length();i++){
		node *temp=new node;
		temp->ch=str[i];
		current->next=temp;
		temp->pre=current;
		current=temp;
	}
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>cmd;
		switch(cmd){
			case 'L':
				if(current->pre!=NULL)	current=current->pre;
				break;
			case 'D':
				if(current->next!=NULL)	current=current->next;
				break;
			case 'B':
				if(current->pre!=NULL){
					node *temp=current;
					current->pre->next=current->next;
					if(current->next!=NULL){
						current->next->pre=current->pre;
					}
					current=current->pre;
				}
				break;
			case 'P':
				cin>>tmp;
				node *temp=new node;
				temp->ch=tmp;
				if(current->next!=NULL){
					current->next->pre=temp;
					temp->next=current->next;
				}
				temp->pre=current;
				current->next=temp;
				current=temp;
				break;
		}
	}
	current=top->next;
	while(current!=NULL){
		cout<<current->ch;
		current=current->next;
	}
	cout<<"\n";
}
