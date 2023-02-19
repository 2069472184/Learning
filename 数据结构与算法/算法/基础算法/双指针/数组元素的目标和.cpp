//https://www.acwing.com/problem/content/802/

#include <iostream>
using namespace std;
const int N = 100010;

int n, m, x, La, Lb;
int a[N], b[N];

int main ()
{
    cin >> n >> m >> x;
    
    for ( int i = 1; i <= n; i++ ) scanf( "%d", &a[i] );
    for ( int i = 1; i <= m; i++ ) scanf( "%d", &b[i] );
    
    for ( int i = 1, j = m; i <= n; i++ )
    {
        //��Ŀ�涨����һ����,���Ե���һ�� i = 1 ʱ
        //j�����ܼ���1ʱ���������� a[i] + b[j] <= x 
        //��Ϊ a[1] + b[1] �ĺ�����С��,�ض�С�ڻ����x 
        //����������� j > 0 �������ж�
        while ( a[i] + b[j] > x ) j--;
        
        if ( a[i] + b[j] == x ) 
        {
            cout << i - 1 << ' ' << j - 1;
            return 0;
        }
    }
}