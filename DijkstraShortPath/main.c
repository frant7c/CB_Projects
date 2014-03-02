#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 6
#define INFINITY 32767
#define NOT_EXIST -1

void dijkstra_shortpath(int graph[MAXVEX][MAXVEX], int dist[MAXVEX], int path[MAXVEX], int start_point, int end_point)
{
    int close_list[MAXVEX] = {0};
    int open_list[MAXVEX] = {0};
    int open_cnt = 0, close_cnt = 0;
    int shortest_dist, cur_point = start_point;
    int i;

    for(i = 0; i < MAXVEX; i++)
    {
        path[i] = NOT_EXIST;
    }

    /*��ʼ������¼����ʼ����������нڵ����open list*/
    for(i = 0; i < MAXVEX; i++)
    {
        dist[i] = graph[start_point][i];
        if(dist[i] < INFINITY)
        {
            printf("1 path[%d] = %d\n", i, path[i]);
            path[i] = start_point;
            printf("2 path[%d] = %d\n", i, path[i]);
            open_list[i] = 1;
            open_cnt++;
        }
    }

    /*����ʼ�ڵ����close list*/
    close_list[start_point] = 1;
    close_cnt = 1;

    /*open listΪ�ձ�ʾ������Ҫ�ҵ�·������Ŀ��ڵ㱻����close listʱ��ʾ���·���ҵ�*/
    while(open_cnt > 0 && cur_point != end_point)
    {
        shortest_dist = INFINITY;

        /*��open list���ҳ���ǰ��֪·���е����·��*/
        for(i = 0; i < MAXVEX; i++)
        {
            if(open_list[i] == 1 && shortest_dist > dist[i])
            {
                shortest_dist = dist[i];
                cur_point = i;
            }
        }
        /*����ǰ�ڵ��Ƴ�open list������close list*/
        open_list[cur_point] = 0;
        open_cnt--;
        close_list[cur_point] = 1;
        close_cnt++;

        /*�������ʼ�㣬������ǰ�ڵ㣬����һ�ڵ�ľ��룬����и���·�������dist�б�
        �������һ�ڵ���close list������ԣ��������open list*/
        for(i = 0; i < MAXVEX; i++)
        {
            if(close_list[i] == 0 && graph[cur_point][i] < INFINITY)
            {
                if(dist[i] > dist[cur_point] + graph[cur_point][i])
                {
                    dist[i] = dist[cur_point] + graph[cur_point][i];
                    printf("1 path[%d] = %d\n", i, path[i]);
                    path[i] = cur_point;
                    printf("2 path[%d] = %d\n", i, path[i]);
                }
                /*��ֹ�ظ�����*/
                if(open_list[i] == 0)
                {
                    open_list[i] = 1;
                    open_cnt++;
                }
            }
        }
    }

    /*��ӡ���*/
    if(path[end_point] == NOT_EXIST)
    {
        printf("No path!\n");
        return;
    }

    printf("%d <= ", end_point);
    cur_point = end_point;
    while(path[cur_point] != start_point)
    {
        printf("%d <= ", path[cur_point]);
        cur_point = path[cur_point];
    }
    printf("%d", start_point);
}

int main()
{
    int graph[MAXVEX][MAXVEX], dist[MAXVEX] = {0}, path[MAXVEX] = {NOT_EXIST};
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
    dijkstra_shortpath(graph, dist, path, 0, 5);

    fclose(file);
    return 0;
}
