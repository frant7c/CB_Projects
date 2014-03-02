#include <stdio.h>
#include <stdlib.h>
#include "../LBLsContainer/LBLsContainer.h"

typedef struct data_alignment
{
    int a;
    int b;
    int c;
}data_alignment;

typedef struct data_alignment_a
{
    data_alignment a;
    double b;
}data_alignment_a;

int main()
{
    int a = 10;
    int *p;
    int *p1;
    unsigned short b = 0xffff;
    char buf[20];
    int arr[5] = {1, 2, 3, 4, 5};
    int (*p2)[3];
    int array[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    queue q1;
    queue ele_que;
    stack s1;
    HashTable *hash_table = NULL;
    HashElement *hash_elem;
    int max_element = 5;
    data_alignment c;
    int **tmp;

    tmp = array;
    queue_init(&q1, sizeof(queue) * max_element, max_element);
    ele_que.head = 0;
    enqueue(&q1, (void *)&ele_que, sizeof(queue));
    ele_que.head = 1;
    enqueue(&q1, (void *)&ele_que, sizeof(queue));
    ele_que.head = 2;
    enqueue(&q1, (void *)&ele_que, sizeof(queue));
    ele_que.head = 3;
    enqueue(&q1, (void *)&ele_que, sizeof(queue));
    dequeue(&q1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    ele_que.head = 4;
    enqueue(&q1, (void *)&ele_que, sizeof(queue));
    dequeue(&q1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    dequeue(&q1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    dequeue(&q1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    dequeue(&q1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    ele_que.head = 5;
    enqueue(&q1, (void *)&ele_que, sizeof(queue));
    dequeue(&q1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    printf("---------------------\n");
    stack_init(&s1, sizeof(queue) * max_element, max_element);
    ele_que.head = 0;
    stack_push(&s1, (void *)&ele_que, sizeof(queue));
    ele_que.head = 1;
    stack_push(&s1, (void *)&ele_que, sizeof(queue));
    ele_que.head = 2;
    stack_push(&s1, (void *)&ele_que, sizeof(queue));
    ele_que.head = 3;
    stack_push(&s1, (void *)&ele_que, sizeof(queue));
    stack_pop(&s1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    ele_que.head = 4;
    stack_push(&s1, (void *)&ele_que, sizeof(queue));
    stack_pop(&s1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    stack_pop(&s1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    stack_pop(&s1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    stack_pop(&s1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    ele_que.head = 5;
    stack_push(&s1, (void *)&ele_que, sizeof(queue));
    stack_pop(&s1, &ele_que, sizeof(queue));
    printf("%d\n", ele_que.head);
    printf("---------------------\n");

    hash_table = hash_table_init(10);
    if(NULL == hash_table)
    {
        printf("error\n");
        return 0;
    }

    hash_elem = (HashElement *)malloc(sizeof(HashElement));
    p1 = (int *)malloc(sizeof(int));
    *p1 = 0x12345678;
    hash_elem->data = (void *)p1;
    hash_elem->key = 56;
    hash_elem->next = NULL;
    hash_elem->value = 78;
    hash_insert(hash_table, 10, hash_elem);
    hash_insert(hash_table, 10, hash_elem);
    hash_elem = (HashElement *)malloc(sizeof(HashElement));
    p1 = (int *)malloc(sizeof(int));
    *p1 = 88;
    hash_elem->data = (void *)p1;
    hash_elem->key = 37;
    hash_elem->next = NULL;
    hash_elem->value = 89;
    hash_insert(hash_table, 10, hash_elem);
    hash_elem = (HashElement *)malloc(sizeof(HashElement));
    p1 = (int *)malloc(sizeof(int));
    *p1 = 99;
    hash_elem->data = (void *)p1;
    hash_elem->key = 645;
    hash_elem->next = NULL;
    hash_elem->value = 100;
    hash_insert(hash_table, 10, hash_elem);
    hash_elem = (HashElement *)malloc(sizeof(HashElement));
    p1 = (int *)malloc(sizeof(int));
    *p1 = 45;
    hash_elem->data = (void *)p1;
    hash_elem->key = 223;
    hash_elem->next = NULL;
    hash_elem->value = 46;
    hash_insert(hash_table, 10, hash_elem);
    hash_elem = (HashElement *)malloc(sizeof(HashElement));
    p1 = (int *)malloc(sizeof(int));
    *p1 = 233;
    hash_elem->data = (void *)p1;
    hash_elem->key = 6867;
    hash_elem->next = NULL;
    hash_elem->value = 124;
    hash_insert(hash_table, 10, hash_elem);
    hash_elem = (HashElement *)malloc(sizeof(HashElement));
    p1 = (int *)malloc(sizeof(int));
    *p1 = 4644;
    hash_elem->data = (void *)p1;
    hash_elem->key = 23;
    hash_elem->next = NULL;
    hash_elem->value = 6546;
    hash_insert(hash_table, 10, hash_elem);
    hash_elem = (HashElement *)malloc(sizeof(HashElement));
    p1 = (int *)malloc(sizeof(int));
    *p1 = 23;
    hash_elem->data = (void *)p1;
    hash_elem->key = 453;
    hash_elem->next = NULL;
    hash_elem->value = 765;
    hash_insert(hash_table, 10, hash_elem);
    hash_elem = (HashElement *)malloc(sizeof(HashElement));
    p1 = (int *)malloc(sizeof(int));
    *p1 = 56464;
    hash_elem->data = (void *)p1;
    hash_elem->key = 452;
    hash_elem->next = NULL;
    hash_elem->value = 785;
    hash_insert(hash_table, 10, hash_elem);
    p = (int *)hash_find(hash_table, 10, 56, 78);
    printf("%d\n", *p);
    p = (int *)hash_find(hash_table, 10, 453, 765);
    printf("%d\n", *p);
    p = (int *)hash_find(hash_table, 10, 23, 6546);
    printf("%d\n", *p);
    printf("---------------------\n");

    printf("%d\n", b++);
    printf("%d\n", b++);
    sscanf("2009 Hello, BIWU", "%*[0-9 Ha-z,]%s", buf);
    printf("%s\n", buf);
    printf("%d\n", sizeof("a"));
    printf("%d\n", *(array[0]+2));
    printf("Hello world!\n");
    printf("%d\n", sizeof(data_alignment_a));
    printf("---------------------\n");
    a = -1;
    printf("%u\n", (unsigned int)a);
    p = arr;
    p2 = array;
    printf("%d %d\n", *++p, p2[3][2]);
    return 0;
}
