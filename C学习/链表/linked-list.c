#include <stdio.h>
#include "node.h"
#include <stdlib.h>

/* typedef struct _node {
    int value;
    struct _node *next;
} Node; */

int main ( int argc, char const *argv[] ) 
{
    Node * head =NULL;  //����һ������ͷ
    int number;
    do {
        scanf("%d", &number);
        if(number!=-1){

            //add to the linked-list
            Node *p=(Node*)malloc(sizeof(Node));  //�����µ�����飬���Ǵ�ʱ��δ��ʹ�ã�ֻ�������������嵥�����ڵģ���Ҫ���õ�ʱ��ͱ�����
            p->value = number;
            p->next = NULL;

            //find the last
            Node *last = head;
            if ( last ) {     //NULL��->����Ч�ģ���last->head��head=NULLʱ����Ч�ģ�����Ҫʵ���������Ƿ�Ϊ������
                while( last->next ) {    //����n������鸳ֵ��n>1��
                    last = last->next;   //����һ�������ΪNULLʱ��last����ͣ����һ����number���������
                }
                //attach
                last->next = p;
            } else {
                head = p;   //��head��ֵΪp��ͬʱ����һ������飨����ʱlast��ָ�Ľṹ�壩��ֵ���������֮��last->next����ΪNULL
            }
            
        }
    } while ( number!=-1 );
    Node *result = head;
    while ( result ) {
        printf( "%d\n", result->value );
        result = result->next;
    }
    return 0;
}