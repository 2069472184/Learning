#include <iostream>

using namespace std;

int main ()
{
    int n; 

    while (scanf("%d", &n) != EOF)
    {
        int num[100000] = {0};

        num[0] = 1, num[1] = 1;

        //i��ʾ 2 �� n ֮�����
        for (int i = 2; i <= n; i++)
        {
            int tem = 0;
            //�ڵ�ǰ���޵Ĵ洢�����ڴ洢�˻�
            for (int j = 1; j <= num[0]; j++)
            {
                num[j] = num[j] * i + tem;
                tem = num[j] / 10;
                num[j] %= 10; 
            }

            //����н�λ������չ����Ĵ洢����
            //ע�⣬�˴���һ��ֻ��չһλ
            while (tem)
            {
                num[0]++;
                num[num[0]] = tem % 10;
                tem /= 10;
            }
        }

        for (int i = num[0]; i >= 1; i--) cout << num[i];
        puts("");
    }

    return 0;
}