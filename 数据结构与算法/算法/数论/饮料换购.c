//https://www.acwing.com/problem/content/1218/

#include<stdio.h>

int n, res;

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    res = n;
    while ( n > 2 )
    {
        res += n/3;
        n -= n/3 * 2;   //ע����߳�����������*2ǰ���
    }

    printf( "%d\n", res );

    return 0;
}