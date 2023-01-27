//https://www.acwing.com/problem/content/1052/

//dfs����
#include<stdio.h>

int t, m, n, res;

void dfs ( int power, int max, int number )
{
    if ( number < 0 ) 
    {
        if ( max == 0 ) res++;
        return;
    }

    for ( int i = power; i <= max; i++ ) 
        dfs( i, max-power, number-1 );

    return;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        dfs(0, m, n);

        printf( "%d\n", res );

        res = 0;
    } 

    return 0;
}

//dp�Ż�����һ��˼��
//�����ȫ����--���������֡�
/*
״̬��ʾ��
    ���϶��壺����dp[i][j]�ļ��ϰ��������ܺ���i���ҷֳ�j������ĵķ���
    �������ԣ�����
״̬���㣺
    ״̬���֣���Ϊ��СֵΪ0�Ͳ�Ϊ0����
        1.��СֵΪ0������������������з����ж���һ��0��ȥ����0֮�󷽰������䣺dp[i][j] = dp[i][j-1]
        2.��Сֵ��Ϊ0���������з���ͬʱ��ȥ1���õ��ķ���dp��ʾΪdp[i-j][j]
*/
#include<stdio.h>
#include<string.h>

int t, m, n, ans;
int dp[15][15];

int main ( int argc, char *argv[] ) 
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        dp[0][0] = 1;
        for ( int i = 0; i <= m; i++ )  //��Ϊÿ�����������������0������i��0��ʼö��
            for ( int j = 1; j <= n; j++ )
            {
                dp[i][j] = dp[i][j-1];
                if ( j <= i ) dp[i][j] += dp[i-j][j];
            }

        printf( "%d\n", dp[m][n] );

        memset( dp, 0, sizeof(dp) );
    }
    return 0;
}

//��ȫ����dp
/*
״̬��ʾ��dp[i][j][k]��ʾ���д�����ֵΪ 0 ~ i �ķ�����ѡ������������Ϊ j ���� k ������ķ����ļ���
״̬���֣�
    1.��ѡ����ֵΪ i �ķ���dp[i][j][k] += dp[i-1][j][k].
    2.ѡu������ֵΪ i �ķ���dp[i][j][k] += dp[i][j-u*i][k-u].
*/
//����д��
#include<stdio.h>
#include<string.h>

int t, n, m;
int dp[15][15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        //�����ʼ������
        /*ֻѡ0�������ķ�������һֱѡ���� n-1 ��������Щ����1�ַ���
        ������Ȱ�ֻѡ0�������ķ�������ȫ�����۵�������Ҫ�ں��潫i��0
        ��ʼ���ۣ�i = 0 ʱ����ָ��±�*/
        for ( int i = 0; i < n; i++ ) dp[0][0][i] = 1;
        
        for ( int  i = 1; i <= m; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k <= n; k++ )
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    for ( int u = 1; u*i <= j && u <= k; u++ )
                        dp[i][j][k] += dp[i-1][j-u*i][k-u];
                }
            
        printf( "%d\n", dp[m][m][n] );

        memset( dp, 0, sizeof(dp) );
    }

    return 0;
}

//uѭ���Ż�
//dp[i][j][k] = dp[i-1][j][k] + dp[i][j-i][k-1] ע������Ҫ���� j >= i 
#include<stdio.h>
#include<string.h>

int t, n, m;
int dp[15][15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        for ( int i = 0; i < n; i++ ) dp[0][0][i] = 1;
        
        for ( int  i = 1; i <= m; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k <= n; k++ )
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    if ( j >= i && k > 0 ) 
                        dp[i][j][k] = dp[i-1][j][k] + dp[i][j-i][k-1];
                }
            
        printf( "%d\n", dp[m][m][n] );

        memset( dp, 0, sizeof(dp) );
    }

    return 0;
}

//iѭ���Ż�
//˼·
#include<stdio.h>
#include<string.h>

int t, n, m;
int dp[15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        for ( int i = 0; i < n; i++ ) dp[0][i] = 1;
        
        for ( int  i = 1; i <= m; i++ )
            for ( int j = 0; j <= m; j++ )
                for ( int k = 0; k <= n; k++ )
                {
                    //��ѡ������ʡ��
                    dp[j][k] = dp[j][k];
                    //dp[i][j][k] = dp[i-1][j][k];

                    //ѡ
                    if ( j >= i && k > 0 ) 
                        dp[j][k] = dp[j][k] + dp[j-i][k-1];   
                        //dp[i][j][k] = dp[i-1][j][k] + dp[i][j-i][k-1];
                        //�˴�Ҫ����õ���ǰiѭ�������ݣ�����j�Ǵ�С�������
                }
            
        printf( "%d\n", dp[m][n] );

        memset( dp, 0, sizeof(dp) );
    }

    return 0;
}

//���ս��
#include<stdio.h>
#include<string.h>

int t, n, m;
int dp[15][15];

int main ( int argc, char *argv[] )
{
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d%d", &m, &n );

        for ( int i = 0; i < n; i++ ) dp[0][i] = 1;
        
        for ( int  i = 1; i <= m; i++ )
            for ( int j = i; j <= m; j++ )
                for ( int k = 1; k <= n; k++ )
                    dp[j][k] = dp[j][k] + dp[j-i][k-1];
            
        printf( "%d\n", dp[m][n] );

        memset( dp, 0, sizeof(dp) );
    }

    return 0;
}