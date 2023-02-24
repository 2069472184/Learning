//https://www.acwing.com/problem/content/851/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510;

int n, m;
//gΪ�ڽӾ���dist�洢ÿ���ڵ㵽1����̾���
int g[N][N], dist[N];
//�������飬��֤ÿ����֮����һ��
bool st[N];

int dijkstra()
{
    //��ʼ������=
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    //��������
    for ( int i = 0; i < n; i++ )
    {
        int t = -1;
        for( int j = 1; j <= n; j++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
                
        st[t] = true;
                
        for ( int i = 1; i <= n; i++ )
            dist[i] = min(dist[i], dist[t] + g[t][i]);
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main ()
{
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof g);
    
    while (m--)
    {
        int x, y, z
        cin >> x >> y >> z;
        g[x][y] = min(z, g[x][y]);
    }
    
    cout << dijkstra();
    
    return 0;
}