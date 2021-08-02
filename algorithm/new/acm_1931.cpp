#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct meeting{
	int start, finish;
};
bool compare(meeting a, meeting b){
	if(a.finish != b.finish)	return a.finish<b.finish;
	else	return a.start<b.start;
}
int main(){
	int N, cnt, start, finish, tmp;
	meeting temp;
	cin>>N;
	vector<meeting> meeting_vec;
	for(int i=0;i<N;i++){
		cin>>temp.start>>temp.finish;
		meeting_vec.push_back(temp);
	}
	sort(meeting_vec.begin(), meeting_vec.end(), compare);
	
	cnt=1;
	tmp=0;
	for(int i=1;i<N;i++){
		if(meeting_vec[i].start>=meeting_vec[tmp].finish){
			cnt++;
			tmp=i;
		}
	}
	cout<<cnt;
	return 0;
}
