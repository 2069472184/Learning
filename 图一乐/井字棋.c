#include<stdio.h>

int main(){
    const int size=3;
    int board[size][size];
    int i,j;
    int numOfX;//   numOfX����1
    int numOfO;//   numOfO����0
    int result=-1;//   -1:û��Ӯ��1:XӮ��0:OӮ

    //�������
    /*for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("�������%d�е�%d�е�����\n",i,j);
            scanf("%d",&board[i][j]);
        }
    }*/  //����ֻ�ܰ����ض�˳���������

    for(int count=1;count<10;count++){
        printf("��ѡ�����������λ��(������ ������)��\n");
        scanf("%d %d",&i,&j);
        printf("������0��1\n");
        scanf("%d",&board[i][j]);
    }//   ���ֿ��Դ�����λ�ö���

    //�����
    for(i=0;i<size&&result==-1;i++){
        numOfO=numOfX=0;
        for(j=0;j<size;j++){
            if(board[i][j]==1){
                numOfX++;
            }else{         
                numOfO++;
            }
        }
        if(numOfO==size){
            result=0;
        }else if(numOfX==size){
            result=1;
        }
    }

    //�����
    if(result==-1){
        for(i=0;i<size&&result==-1;i++){
            numOfO=numOfX=0;
            for(j=0;j<size;j++){
                if(board[i][j]==1){
                    numOfX++;
                }else{
                    numOfO++;
                }
            }
            if(numOfO==size){
                result=0;
            }else if(numOfX==size){
                result=1;
            }
        }
    }

    //������Խ���
    if(result==-1){
        numOfO=numOfX=0;
        for(i=0;i<size;i++){
            if(board[i][j]==1){
                numOfX++;
            }else{
                numOfO++;
            }
        }
        if(numOfO==size){
            result=0;
        }else if(numOfX==size){
            result=1;
        }
    }

    //��鷴�Խ���
    if(result==-1){
        numOfO=numOfX=0;
        for(i=0;i<size;i++){
            if(board[i][size-i-1]==1){
                numOfX++;
            }else{
                numOfO++;
            }
        }
    }

    //������
    if(result==1){
        printf("���XӮ\n");
    }else if(result==0){
        printf("���OӮ\n");
    }else if(result==-1){
        printf("ƽ��\n");
    }
    return 0;
}