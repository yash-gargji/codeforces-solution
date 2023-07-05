 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 
int minDistance(int dist[], int n, int *sptSet)
{
    int min = 10000000, min_index;

    for (int v = 0; v < n; v++)
        if (*(sptSet + v) == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int n)
{
    for (int i = 1; i < n; i++)
        printf("%d ", dist[i]);
}

void dijkstra(int **graph, int n, int src)
{
    int *dist = (int *)malloc(n * sizeof(int));
    int *sptSet = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        dist[i] = 10000000, *(sptSet + i) = 0;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = minDistance(dist, n, sptSet);

        *(sptSet + u) = 1;

        for (int v = 0; v < n; v++)
        {
            if (!*(sptSet + v) && graph[u][v] && dist[u] != 10000000 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist, n);

    free(dist);
    free(sptSet);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int **graph = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        *(graph + i) = (int *)malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a][b] = c;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(graph[i][j] != 1){
                graph[i][j] = 10000000;
            }
        }
    }
   

    dijkstra(graph, n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
