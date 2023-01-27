//https://www.acwing.com/problem/content/1232/

//ֱ����ģ��ᳬʱ
/*
#include<stdio.h>

long n, k, a[100010], count, i, j;

int main ( int argc, char *argv[] )
{
    scanf( "%ld%ld", &n, &k );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%ld", &a[i] );
        a[i] += a[i-1];
    }

    for ( i = 1; i <= n; i++ ) 
        for ( j = i; j <= n; j++ ) 
            if ( (a[j]-a[i-1]) % k == 0 ) 
                count++;

    printf( "%ld\n", count );

    return 0;
}
*/

//���
//�½�һ�����飬�±�洢ÿ��ǰ׺����k��ģ
#include<stdio.h>

long a[100010];
long n, k, i;
long ans[100010];

int main ( int argc, char *argv[] ) 
{
    scanf( "%ld %ld", &n, &k );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%ld", &a[i] );
        a[i] += a[i-1];
    }

    ans[0]++;   
    //�˴���Ҫ���Ȱ�����Ϊ0�������Ϊ1��
    //��Ϊ�������Ϊ0��˵����ǰ׺���������һ��k�����䣬������������Ķ˵�.
    long count = 0;
    for ( i = 1; i <= n; i++ ) {
        count += ans[ a[i] % k ];
        ans[ a[i] % k ]++;
    }

    printf( "%ld\n", count );

    return 0;
}

