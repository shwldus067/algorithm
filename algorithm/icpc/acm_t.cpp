#include <cstdio>
#include<iostream>
#include<vector>

#pragma warning(disable:4996)
using namespace std;


int min(int aaa, int bbb)
{
	return aaa >= bbb ? bbb : aaa;
}
int max(int aaa, int bbbb)
{
	return aaa >= bbbb ? aaa : bbbb;
}
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
char dc[] = { 'U','L','D','R' };

class xy
{
public:
	int x;
	int y;

};
int flag = 0;
long long num[1002];
char ch[1002];
xy tr[1002];

int main(void)
{
	long long size;
	cin >> size;
	int n;
	cin >> n;
	int head = 3;
	tr[0].x = 0;
	tr[0].y = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %c", &num[i], &ch[i]);
	}

	for (int i = 1; i <= n+1; i++) //맨마지막 입력값이 없어도 가는경우 추가:완료
	{

		int x = tr[i - 1].x;
		int y = tr[i - 1].y;
		if (i == n + 1)
		{
			num[i]=size*2+1;
			
		}
	
		int for_min = 1<<31-1;
		//지금 까지 지나왔던거에 부딪혀 죽는 경우 추가완료
		for (int j = 0; j <= i - 3; j++)
		{

			if (head == 2)
			{
				if ((tr[j].y == tr[j + 1].y) && (x <= max(tr[j].x, tr[j + 1].x)) && (x >= min(tr[j].x, tr[j + 1].x)) && (y<tr[j].y) && (y + dy[head] * num[i] >= tr[j].y))
				{
					int temp = tr[j].y - y;
					if (temp < for_min) for_min = temp;
					flag = 1;
				}
			}
			if (head == 0)
			{
				if ((tr[j].y == tr[j + 1].y) && (x <= max(tr[j].x, tr[j + 1].x)) && (x >= min(tr[j].x, tr[j + 1].x)) && (y>tr[j].y) && (y + dy[head] * num[i] <= tr[j].y))
				{
					int temp = y - tr[j].y;
					if (temp < for_min) for_min = temp;
					flag = 1;
				}
			}
			if (head == 1)
			{
				if ((tr[j].x == tr[j + 1].x) && (y <= max(tr[j].y, tr[j + 1].y)) && (y >= min(tr[j].y, tr[j + 1].y)) && (x>tr[j].x) && (x + dx[head] * num[i] <= tr[j].x))
				{
					int temp = x - tr[j].x;
					if (temp < for_min) for_min = temp;
					flag = 1;
				}
			}
			if (head == 3)
			{
				if ((tr[j].x == tr[j + 1].x) && (y <= max(tr[j].y, tr[j + 1].y)) && (y >= min(tr[j].y, tr[j + 1].y)) && (x<tr[j].x) && (x + dx[head] * num[i] >= tr[j].x))
				{
					int temp = tr[j].x - x;
					if (temp < for_min) for_min = temp;
					flag = 1;
				}
			}


		}
		if (flag == 1) {

			ans += for_min;
			break;
		}

		//벽 끝에 부딪혀서 죽는 경우 추가 완료
		if ((x + dx[head] * num[i] < -size) || (x + dx[head] * num[i] > size) || (y + dy[head] * num[i] > size) || (y + dy[head] * num[i] < -size))
		{
			if (head == 0)
			{
				ans += (y + size+1);
			}
			else if (head == 1)
			{
				ans += (x + size+1);
			}
			else if (head == 2)
			{
				ans += (size - y+1);
			}
			else if (head == 3)
			{
				ans += (size - x+1);
			}
			break;
		}
		
		
		//안 죽는 경우
		x += dx[head] * num[i];
		y += dy[head] * num[i];
		ans += num[i];
		tr[i].x = x;
		tr[i].y = y;

		if (ch[i] == 'L')
		{
			head = (head + 1) % 4;
		}
		else if (ch[i] == 'R')
		{
			head = (head + 3) % 4;
		}

	}

	cout << ans << endl;

}
