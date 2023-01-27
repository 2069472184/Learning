//https://www.acwing.com/problem/content/1214/

/*
��Ŀ���ʣ�
1.һ��Ҫ�Ե�����˳��ȡ��Ʒ����ֵ��С�������У�
2.��ʼ���Ϊdp[1][1][0][-1] = 1(��Ʒ�ļ�ֵ���Ե���0),dp[1][1][1][c[1][1]] = 1.

���϶��壺
dp[i][j][k][w]�����ߵ�(i, j)�㣬��ȡ��k����Ʒ�������һ����Ʒ�ļ�ֵ��w�����з����ļ���
�������ԣ�count
״̬���㣺
��Ϊ���࣬ע��״̬ת�Ƶ�ʱ��Ҫȫ����������������ǰ�漸��һ��ȡmax
���һ�������ߵ�(i, j)��
    1.��ȡ dp[i][j][k][w] = ( dp[i][j][k][w] + dp[i-1][j][k][w] ) % mod;   
    2.ȡ  ������Ҫ����c[i][j] == w��ǰһ����ֵ�����Ǵ�С��w������һ����ֵ
          ������Ҫѭ��һ�飬��ÿһ������ķ�����������    
          dp[i][j][k][w] = ( dp[i][j][k][w] + dp[i-1][j][w-1][c] ) % mod;   1 <= c <= һ��������������Ʒ��ֵ�����ֵ;
���һ�������ߵ�(i, j)���ǽ�i-1����j-1
*/

//��άdp
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 55
#define mod 1000000007

int n, m, k, maxc, res;
int c[N][N], dp[N][N][13][14];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d%d", &n, &m, &k );

    for ( int i = 1; i <= n; i++ )
        for ( int  j = 1; j <= m; j++ )
        {
            scanf( "%d", &c[i][j] );
            c[i][j]++;
            maxc = max( maxc, c[i][j] );
        }

    dp[1][1][0][0] = 1;
    dp[1][1][1][c[1][1]] = 1;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            for ( int u = 0; u <= k; u++ )
                for ( int w = 0; w <= maxc; w++ )   //w=0��ʾû���κ���Ʒ��������Ʒ��ֵΪ0
                {
                    //��ȡ
                    dp[i][j][u][w] = ( dp[i][j][u][w] + dp[i][j-1][u][w] ) % mod;
                    dp[i][j][u][w] = ( dp[i][j][u][w] + dp[i-1][j][u][w] ) % mod;
                    //ȡ
                    if ( u > 0 && c[i][j] == w ) 
                    {
                        for ( int c = 0; c < w; c++ )
                        {
                            dp[i][j][u][w] = ( dp[i][j][u][w] + dp[i][j-1][u-1][c] ) % mod;
                            dp[i][j][u][w] = ( dp[i][j][u][w] + dp[i-1][j][u-1][c] ) % mod;
                        }
                    }
                }
    
    for ( int i = 1; i <= maxc; i++ ) res = ( res + dp[n][m][k][i] ) % mod;

    printf( "%d\n", res );

    return 0;
}