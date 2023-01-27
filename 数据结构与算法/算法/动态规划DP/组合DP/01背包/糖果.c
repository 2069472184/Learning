//https://www.acwing.com/problem/content/1049/

//����DP
/*
״̬��dp[i][j]��ʾ�������㡰��ǰi����Ʒ��ѡ�����ǹ�����Ŀn%k=j���ķ����������ǹ���Ŀ
״̬���㣺
1.ѡ��1����Ʒ��
    �����з����ֳ������֣�һ������w[i]��һ������dp[i-1][( ( j - w[i] ) % k + k ) % k]
    �Ƶ����̣�����һ���ֵ��ǹ�����s���� (s + w[i]) % k = j���� s + w[i] = j + n*k��
    �����ȡ��ģ���� s % k = ((j - w[i]) % k + k) % k + 0.
2.��ѡ��1����Ʒ��dp[i][j] = dp[i-1][j]
*/
#include<stdio.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define null -0x3f3f3f3f
#define N 105

int n, k, maxW, w[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &k );
    for ( int i = 1; i <= n; i++ ) scanf( "%d", &w[i] );

    //��Ҫ�������ʼ��Ϊ����С,��Ϊdp[0][i]֮��������
    //memset( dp, -0x3f, sizeof(dp) );   
    for ( int i = 1; i < k; i++ ) dp[0][i] = null;
    dp[0][0] = 0;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j < k; j++ )
            dp[i][j] = max( dp[i-1][j], dp[i-1][( ( j - w[i] ) % k + k ) % k] + w[i] );

    printf( "%d\n", dp[n][0] );

    return 0;
}