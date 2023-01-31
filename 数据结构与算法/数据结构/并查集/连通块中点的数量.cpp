//https://www.acwing.com/problem/content/839/

#include <iostream>
using namespace std;

const int N = 100010;

//size����ά��ÿ��������Ԫ�ص�����
int n, m, p[N], Size[N];
string h;
int a, b;

int Find ( int x )
{
    if ( p[x] != x ) p[x] = Find(p[x]);
    return p[x];
}

int main ()
{
    cin >> n >> m;

    for ( int i = 1; i <= n; i++ ) p[i] = i, Size[i] = 1;

    while ( m-- )
    {
        cin >> h;
        if ( h[0] == 'C' ) 
        {
            cin >> a >> b;
            //�˴���һ�����У�����a��b�Ѿ���һ����ͨ���ڣ��ǾͲ���Ҫ֮��Ĳ���
            if ( Find(a) == Find(b) ) continue;
            //����b���ڼ��ϵ�size
            Size[Find(b)] += Size[Find(a)];
            //����a��b���ڼ���
            p[Find(a)] = Find(b); 
        }
        else if ( h[1] == '1' )
        {
            cin >> a >> b;
            if (Find(a) == Find(b)) puts("Yes");
            else puts("No");
        }
        else 
        {
            cin >> a;
            cout << Size[Find(a)] << endl;;
        }
    }

    return 0;
}