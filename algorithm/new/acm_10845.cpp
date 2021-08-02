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
class queue{
	private:
		int size=0;
		node<T> *front=NULL;
		node<T> *back=NULL;
	public:
		void push(T num){
			node<T> *tmp=new node<T>;
			tmp->num=num;
			tmp->next=NULL;
			if(size==0){
				front=tmp;
			}
			else{
				back->next=tmp;
			}
			back=tmp;
			size++;
		}
		T pop(void){
			if(size==0)	return -1;
			node<T> *tmp=front;
			T r_num=tmp->num;
			size--;
			front=front->next;
			if(size==0)	back=NULL;
			delete tmp;
			return r_num;
		}
		int getsize(void){
			return size;
		}
		bool isempty(void){
			return size==0;
		}
		T getfront(void){
			if(size==0)	return -1;
			return front->num;
		}
		T getback(void){
			if(size==0)	return -1;
			return back->num;
		}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	string cmd;
	queue<int> Q;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>cmd;
		if(cmd=="push"){
			int tmp;
			cin>>tmp;
			Q.push(tmp);
		}
		else if(cmd=="pop"){
			cout<<Q.pop()<<"\n";
		}
		else if(cmd=="size"){
			cout<<Q.getsize()<<"\n";
		}
		else if(cmd=="empty"){
			if(Q.isempty())	cout<<1<<"\n";
			else	cout<<0<<"\n";
		}
		else if(cmd=="front"){
			cout<<Q.getfront()<<"\n";
		}
		else if(cmd=="back"){
			cout<<Q.getback()<<"\n";
		}
	}
}
