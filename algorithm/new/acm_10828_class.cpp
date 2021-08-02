#include<iostream>
#include<string>
using namespace std;
template <typename T>
class node{
	public:
		T num;
		node<T> *next=NULL;
};

template <typename T>
class stack{
	private:
		int size=0;
		node<T> *top=NULL;
	public:
		void push(T num){
			node<T> *tmp=new node<T>;
			tmp->num=num;
			tmp->next=top;
			top=tmp;
			size++;
		}
		T pop(void){
			if(size==0)	return -1;
			T tmp=top->num;
			top=top->next;
			size--;
			return tmp;
		}
		int getsize(void){
			return size;
		}
		bool isempty(void){
			return size==0;
		}
		int gettop(void){
			if(size==0)	return -1;
			return top->num;
		}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, tmp;
	stack<int> S;
	string cmd;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>cmd;
		if(cmd=="push"){
			cin>>tmp;
			S.push(tmp);
		}
		else if(cmd=="pop"){
			cout<<S.pop()<<"\n";
		}
		else if(cmd=="size"){
			cout<<S.getsize()<<"\n";
		}
		else if(cmd=="empty"){
			if(S.isempty())	cout<<1<<"\n";
			else	cout<<0<<"\n";
		}
		else if(cmd=="top"){
			cout<<S.gettop()<<"\n";
		}
	}
	return 0;
}
