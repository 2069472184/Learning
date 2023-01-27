//https://www.acwing.com/problem/content/1207/

//������޽����������˵a��b�����Լ������1����ֻ�ܴճ�ż�������������У�������涨��������޽�����

//���ȴ���ѣ��ҹ��ɣ�
#include<stdio.h>

int n, m, res;

int dfs ( int i, int n, int m )   //�ж�һ�����Ƿ��ܱ�n��m�������
{
    if ( !i ) return 1;

    //���ǲ�֪����ĳ��Ӧ�ü�n���Ǽ�m�����ԾͶ��о�һ�飬�Ⱥ�˳��û��Ҫ��
    if ( i >= m && dfs( i-m, n, m ) ) return 1;
    if ( i >= n && dfs( i-n, n, m ) ) return 1;   
    
    return 0;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    for ( int i = 1; i <= 1000; i++ )   //��ö�ٵ�1000��1000֮ǰ�н�ͺã�û�н�Ҳ�϶�1000֮���ܴ������
    {                                    
        if (!dfs( i, n, m )) res = i;   //�˴���ʾ1~1000�в��ܱ��������
    }

    printf( "%d\n", res );

    return 0;
}
/*
3 2:1
3 4:5
3 5:7
3 7:11
3 8:13
���֣�mÿ+1��res��+2 -> �������Է��̣�m = 2*n + x����� x = -3.
�Ƴ����� n = 3 ʱ��res = 2*m - 3 = 2*(m-1) - 1.
����n�仯ʱ��m��ϵ���ͻ���Ӧ�ı䣬�ʿ��Բ²� res = (n-1)*(m-1) - 1.
����һ�����ۣ�֤���ο�https://www.acwing.com/solution/content/3165/
*/

//��������
/* 
#include<stdio.h>

int n, m;

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );

    printf( "%d\n", (n-1) * (m-1) - 1 );

    return 0;
} 
 */