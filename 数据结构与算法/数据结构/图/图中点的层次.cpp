//https://www.acwing.com/problem/content/849/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 100010, M = N * 2;

int n, m;
//�洢ͼ
int h[N], e[M], ne[M], idx;
//d[i]�洢���Ϊ1�Ľڵ㵽i�ľ���
int d[N];

queue<int> q;

void add (int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs ()
{
    q.push(1);    
    
    d[1] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        
        for ( int i = h[t]; i != -1; i = ne[i] )
            //�˴�ҲҪ��֤ÿ���ڵ�ֻ����һ��
            if (d[e[i]] == -1) 
            {
                d[e[i]] = d[t] + 1;
                q.push(e[i]);
            }
    }
    
    return d[n];
}

int main ()
{
    cin >> n >> m;
    
    //��ʼ����������Ϊ-1���ȷ������أ��ַ�������޽�����
    memset(d, -1, sizeof(d));
    //�ڽӱ��ͷ�ڵ��ʼֵ����-1
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    
    cout << bfs();
    
    return 0;
}