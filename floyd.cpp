#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 999

int min(int a, int b) {
    int min = (a<b) ? a : b;
    return min;
}

void createGraph(int adj[MAX][MAX], int n)
{
    printf("Enter Adj Matrix: (999 for inf)\n ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

void floyd(int adj[MAX][MAX], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], (adj[i][k] + adj[k][j]));
            }
        }
    }
}

void printGraph(int adj[MAX][MAX], int n)
{
    printf("After:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter No of Vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    createGraph(adj, n);
    floyd(adj, n);
    printGraph(adj, n);

    return 0;
}
