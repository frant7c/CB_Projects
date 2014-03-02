#include <stdio.h>
#include <stdlib.h>
#include "../LBLsContainer/LBLsContainer.h"

#define MAXVEX 6
#define MAXEDGE ((MAXVEX*(MAXVEX - 1))/2)
#define INFINITY 32767

typedef struct EdgeInfo
{
    int node1;
    int node2;
    int weight;
}EdgeInfo;

/*��1�����Ƚ�G��n�����㿴��n����������ͨ��֧�������еı߰�Ȩ��С������*/
/*��2���ӵ�һ���߿�ʼ������Ȩ������˳����ÿһ���ߡ�
������������������������ͬ����ͨ��֧�����鿴����k����(v,w)ʱ��
����˵�v��w�ֱ��ǵ�ǰ������ͬ����ͨ��֧T1��T2�Ķ˵��ǣ����ñ�(v,w)��T1��T2���ӳ�һ����ͨ��֧��
Ȼ������鿴��k+1���ߣ�����˵�v��w�ڵ�ǰ��ͬһ����ͨ��֧�У���ֱ���ٲ鿴k+1���ߡ�
�������һ�����е�ֻʣ��һ����ͨ��֧ʱΪֹ��*/

int seek_in_set(int set[MAXVEX], int node)
{
    int i = node;
    while(set[i] != -1)
    {
        i = set[i];
    }
    return i;
}

void kruskal(int graph[MAXVEX][MAXVEX])
{
    int i, j;
    int edge_cnt;
    int parent1, parent2;
    int set[MAXVEX] = {0};
    QuickSortElem edges[MAXEDGE];
    EdgeInfo *edge_info;

    /*��ȡ����Ϣ*/
    edge_cnt = 0;
    for(i = 0; i < MAXVEX; i++)
    {
        for(j = i + 1; j < MAXVEX; j++)
        {
            if(graph[i][j] < INFINITY)
            {
                edges[edge_cnt].key = graph[i][j];
                edge_info = (EdgeInfo *)malloc(sizeof(EdgeInfo));
                edge_info->node1 = i;
                edge_info->node2 = j;
                edge_info->weight = graph[i][j];
                edges[edge_cnt].data = (void *)edge_info;
                edge_cnt++;
            }
        }
    }

    /*����Щ�߰�Ȩ����С��������*/
    quick_sort(edges, 0, edge_cnt - 1);

    /*��ʼ����ͨ���ϣ�set[i]=-1��ʾ������ֻ��iһ�����㣬set[i]=j��ʾ����i��j����ͬһ��������j��i�ĸ��ڵ�*/
    for(i = 0; i < MAXVEX; i++)
    {
        set[i] = -1;
    }

    i = 0;
    j = 0;
    while(i < edge_cnt && j < MAXVEX - 1)
    {
        edge_info = (EdgeInfo *)edges[i].data;
        parent1 = seek_in_set(set, edge_info->node1);
        parent2 = seek_in_set(set, edge_info->node2);
        /*��������ͬһ�������������Ϻϲ�*/
        if(parent1 != parent2)
        {
            set[edge_info->node1] = edge_info->node2;
            j++;
            printf("%d -> %d  w: %d\n", edge_info->node1, edge_info->node2, edge_info->weight);
        }
        i++;
    }
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
    kruskal(graph);

    fclose(file);
    return 0;
}
