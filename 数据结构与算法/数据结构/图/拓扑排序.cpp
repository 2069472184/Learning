//https://www.acwing.com/problem/content/description/850/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
//q�������ɴ洢���Ϊ0�Ľڵ㣬d�洢���е�����
int q[N], d[N];

void add (int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort ()
{
    int hh = 0, tt = -1;
    
    //�Ƚ��������Ϊ 0 �ĵ��������
    for ( int i = 1; i <= n; i++ )
        if (!d[i]) q[++tt] = i;
    
    while (hh <= tt)
    {
        int t = q[hh++];
        
        for ( int i = h[t]; i != -1; i = ne[i] )
        {
            //��ʱt������ǰ�棬������ֻ�г��ȣ�����ɾȥ�������ж���Ӱ���ָ��
            //�߻��������о���e[i]�����-1
            d[e[i]]--;
            //�����ʱe[i]����ȼ�Ϊ0��˵����ʱe[i]Ҳ�����Ƶ���ǰ��
            if (d[e[i]] == 0) q[++tt] = e[i];
        }
    }
    
    //�˴��ж�ɾȥǰ�����ָ����Ƿ�����ж���ͬ��ָ��ĵ�
    //���Ƿ����е㶼�������˶�����
    return tt == n - 1;
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    for ( int i = 1; i <= m; i++ )
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y]++;
    }
    
    if (topsort())
    {
        for ( int i = 0; i < n; i++ ) cout << q[i] << ' ';
        puts("");
    }
    else cout << -1;
    
    return 0;
}