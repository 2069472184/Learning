//https://www.acwing.com/problem/content/description/904/

//����dp
/*
״̬��ʾ��dp[i][j]��ʾ���н��ַ���a[1~i]���b[1~j]�ķ����Ĳ������ļ��ϣ�������min
״̬���֣���ͼ��ͼ��ͼ
    1.a[i]��ɾ����dp[i][j] = min( dp[i-1][j] + 1, dp[i][j] );
    2.a[i]�ǲ���ģ�dp[i][j] = min( dp[i][j-1] + 1, dp[i][j] );
    3.a[i]�Ǳ��滻�ģ�
        ���a[i] == b[j], dp[i][j] = min( dp[i-1][j-1], dp[i][j] );
        ���a[i] != b[j], dp[i][j] = min( dp[i-1][j-1] + 1, dp[i][j] );
*/
#include <stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define N 1010

int n, m;
char a[N], b[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%s", &n, a+1 );
    getchar();
    scanf( "%d%s", &m, b+1 );
    
    //���ǵ�֮����õ��±�Ϊ0�������������Ҫ��ʼ��
    //�����Ҫ��a��ǰi����ĸ��b��ǰ0����ĸƥ�䣬��ֻ����ɾ�������Ҳ�����Ϊi
    for ( int i = 0; i <= n; i++ ) dp[i][0] = i;
    //�����Ҫ��a��ǰ0����ĸ��b��ǰi����ĸƥ�䣬��ֻ������Ӳ����Ҳ�����Ϊi
    for ( int i = 0; i <= m; i++ ) dp[0][i] = i;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            dp[i][j] = min( dp[i-1][j] + 1, dp[i][j-1] + 1 );
            if ( a[i] == b[j] ) dp[i][j] = min( dp[i][j], dp[i-1][j-1] );
            else dp[i][j] = min( dp[i][j], dp[i-1][j-1] + 1 );  
        }

    printf( "%d\n", dp[n][m] );

    return 0;
}