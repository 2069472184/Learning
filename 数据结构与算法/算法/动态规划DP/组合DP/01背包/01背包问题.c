//https://www.acwing.com/problem/content/2/

//�������Ϸ�����(��������)
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, num, v[N], w[N];
int dp[N][N];  
//dp[i][j]��ʾ��ǰi����Ʒ��ѡ���������������j�����з����ļ������ܼ�ֵ�������
//dp����ļ����Ϊ���࣬һ���ǲ�ѡ��i����Ʒ����ʱdp[i][j] = dp[i-1][j]��
//�ڶ�����ѡ��i����Ʒ����ʱ����Ҫ��֤ǰ��i-1����Ʒ�ļ�ֵ��󣬼�dp[i-1][j-v[i]]���Ȼ���ټ��ϲ����w[i]
//���ձ�ʾΪ��dp[i][j] = dp[i-1][j-v[i]] + w[i].

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &num );
    for ( int i = 1; i <= n; i++ )
        scanf( "%d%d", &v[i], &w[i] );

    for ( int i = 1; i <= n; i++ )
        for ( int j = 0; j <= num; j++ )
        {
            //��ѡ��i����Ʒ���������ȣ��Ա����ȡ������������ֵ
            dp[i][j] = dp[i-1][j];

            //ѡ��i����Ʒ����ȡѡ��ѡ������������ֵ
            if ( j >= v[i] ) dp[i][j] = max( dp[i][j], dp[i-1][j-v[i]] + w[i] );
        }

    printf( "%d\n", dp[n][num] );
    
    return 0;
} 

//һάdp�����Ż�
//����dp�Ż����Ǵ���ĵȼ��滻
//����˼·
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, num, v[N], w[N];
int dp[N];  //��������

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &num );
    for ( int i = 1; i <= n; i++ )
        scanf( "%d%d", &v[i], &w[i] );

    /*j��Ҫ�Ӵ�С��������Ϊʡ�Ե�����dp[i-1][j-v[i]]���õ�������һ���ֵ
    ������dp[j]��ʱ��j-v[i]�϶���jС���ʶ��Ӵ�С�����ܹ���֤��i��ѭ���õ���һ���ǻ�δ�����¹������ݣ���ǰ��һ��ѭ�������ݣ�
    ���j��С����������п��ܳ���j�±���ͬ����������ǵ���i-1�����ȷֵ��
    ���磺j = k ʱ j - v[i] ǡ�õ��� j = n (n < k) ʱ�� j ,��ô j = n ʱ��max�������൱�ڰѵ�i-1��� j = n ��������ǵ���
    �� j = k ʱ�����õ����ǵ�i���ֵ������Ȼ�Ǵ����*/
    for ( int i = 1; i <= n; i++ )
        for ( int j = num; j >= 0; j-- )   
        {
            //dp[j] = dp[j];   //��ѡ��i����Ʒ�����������ʡ��
            //dp[i][j] = dp[i-1][j];

            if ( j >= v[i] )    //ѡ��i����Ʒ�����
                dp[j] = max( dp[j], dp[j-v[i]] + w[i] );
                //dp[i][j] = max( dp[i][j], dp[i-1][j-v[i]] + w[i] );
        }

    return 0;
}

//�������
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 1010

int n, num, v[N], w[N];
int dp[N];

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &num );
    for ( int i = 1; i <= n; i++ )
        scanf( "%d%d", &v[i], &w[i] );

    for ( int i = 1; i <= n; i++ )
        for ( int j = num; j >= v[i]; j-- )
            dp[j] = max( dp[j], dp[j-v[i]] + w[i] );
    
    printf( "%d\n", dp[num] );

    return 0;
}