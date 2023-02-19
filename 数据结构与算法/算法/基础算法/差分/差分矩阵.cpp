//https://www.acwing.com/problem/content/800/

//b[i][j]��Ӧ��a����ı仯��ϵ����ά��������������a[i][j]Ϊ��b[1][1]Ϊ���Ͻǣ���b[i][j]Ϊ���½ǵ��Ӿ���
//���������ٷ���a��ֵʱֻ��Ҫ�ö�άǰ׺�͹�ʽ

//����,������ά��ֵĹ��̶����ڶԲ������������,ֻ��ʱ�̼ǵò������Ķ�άǰ׺����a���鼴��
//��Ŀ�е�"��a����ĳ����Χ�ڵ�Ԫ�ؼӼ�c"��ʵ�Ϳ������Ϊb����ĸı�
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1010;

int n, m, q;
int a[N][N], b[N][N];

void insert ( int x1, int y1, int x2, int y2, int c )
{
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main ()
{
    cin >> n >> m >> q;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            scanf( "%d", &a[i][j] );

    //����һ��a����,���ò�ֵķ�ʽ������b����,
    //����ͬʱ��ʼ��a����Ҳ����b�����άǰ׺�͵ķ�ʽ��������
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            insert( i, j, i, j, a[i][j] );

    while ( q-- )
    {
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            //��ʱb�������һ��ǰ׺�����飬������Ҫ��b������b[1][1]Ϊ���Ͻǣ�
            //��b[i][j]Ϊ���½ǵ��Ӿ���ĺͣ�����;���a[i][j]
            b[i][j] += b[i - 1][j] + b[i][j - 1] + a[i - 1][j - 1];

    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
            cout << a[i][j] << ' ';
        puts("");
    }

    return 0;
}