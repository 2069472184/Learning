#include<stdio.h>

void Printout ( unsigned long long N ) ;

void Printdigit ( int result ) ;

int main ( int argc, char argv[] ) 
{
    int long long N;
    scanf( "%lld", &N );
    Printout( N );
    return 0;
}

void Printout ( unsigned long long N )
{
    if ( N>=10 ) {
        Printout ( N/10 ) ;   //�򵥵ݹ�
    }
    Printdigit ( N%10 ) ;   //�˴����ò��ܼ�else��䣬��Ȼ�������if������Ѿ����뵽��һ���Printout������ȥ�ˣ���������һ�㺯������仹��Ҫִ����
}

void Printdigit ( int result ) 
{
    printf( "%d\n", result );
}