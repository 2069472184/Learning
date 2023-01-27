//https://www.acwing.com/problem/content/732/

//��������
/* #include<stdio.h>
#define N 100010

long n;
long h[N];
long long l, r, mid;

int check ( long long power )
{
    for ( int i = 1; i <= n; i++ )
    {
        power = 2 * power - h[i];   
        if ( power >= 100000 ) return 1;
        if ( power < 0 ) return 0;
    }
    return 1;
}

int main ( int argc, char *argv[] )
{   
    scanf( "%ld", &n );
    for ( int i = 1; i <= n; i++ )  
    {
        scanf( "%ld", &h[i] );
        r += h[i];
    }

    l = 0;
    while ( l < r )
    {
        mid = ( l + r ) / 2 ;
        if ( check( mid ) ) r = mid;
        else l = mid + 1;
    }

    printf( "%ld\n", l );

    return 0;
} */

//����+̰��
//���������Ӻ���ǰ�ƣ�����������������С���0
#include<stdio.h>
#define N 100010

long n, h[N];
long res;

int main ( int argc, char *argv[] ) 
{
    scanf( "%ld", &n );
    for ( int i = 1; i <= n; i++ ) 
        scanf( "%ld", &h[i] );
    
    for ( int i = n; i > 0; i-- )
        res = ( res + h[i] + 1 ) / 2;

    printf( "%ld\n", res );

    return 0;
}