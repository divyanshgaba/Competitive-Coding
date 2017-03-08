#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
int n;
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
    int v;
   for (v = 0; v < n; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
    int i;
   printf("Vertex   Distance from Source\n");
   for (i = 0; i < n; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[n][n], int src)
{
     int dist[n];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[n]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

                     int i;
     // Initialize all distances as INFINITE and stpSet[] as false
     for (i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;
int count;
     // Find shortest path for all vertices
     for (count = 0; count < n-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;
int  v;
       // Update dist value of the adjacent vertices of the picked vertex.
       for (v = 0; v < n; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     // print the constructed distance array
     printSolution(dist, n);
}
int main()
{
    scanf("%d",&n);
    int i;
    int graph[501][501]={};
    int orig[501];
    for(i=0;i<n;i++)
    {
        scanf("%d",&orig[501]);
    }
    for(i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        graph[x-1][y-1]=1;
    }
    dijkstra(graph, 0);

    return 0;
}
