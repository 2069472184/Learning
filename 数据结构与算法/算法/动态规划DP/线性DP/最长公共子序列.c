//https://www.acwing.com/problem/content/899/

//����dp
/*
״̬��ʾ��dp[i][j]��ʾ������a[1]~a[i]��b[1]~b[j]��Χ�ڵĹ��������еĳ��ȵļ��ϣ�������max
״̬���֣�
    1.ѡa[i]����ѡb[j]��dp[i][j] = dp[i][j-1]
    2.ѡa[i]��b[j]����� a[i] == b[i], �� d[i][j] = d[i-1][j-1] + 1
    3.��ѡa[i]��ѡb[j]��dp[i][j] = dp[i-1][j]
    4.����ѡ��dp[i][j] = dp[i-1][j-1]      
    ���������1�У�dp[i][j-1] �ְ���ѡ a[i] ��ѡ a[i] �������
    ������ж��ظ������Ǳ���Ҫ��max���ظ�����Խ�����Ӱ��.���3Ҳ������
    ����ͨ���۲췢�֣����4�ֱ����������3�����1�У��ʿ���ʡ�Ե����4������
    �������4������2С1�����Կ���ֱ��ʡ��
*/
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, m;
char a[N], b[N];
int dp[N][N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );
    getchar();
    gets(a+1);
    gets(b+1);

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            if ( a[i] == b[j] ) dp[i][j] = max( dp[i][j], dp[i-1][j-1] + 1 );
        }

    printf( "%d\n", dp[n][m] );

    return 0;
}

//���˵Ҫ���������ȵ�ͬʱ�����������������أ�
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, m;
char a[N], b[N], ans[N];
int dp[N][N];

char *specific ( char *ans, char *a, char *b )
{
    int i = n, j = m;
    int k = dp[n][m];

    while ( k )
    {
        if ( dp[i][j] == dp[i-1][j] ) i--;  //��ѡa[i]��ѡb[i]
        else if ( dp[i][j] == dp[i][j-1] ) j--;  //��ѡb[i]��ѡa[i]
        else   //��ѡ����������ܶ����ַ�
        {
            ans[--k] = a[i];
            i--;
            j--;
        }
    } 

    return ans;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d%s%s", &n, &m, a+1, b+1 );

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            if ( a[i] == b[j] ) dp[i][j] = max( dp[i][j], dp[i-1][j-1] + 1 );
        }

    printf( "%d\n", dp[n][m] );
    printf( "%s\n", specific( ans, a, b ) );    

    return 0;
}