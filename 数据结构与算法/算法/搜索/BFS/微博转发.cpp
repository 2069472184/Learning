//https://www.acwing.com/problem/content/1564/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M = 100010;

int n, l;
bool st[N];
int h[N], e[M], ne[M], idx;
int q[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs (int x)
{
    int hh = 0, tt = 0;
    q[0] = x;
    
    memset(st, 0, sizeof(st));
    st[x] = true;
    
    int ans = 0;
    for (int j = 0; j < l; j++)
    {
        //ֻ������ǰһ���ע���ˣ�����Ҫ�ȼ�¼��ǰ�����е�Ԫ�ظ���
        int len = tt - hh + 1;
        while (len--)
        {
            auto t = q[hh++];
            
            //��ǰ������ӵ�Ԫ�ؾ�����һ������й�ע��
            for (int i = h[t]; i != -1; i = ne[i])
                if (!st[e[i]]) 
                {
                    q[++tt] = e[i];
                    st[e[i]] = true;
                    //ֻҪ����һ����˿���Ͷ�һ��ת����
                    ans++;
                }
        }
    }
    
    return ans;
}

int main ()
{
    cin >> n >> l;
    
    memset(h, -1, sizeof(h));
    
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        while(num--)
        {
            int x;
            scanf("%d", &x);
            //Ϊ�˿���ʱ���㣬������ "a��עb" Ϊ "a <- b"
            add(x, i);
        }
    }
    
    int c;
    cin >> c;
    
    while (c--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", bfs(x));
    }
    
    return 0;
}
