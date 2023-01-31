//https://www.acwing.com/problem/content/838/

#include <iostream>
using namespace std;

const int N = 100010;

int n, m, p[N];
string h;
int a, b;

//����x�ĸ��ڵ�+·���Ż�
int Find ( int x )
{
    //Ϊʲô�õݹ�����õ�������Ϊ�ݹ����ֱ����һ��·���ϵĽڵ�ȫ��ָ����ڵ㣬ֻ��Ҫ��һ�ξͺ�
    if ( p[x] != x ) p[x] = Find(p[x]);
    return p[x];
}

int main ()
{
    cin >> n >> m;

    for ( int i = 1; i <= n; i++ ) p[i] = i;

    while ( m-- )
    {
        cin >> h >> a >> b;
        if ( h[0] == 'M' ) p[Find(a)] = Find(b); //��a���ڵļ��ϵĸ��ڵ�����b���ڼ��ϵĸ��ڵ����
        else
        {
            if (Find(a) == Find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}