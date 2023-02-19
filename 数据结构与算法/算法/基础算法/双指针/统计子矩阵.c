/*
-------��Ŀ-------
����һ�� N �� M �ľ��� A������ͳ���ж��ٸ��Ӿ��� (��С 1 �� 1����� N �� M) �����Ӿ������������ĺͲ��������������� K??
-------����-------
��һ�а����������� N, M �� K.?
֮�� N ��ÿ�а��� M ��������������� A. 
-------���-------
һ������
-------����-------
���� 100% �����ݣ�1 �� N, M �� 500; 0 �� Aij �� 1000; 1 �� K �� 250000000.
*/

//�����ⷨ43��
/*
#include<stdio.h>

int N, M, A[501][501], i, j;
long count;
long long K;

int sum ( int A[501][501], int x1, int y1, int x2, int y2 )
{
    int i, j;
    long long result = 0;
    for ( i = x1; i <= x2; i++ ) {
        for ( j = y1; j <= y2; j++ ) {
            result += A[i][j];
            if ( result > K ) 
                return 0;
        }
    }
    return 1;
}

int judge ( int a, int b, int A[501][501] )
{
    int i, j, result = 0;
    for ( i = 0; i+a-1 < N; i++ ) {
        for ( j = 0; j+b-1 < M; j++ ) {
            if ( A[i][j] <= K && sum( A, i, j, (i+a-1), (j+b-1) ) ) 
                result++;
        }
    }
    return result;
}

int main ( int argc, char *argv[] )
{   
    scanf( "%d %d %lld", &N, &M, &K );
    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < M; j++ ) 
            scanf( "%d", &A[i][j] );
    }

    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) 
            count += judge( i, j, A );
    }

    printf( "%ld\n", count );
    
    return 0;
}
*/

//��άǰ׺�ͺ�64��
/*
#include<stdio.h>
#define P 502

int sum[P][P], a[P][P]; 
int N, M, i, j;
int x, y;
long result;
long long K;

int main ( int argc, char *argv[] )
{
    scanf( "%d %d %lld", &N, &M, &K );
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) 
            scanf( "%d", &a[i][j] );
    }

    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) 
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
    }

    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) {
            for ( x = 1; x <= N-i+1; x++ ) {
                for ( y = 1; y <= M-j+1; y++ ) {
                    if ( sum[x+i-1][y+j-1] - sum[x+i-1][y-1] - sum[x-1][y+j-1] + sum[x-1][y-1] <= K ) 
                        result++;
                }
            }
        }
    }

    printf( "%d\n", result );

    return 0;
}
*/

//��άǰ׺�͸���forѭ��˳���79��
/*
#include<stdio.h>
#define P 502

int sum[P][P], a[P][P]; 
int N, M, i, j;
int x, y;
long result;
long long K;

int main ( int argc, char *argv[] )
{
    scanf( "%d %d %lld", &N, &M, &K );
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) {
            scanf( "%d", &a[i][j] );
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }

    for ( x = 1; x <= N; x++ ) {   //���������ȱ����Ӿ������Ͻ�λ�ã������ڲ����������״ʱ���ٱ�������
        for ( y = 1; y <= M; y++ ) {
            for ( i = 1; i <= N-x+1; i++ ) {
                for ( j = 1; j <= M-y+1; j++ ) {
                    if ( sum[x+i-1][y+j-1] - sum[x+i-1][y-1] - sum[x-1][y+j-1] + sum[x-1][y-1] <= K ) 
                        result++;
                    else 
                        break;
                }
            }
        }
    }

    printf( "%ld\n", result );

    return 0;
}
*/

//��λǰ׺��+˫ָ���Ż���100��
#include<stdio.h>

int a[505][505];
int N, M;
int i, j;
int r, l;
long long K;
long result;

int main ( int argc, char *argv[] )
{
    scanf( "%d%d%lld", &N, &M, &K );
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) {
            scanf( "%d", &a[i][j] );
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
        }
    }

    for ( i = 1; i <= N; i++ ) {
        for ( j = i; j <= N; j++ ) {
            for ( l = 1, r = 1; r <= M; r++ ) {
                while ( l <= r && a[j][r] - a[j][l-1] - a[i-1][r] + a[i-1][l-1] > K ) l++;
                if ( l <= r ) result += r - l + 1;
            }
        }
    }

    printf( "%ld\n", result );

    return 0;
}

//һάǰ׺��+˫ָ���Ż���100��
//ö�����±߽磬ͨ��˫ָ��ȷ�����ұ߽�
#include<stdio.h>

int a[505][505];
int N, M;
int i, j;
int r, l, sum;
long long K;
long result;

int main ( int argc, char *argv[] ) 
{
    scanf( "%d %d %lld", &N, &M, &K );
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) {
            scanf( "%d", &a[i][j] );
            a[i][j] += a[i-1][j];    //�������е�ǰ׺��(�Ե�һ�е�ÿ��Ԫ��Ϊÿһ�е����)
        }
    }

    for ( i = 1; i <= N; i++ ) {
        for ( j = i; j <= N; j++ ) {
            for ( l = 1, r = 1, sum = 0; r <= M; r++ ) {     //�Ӿ����ұ߽�Ϊr����߽�Ϊl
                sum += a[j][r]-a[i-1][r];           //������������ָ������һ�е�Ԫ�غ�
                while ( sum > K ) {
                    sum -= a[j][l]-a[i-1][l];       //������������ָ������һ�е�Ԫ�غ�
                    l++;
                }
                result += r-l+1;
            }
        }
    }

    printf( "%ld", result );

    return 0;
}