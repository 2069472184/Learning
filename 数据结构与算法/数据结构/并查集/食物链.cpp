//https://www.acwing.com/problem/content/242/

//��Ȩ���鼯
/*
������ÿ���ڵ㵽���ڵ�ľ����3��ģ������ʾ�ڵ�֮��Ĺ�ϵ��
mod 3 = 1:���ԳԸ��ڵ�
mod 3 = 2:���Ա����ڵ��
mod 3 = 0:�͸��ڵ�ͬ��
*/
#include <iostream>
using namespace std;

const int N = 100010;
typedef long long ll;
typedef unsigned long long ull;

int n, k, t, x, y, ans;

//d����洢�ڵ㵽���ڵ�ľ��룬��������·��ѹ���Ľ��У�
//���ڵ��ɸ��ڵ㣬����ֵ�Ͼͱ�ʾ�ڵ㵽���ڵ�ľ�����
int p[N], d[N];

int Find ( int u )
{
    if ( p[u] != u )
    {
        int t = Find(p[u]);
        //�˴���+=��ԭ���ǿ�������֮ǰx���ڼ������ӵ���y���ڼ����У��������ӵĲ���ֻ�õ���d[px];
        //d[x]��û�б����£���������������ԭ����ֵ��������Ҫ���������+=
        d[u] += d[p[u]];
        p[u] = t;
    } 
    return p[u];
}

int main ()
{   
    cin >> n >> k;

    for ( int i = 1; i <= n; i++ ) p[i] = i; 

    while ( k-- )
    {
        cin >> t >> x >> y;

        if ( x > n || y > n ) ans++;
        else
        {
            int px = Find(x), py = Find(y);
            if (t == 1)
            {
                if ( px == py && (d[x] - d[y]) % 3 ) ans++;
                else if ( px != py )
                {
                    p[px] = py;
                    //��ʱx���ڼ��ϵĸ��ڵ�px����y���ڼ��ϸ��ڵ�py�ľ��뻹��δ֪��
                    // ( d[px] + d[x] ) % 3 = d[y] % 3;
                    d[px] = d[y] - d[x];
                    //ע�⣬�����������Ϻ�d[x]��û�и��£�����Ҫ����Find�����н���
                }
            }
            else
            {
                if ( px == py && (d[x] - d[y] - 1) % 3 ) ans++;
                else if ( px != py )
                {
                    p[px] = py;
                    // ( d[px] + d[x] ) % 3 = ( d[y] + 1 ) % 3
                    d[px] = d[y] + 1 - d[x];
                    //ͬ�ϣ�d[x]δ����
                }
            }
        }
    }

    cout << ans;

    return 0;
}