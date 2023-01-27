//https://www.acwing.com/problem/content/9/

//���鱳��dp---���ֳɺö��飬ÿ�����и�����ͬ����Ʒ����ֻ�ܴ�ÿ����ȡһ����Ʒ
/*
״̬��ʾ��dp[i][j]��ʾ��ǰi����ѡ���������<=j�����з����ܼ�ֵ�ļ��ϣ�����Ϊmax
״̬���֣�
    1.��i����Ʒ��ѡ��dp[i][j] = dp[i-1][j]
    2.��i����Ʒѡ��k����dp[i][j] = max( dp[i][j], dp[i-1][j-v[i][k]] + w[i][k] )

*/
//�����㷨
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 105

int n, V, s[N], v[N][N], w[N][N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d", &s[i] );
        for ( int j = 1; j <= s[i]; j++ ) 
            scanf( "%d%d", &v[i][j], &w[i][j] );
    }

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= V; j++ )
            for ( int k = 0; k <= s[i]; k++ )
                if ( j >= v[i][k] )   //�˴����жϲ���д��forѭ�����棬��Ϊv������Ԫ��ֵ���ǵ������е�
                    dp[i][j] = max( dp[i][j], dp[i-1][j-v[i][k]] + w[i][k] );

    printf( "%d\n", dp[n][V] );

    return 0;
}

//��άתһά�Ż�
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 105

int n, V, s[N], v[N][N], w[N][N];
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &V );
    for ( int i = 1; i <= n; i++ )
    {
        scanf( "%d", &s[i] );
        for ( int j = 1; j <= s[i]; j++ ) 
            scanf( "%d%d", &v[i][j], &w[i][j] );
    }

    for ( int i = 1; i <= n; i++ )
        for ( int j = V; j >= 0; j-- )
            for ( int k = 0; k <= s[i] ; k++ )
                if ( j >= v[i][k] ) dp[j] = max( dp[j], dp[j-v[i][k]] + w[i][k] );

    printf( "%d\n", dp[V] );

    return 0;
}