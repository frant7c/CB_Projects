#include <stdio.h>
#include <stdlib.h>
#include "../LBLsContainer/LBLsContainer.h"

/*����һ�������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ���
�֡�
Ҫ��ʱ�临�Ӷ��� O(n)������ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
������������ 1��2��4��7��11��15 ������ 15������ 4+11=15�������� 4 �� 11��*/
int find_sum(int *data, int data_size, int sum)
{
    HashTable *hash_table;
    HashElement *hash_elem;
    int i, j;
    int *ai;
    int bi;
    int half_cnt;

    /*aiΪ�����е�i��Ԫ�أ�bi=sum-ai����ϣ��洢bi��ai��ӳ���ϵ*/
    hash_table = hash_table_init(data_size);

    for(i = 0; i < data_size; i++)
    {
        ai = (int *)malloc(sizeof(int));
        *ai = data[i];
        bi = sum - data[i];
        hash_elem = (HashElement *)malloc(sizeof(HashElement));
        hash_elem->data = (void *)ai;
        hash_elem->key = bi;
        hash_elem->next = NULL;
        hash_elem->value = bi;
        hash_insert(hash_table, data_size, hash_elem);
    }

    for(i = 0; i < data_size; i++)
    {
        ai = (int *)hash_find(hash_table, data_size, data[i], data[i]);
        if(ai != NULL)
        {
            if(*ai * 2 != sum)
            {
                printf("Found!\n%d + %d = %d", data[i], *ai, sum);
                return 0;
            }
            else
            {
                /*����ai*2=sum����������ϣ����ܹ��˵��ظ���Ԫ�أ������Ҫ�������飬��������ai����ai*2=sum���ҵ���*/
                half_cnt = 1;
                for(j = 0; j < data_size; j++)
                {
                    if(data[j] == *ai)
                    {
                        if(half_cnt == 2)
                        {
                            printf("Found!\n%d + %d = %d", *ai, *ai, sum);
                            return 0;
                        }
                        else
                        {
                            half_cnt++;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    FILE *file;
    int data[10];
    int i, j;

    file = fopen("data.txt", "r+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return 0;
    }

    i = 0;
    while(!feof(file))
    {
        fscanf(file, "%d ", &data[i++]);
    }
    fclose(file);

    printf("Original sequence:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    find_sum(data, 10, 16);
    return 0;
}
