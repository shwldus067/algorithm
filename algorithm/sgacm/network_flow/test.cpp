#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#define v(type) vector<type>

struct node
{
    int x, y, z = 0;
    int dual;
    node() {}
    node(int _x, int _y) : x(_x), y(_y) {}
};

int N, K;
v(node) adj[10001], v;
bool visit[10001];

void splitvertex(int x);
void addnode(int x, int y);
int maxflow();
void printans(int cur);
int dfs(int cur);

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0);
    int i, j, a, t = 1;
    stringstream ss;
    while (1)
    {
        string str;
        cin >> K >> N;
        if (K == 0 && N == 0)
            break;
        for (i = 3; i <= N; i++)
            splitvertex(i);
        getline(cin, str);
        for (i = 1; i <= N; i++)
        {
            getline(cin, str);
            ss.str(str);
            while (ss >> a)
            {
                if (a < i)
                    continue;
                addnode(i, a), addnode(a, i);
            }
            ss.clear();
        }

        int ans = maxflow();
        cout << "Case " << t++ << ":\n";
        if (ans < K)
            cout << "Impossible\n";
        else
            printans(1);
        cout << "\n";
        for (i = 1; i <= N * 2; i++)
            adj[i].clear();
    }

    return 0;
}

void splitvertex(int x)
{
    int i = adj[x].size(), j = adj[x + N].size();
    adj[x].push_back({x + N, 1}), adj[x + N].push_back({x, 0});
    adj[x][i].dual = j, adj[x + N][j].dual = i;
}

void addnode(int x, int y)
{
    if (x > 2)
        x += N;
    int i = adj[x].size(), j = adj[y].size();
    adj[x].push_back({y, 1}), adj[y].push_back({x, 0});
    adj[x][i].dual = j, adj[y][j].dual = i;
}

int maxflow()
{
    int res = 0;
    while (1)
    {
        int i, mn = ~(1 << 31);
        v.clear();
        for (i = 1; i <= N * 2; i++)
            visit[i] = false;
        if (res == K || !dfs(1))
            return res;
        for (i=0;i<v.size();i++)
        {
        	node itr=v[i];
            node &n = adj[itr.x][itr.y];
            mn = min(mn, n.y - n.z);
        }
        for (i=0;i<v.size();i++){
        	node itr=v[i];
            adj[itr.x][itr.y].z += mn, adj[adj[itr.x][itr.y].x][adj[itr.x][itr.y].dual].z -= mn;
		}
        res += mn;
    }
}

void printans(int cur)
{
    if (cur == 2)
    {
        cout << "2\n";
        return;
    }
    int i;
    for (i = 0; i < adj[cur].size(); i++)
    {
        if (!adj[cur][i].y || !adj[cur][i].z)
            continue;
        if (cur <= N)
            cout << cur << " ";
        printans(adj[cur][i].x);
    }
}

int dfs(int cur)
{
    int i;
    visit[cur] = true;
    if (cur == 2)
        return 1;
    for (i = 0; i < adj[cur].size(); i++)
    {
        node &itr = adj[cur][i];
        if (visit[itr.x] || itr.y == itr.z)
            continue;
        v.push_back({cur, i});
        if (dfs(itr.x))
            return 1;
        v.pop_back();
    }
    return 0;
}
