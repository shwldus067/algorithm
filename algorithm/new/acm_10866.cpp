#include<iostream>
#include<string>
using namespace std;
template <typename T>
class node{
	public:
		T num;
		node<T> *pre=NULL;
		node<T> *next=NULL;
};

template <typename T>
class deque{
	private:
		int size=0;
		node<T> *front=NULL;
		node<T> *back=NULL;
	public:
		void push_front(T num){
			node<T> *tmp=new node<T>;
			tmp->num=num;
			tmp->next=front;
			if(size==0){
				back=tmp;
			}
			else{
				front->pre=tmp;
			}
			front=tmp;
			size++;
		}
		void push_back(T num){
			node<T> *tmp=new node<T>;
			tmp->num=num;
			tmp->pre=back;
			if(size==0){
				front=tmp;
			}
			else{
				back->next=tmp;
			}
			back=tmp;
			size++;
		}
		T pop_front(void){
			if(size==0)	return -1;
			node<T> *tmp=front;
			T r_num=front->num;
			front=front->next;
			size--;
			delete tmp;
			return r_num;
		}
		T pop_back(void){
			if(size==0)	return -1;
			node<T> *tmp=back;
			T r_num=back->num;
			back=back->pre;
			size--;
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
	int N, tmp;
	string cmd;
	cin>>N;
	deque<int> D;
	for(int i=0;i<N;i++){
		cin>>cmd;
		if(cmd=="push_front"){
			cin>>tmp;
			D.push_front(tmp);
		}
		else if(cmd=="push_back"){
			cin>>tmp;
			D.push_back(tmp);
		}
		else if(cmd=="pop_front"){
			cout<<D.pop_front()<<"\n";
		}
		else if(cmd=="pop_back"){
			cout<<D.pop_back()<<"\n";
		}
		else if(cmd=="size"){
			cout<<D.getsize()<<"\n";
		}
		else if(cmd=="empty"){
			if(D.isempty())	cout<<1<<"\n";
			else cout<<0<<"\n";
		}
		else if(cmd=="front"){
			cout<<D.getfront()<<"\n";
		}
		else if(cmd=="back"){
			cout<<D.getback()<<"\n";
		}
	}
}
