#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*�����ַ���������ת���������ַ���ǰ������ɸ��ַ��ƶ����ַ�����β����
����ַ��� abcdef ����ת 2 λ�õ��ַ��� cdefab��
��ʵ���ַ�������ת�ĺ�����Ҫ��Գ���Ϊ n ���ַ���������ʱ�临�Ӷ�Ϊ
O(n)���ռ临�Ӷ�Ϊ O(1)��*/

void reverse_str(int head, int tail, char *data)
{
    int i = head;
    int j = tail;
    char temp;

    while(i < j)
    {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char data[20] = "cdregrtqvbr";
    int str_len;

    printf("%s\n", data);
    str_len = strlen(data);

    reverse_str(0, 2, data);
    reverse_str(3, str_len - 1, data);
    reverse_str(0, str_len - 1, data);
    printf("%s\n", data);
    printf("Hello world!\n");
    return 0;
}
