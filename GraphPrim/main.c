#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 6
#define INFINITY 32767

/*������S = {1}��Ȼ��ֻҪS��V�����Ӽ���
�ͽ������µ�̰��ѡ��ѡȡ��������i ��S,j ��V �C S,��c[i][j]��С�ıߣ�
������j��ӵ�S�С��������һֱ���е�S = VʱΪֹ��*/


void prim(int graph[MAXVEX][MAXVEX], int start_point)
{
    int set_s[MAXVEX] = {0};
    int set_t[MAXVEX];
    int set_s_cnt = 0;
    int set_t_cnt = MAXVEX;
    int shortest = INFINITY;
    int cur_point = start_point;
    int next_point = start_point;
    int i, j;

    for(i = 0; i < MAXVEX; i++)
    {
        set_t[i] = 1;
    }

    /*����ʼ����뼯��s*/
    set_s[start_point] = 1;
    set_s_cnt++;
    set_t[start_point] = 0;
    set_t_cnt--;
    printf("%d", start_point);

    while(set_s_cnt < MAXVEX)
    {
        /*Ѱ�ҴӼ���s��ĳһ����i������t��ĳһ����j��ʹ�ñ�ij�����б�����̵�*/
        shortest = INFINITY;
        for(i = 0; i < MAXVEX; i++)
        {
            if(set_s[i] == 1)
            {
                for(j = 0; j < MAXVEX; j++)
                {
                    if(set_t[j] == 1 && graph[i][j] < shortest)
                    {
                        shortest = graph[i][j];
                        cur_point = j;
                    }
                }
            }

        }
        /*������j����s*/
        set_s[cur_point] = 1;
        set_s_cnt++;
        set_t[cur_point] = 0;
        set_t_cnt--;

        printf(" -> %d", cur_point);
    }
    printf("\n");
}

int main()
{
    int graph[MAXVEX][MAXVEX];
    int i, j;
    FILE *file;

    file = fopen("data.txt", "r+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return 0;
    }

    j = 0;
    while(!feof(file))
    {
        for(i = 0; i < MAXVEX; i++)
        {
            fscanf(file, "%d ", &graph[j][i]);
        }
        j++;
    }
    printf("Original sequence:\n");
    for(i = 0; i < MAXVEX; i++)
    {
        for(j = 0; j < MAXVEX; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    prim(graph, 0);

    fclose(file);
    return 0;
}
