#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LBLsContainer.h"

#define MAX_CHAR 256

#define MAX(x, y) (x) > (y) ? (x) : (y)

int queue_init(queue *fifo, int len, int max_element)
{
    fifo->data = (void *)malloc(len);
    if(NULL == fifo->data)
    {
        return -1;
    }
    fifo->max_element = max_element;
    fifo->head = 0;
    fifo->tail = 0;
    return 0;
}

int enqueue(queue *fifo, void *data, int element_size)
{
    int head = fifo->head;
    int tail = fifo->tail;
    int max_element = fifo->max_element;
    char *dest;
    char *src;
    int i;

    /*�ж϶����Ƿ�����*/
    if(((tail+1) % max_element) == head)
    {
        printf("Queue is full!\n");
        return -1;
    }
    else
    {
        tail = (tail+1) % max_element;
        dest = (char *)fifo->data + tail * element_size;
        src = (char *)data;
        for(i = 0; i < element_size; i++)
        {
            *dest = *src;
            dest++;
            src++;
        }
        fifo->tail = tail;
    }
    printf("en: %d %d\n", fifo->head, fifo->tail);
    return 0;
}

int dequeue(queue *fifo, void *data, int element_size)
{
    int head = fifo->head;
    int tail = fifo->tail;
    int max_element = fifo->max_element;
    char *dest;
    char *src;
    int i;

    /*�ж϶����Ƿ�Ϊ��*/
    if(head == tail)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        head = (head+1) % max_element;
        src = (char *)fifo->data + head * element_size;
        dest = (char *)data;
        for(i = 0; i < element_size; i++)
        {
            *dest = *src;
            dest++;
            src++;
        }
        fifo->head = head;
    }
    printf("de: %d %d\n", fifo->head, fifo->tail);
    return 0;
}

int stack_init(stack *filo, int len, int max_element)
{
    filo->data = (void *)malloc(len);
    if(NULL == filo->data)
    {
        return -1;
    }
    filo->max_element = max_element;
    filo->top = 0;
    filo->bottom = 0;
    return 0;
}

int stack_push(stack *filo, void *data, int element_size)
{
    int top = filo->top;
    int max_element = filo->max_element;
    char *dest;
    char *src;
    int i;

    /*�ж�ջ�Ƿ�����*/
    if(top + 1 == max_element)
    {
        printf("Stack is full!\n");
        return -1;
    }
    else
    {
        dest = (char *)filo->data + top * element_size;
        src = (char *)data;
        for(i = 0; i < element_size; i++)
        {
            *dest = *src;
            dest++;
            src++;
        }
        filo->top++;
    }
    printf("pu: %d\n", filo->top);
    return 0;
}

int stack_pop(stack *filo, void *data, int element_size)
{
    int top = filo->top;
    int bottom = filo->bottom;
    char *dest;
    char *src;
    int i;

    /*�ж�ջ�Ƿ��*/
    if(top == bottom)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        top--;
        dest = (char *)data;
        src = (char *)filo->data + top * element_size;
        for(i = 0; i < element_size; i++)
        {
            *dest = *src;
            dest++;
            src++;
        }
        filo->top--;
    }
    printf("po: %d\n", filo->top);
    return 0;
}

HashTable * hash_table_init(int table_size)
{
    int i;
    HashTable *hash_table;

    hash_table = (HashTable *)malloc(table_size * sizeof(HashTable));
    if(NULL == hash_table)
    {
        printf("error!!\n");
        return NULL;
    }

    for(i = 0; i < table_size; i++)
    {
        hash_table[i].next = NULL;
    }
    return hash_table;
}

void * hash_find(HashTable hash_table[], int table_size, int key, int value)
{
    unsigned int index = (key * 2654435769) % table_size;
    HashElement * cur_elem;

    cur_elem = hash_table[index].next;
    while(cur_elem != NULL)
    {
        if(cur_elem->value == value)
        {
            return cur_elem->data;
        }
        cur_elem = cur_elem->next;
    }
    return NULL;
}

int hash_insert(HashTable hash_table[], int table_size, HashElement *element)
{
    unsigned int index = ((unsigned int)element->key * (unsigned int)2654435769) % table_size;
    HashElement * cur_elem;
    HashElement * last_elem;

    //printf("index = %d\n", index);

    if(NULL == hash_table[index].next)
    {
        hash_table[index].next = element;
        return 0;
    }

    cur_elem = hash_table[index].next;
    while(cur_elem != NULL)
    {
        if(cur_elem->value == element->value)
        {
            printf("Element already exists!\n");
            return 0;
        }
        last_elem = cur_elem;
        cur_elem = cur_elem->next;
    }
    element->next = NULL;
    last_elem->next = element;
    return 0;
}

void quick_sort(QuickSortElem *data, int head, int tail)
{
    int base = data[head].key;
    void *base_data = data[head].data;
    int i = head;
    int j = tail;
    if(head < tail)
    {
        do
        {
            while((i < j)&&(data[j].key > base))
            {
                j--;
            }
            if(i < j)
            {
                data[i].key = data[j].key;
                data[i].data = data[j].data;
                i++;
            }
            while((i < j)&&data[i].key < base)
            {
                i++;
            }
            if(i < j)
            {
                data[j].key = data[i].key;
                data[j].data = data[i].data;
                j--;
            }
        }while(i < j);

        data[i].key = base;
        data[i].data = base_data;
        quick_sort(data, head, i-1);
        quick_sort(data, i+1, tail);
    }
}

void get_next(const char *sub_str, int sub_str_cnt, int *next)
{
    int i = 0;
    int j = -1;

    next[0] = -1;

    while(i < sub_str_cnt)
    {
        if(j == -1 || sub_str[i] == sub_str[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int kmp_str_search(const char *main_str, const char *sub_str, int main_str_cnt, int sub_str_cnt)
{
    int *next;
    int i, j;
    int step = 1;

    next = (int *)malloc(sub_str_cnt * sizeof(int));
    get_next(sub_str, sub_str_cnt, next);

    i = 0;
    j = 0;
    while(i < main_str_cnt)
    {
        if(j == -1 || main_str[i] == sub_str[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
            printf("step%d: i: %d j: %d\n", step++, i, j);
        }
        if(j >= sub_str_cnt)
        {
            return i - j;
        }
    }
    return -1;
}

/*bad_last_pos�洢���ַ����ұ������һ�γ��ֵ�λ�ã�sub_str_cnt��ʾ���ַ�����ģʽ���У�����������ģʽ��*/
void bm_bad(const char *sub_str, int sub_str_cnt, int bad_last_pos[MAX_CHAR])
{
    int i;

    for(i = 0; i < MAX_CHAR; i++)
    {
        bad_last_pos[i] = -1;
    }

    for(i = 0; i < sub_str_cnt; i++)
    {
        bad_last_pos[(int)sub_str[i]] = i;
    }
}

/*
�ڼ���bmGc����ʱ��Ϊ���Ч�ʣ��ȼ��㸨������suff[]��ʾ�ú�׺�ĳ��ȡ�
suff����Ķ��壺m��pattern�ĳ���
a. suffix[sub_str_cnt-1] = sub_str_cnt;
b. suffix[i] = k
    for [ sub_str[i-k+1] ....,sub_str[i]] == [sub_str[sub_str_cnt-1-k+1]sub_str[sub_str_cnt-1]]
����ȥ��Щ��ɬ�Ѷ���ʵ����suff[i]������sub_str����iλ���ַ�Ϊ��׺�������һ���ַ�Ϊ��׺�Ĺ�����׺���ĳ��ȡ���֪������˵�����û�У����Ǿٸ����Ӱɣ�

    i      : 0 1 2 3 4 5 6 7
    sub_str: b c  a b a b a b

��i=7ʱ��������suff[7] = strlen(sub_str) = 8
��i=6ʱ����sub_str[6]Ϊ��׺�ĺ�׺��Ϊbcababa�������һ���ַ�bΪ��׺�ĺ�׺��Ϊbcababab������û�й�����׺��������suff[6] = 0
��i=5ʱ����sub_str[5]Ϊ��׺�ĺ�׺��Ϊbcabab�������һ���ַ�bΪ��׺�ĺ�׺��Ϊbcababab�����ߵĹ�����׺��Ϊabab������suff[5] = 4
�Դ����ơ���
��i=0ʱ����sub_str[0]Ϊ��׺�ĺ�׺��Ϊb�������һ���ַ�bΪ��׺�ĺ�׺��Ϊbcababab�����ߵĹ�����׺��Ϊb������suff[0] = 1
*/

void get_suffix(const char *sub_str, int sub_str_cnt, int suffix[])
{
    int i, j;
    /*longest_suffix��ʾ��i���ĺ�׺��ģʽ����׺�Ĺ������ֵĳ���*/
    int comm_suffix;

    suffix[sub_str_cnt - 1] = sub_str_cnt;

    for(i = sub_str_cnt - 2; i >= 0; i--)
    {
        j = i;
        comm_suffix = 0;
        while(j >= 0 && sub_str[j] == sub_str[sub_str_cnt - 1 - i + j])
        {
            j--;
            comm_suffix++;
        }

        suffix[i] = comm_suffix;
    }
}

void bm_good(const char *sub_str, int sub_str_cnt, int good_last_pos[])
{
    int i, j;
    int *suffix;

    suffix = (int *)malloc(sub_str_cnt * sizeof(int));
    // �����׺����
    get_suffix(sub_str, sub_str_cnt, suffix);

    // ��ȫ����ֵΪm������Case3
    for(i = 0; i < sub_str_cnt; i++)
    {
        good_last_pos[i] = sub_str_cnt;
    }

    // Case2
    j = 0;
    for(i = sub_str_cnt - 1; i >= 0; i--)
    {
        if(suffix[i] == i + 1)
        {
            for(; j < sub_str_cnt - 1 - i; j++)
            {
                if(good_last_pos[j] == sub_str_cnt)
                    good_last_pos[j] = sub_str_cnt - 1 - i;
            }
        }
    }

    // Case1
    for(i = 0; i <= sub_str_cnt - 2; i++)
    {
        good_last_pos[sub_str_cnt - 1 - suffix[i]] = sub_str_cnt - 1 - i;
    }
}

int bm_str_search(const char *main_str, const char *sub_str, int main_str_cnt, int sub_str_cnt)
{
    int bad_last_pos[MAX_CHAR] = {0};
    int *good_last_pos;
    int i, j;
    int good_move, bad_move;
    int step = 1;

    good_last_pos = (int *)malloc(sub_str_cnt * sizeof(int));

    bm_bad(sub_str, sub_str_cnt, bad_last_pos);
    bm_good(sub_str, sub_str_cnt, good_last_pos);

    /*jΪ�����±꣬iΪƥ�䴮�±�*/
    j = 0;
    while(j <= main_str_cnt - sub_str_cnt)
    {
        i = sub_str_cnt - 1;
        while(i >= 0 && main_str[j + i] == sub_str[i])
        {
            i--;
        }

        /*�ҵ���*/
        if(i < 0)
        {
            return j;
        }
        else
        {
            bad_move = i - bad_last_pos[(int)main_str[j + i]];
            good_move = good_last_pos[i];
            if(bad_move > good_move)
            {
                j += bad_move;
                printf("step%d: bad_move: %d good_move: %d j: %d\n", step++, bad_move, good_move, j);
            }
            else
            {
                j += good_move;
                printf("step%d: bad_move: %d good_move: %d j: %d\n", step++, bad_move, good_move, j);
            }
            //j += MAX(i - bad_last_pos[main_str[j + i]], good_last_pos[i]);
        }
    }

    return -1;
}
