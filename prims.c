#include<stdio.h>
#include<limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];

void prim() {
    int i,j,min,a,b,u,v;
    int ne=1;
    int mincost=0;
    
    for(i=1;i<=n;i++)
        visited[i]=0;
    
    printf("\nThe edges of Minimum Cost Spanning Tree are\n");
    visited[1]=1;
    
    while(ne<n) {
        for(i=1,min=INT_MAX;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(cost[i][j]<min) {
                    if(visited[i]!=0) {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0) {
            printf("%d edge (%d,%d) = %d\n",ne++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=INT_MAX;
    }
    printf("\n\tMinimum cost = %d\n",mincost);
}

int main() {
    int i,j;
    printf("\n\tImplementation of Prim's algorithm\n");
    printf("\nEnter the no. of vertices\n");
    scanf("%d",&n);
    printf("\nEnter the cost adjacency matrix\n");
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INT_MAX;
        }
    }
    prim();
    return 0;
}