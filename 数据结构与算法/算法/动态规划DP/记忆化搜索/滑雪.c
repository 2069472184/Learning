//https://www.acwing.com/problem/content/903/

//���仯����

//�����·�������������ģ�����˵�ѱ�������ĵ��ֵ��СΪ1
//�����轫���е��ֵ��ʼ��Ϊ-1

/*
״̬��ʾ��dp[i][j]��ʾ���д�(i,j)��ʼ����·�ߵĳ��ȵļ��ϣ�������max
״̬���㣺
    ���������������޹������еģ����Կ��ܳ���ĳ��ֵ���õ���ʱ��δ��������������Ա����õ�DP�����ĵݹ�
    �������Ļ���������ƫ�������
*/
#include <stdio.h>
#define max(c,d) ((c)>(d)?(c):(d))
#define N 305

int r, c, h[N][N], ans;
int dp[N][N];

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };  //�������ҷֱ������ϣ����ң����£�����

int DP ( int x, int y )
{
    //��ֹ�ظ�������ͬλ�õ�·�����ֵ�����͸��Ӷ�
    if ( dp[x][y] ) return dp[x][y];  //���dp[x][y]��Ϊ0��˵���Ѿ����������

    //��ʼ��Ҫ�����λ�õ�ֵ��һ��ʼ����һ����λ����
    dp[x][y] = 1;
    for ( int i = 0; i <= 3; i++ )
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if ( a >= 1 && a <= r && b >= 1 && b <= c && h[x][y] > h[a][b] )
            dp[x][y] = max( dp[x][y], DP(a, b) + 1 );
    }

    return dp[x][y];
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &r, &c );
    for ( int i = 1; i <= r; i++ )
        for ( int j = 1; j <= c; j++ )  
            scanf( "%d", &h[i][j] );

    for ( int i = 1; i <= r; i++ )
        for ( int j = 1; j <= c; j++ )
            ans = max( ans, DP(i, j) );

    printf( "%d\n", ans );

    return 0;
}