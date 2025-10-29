#include<stdio.h>
#include<limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int dist[MAX];
int visited[MAX];

int minDistance() {
    int min=INT_MAX,min_index;
    for(int v=1;v<=n;v++) {
        if(visited[v]==0 && dist[v]<=min) {
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    for(int i=1;i<=n;i++) {
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    dist[src]=0;
    
    for(int count=1;count<n;count++) {
        int u=minDistance();
        visited[u]=1;
        
        for(int v=1;v<=n;v++) {
            if(!visited[v] && cost[u][v] && dist[u]!=INT_MAX 
               && dist[u]+cost[u][v]<dist[v]) {
                dist[v]=dist[u]+cost[u][v];
            }
        }
    }
    
    printf("Vertex\tDistance from Source\n");
    for(int i=1;i<=n;i++) {
        if(dist[i]==INT_MAX)
            printf("%d\tINF\n",i);
        else
            printf("%d\t%d\n",i,dist[i]);
    }
}

int main() {
    int src;
    printf("\n\tImplementation of Dijkstra's algorithm\n");
    printf("\nEnter the no. of vertices\n");
    scanf("%d",&n);
    printf("\nEnter the cost adjacency matrix\n");
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("\nEnter the source vertex\n");
    scanf("%d",&src);
    dijkstra(src);
    return 0;
}