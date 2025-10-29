#include<stdio.h>
#include<stdlib.h>

int n=4;

int check(int a[4][4],int t[4][4]) {
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]!=t[i][j])
                return 0;
    return 1;
}

int cal(int temp[4][4],int t[4][4]) {
    int i,j,m=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(temp[i][j]==t[i][j])
                m++;
    return m;
}

int main() {
    int i,j,a[4][4],t[4][4],temp[4][4],r[4][4];
    int x,y,p,m,d,dmin,l=0;
    
    printf("Enter initial matrix (0 for empty):\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
            
    printf("Enter target matrix (0 for empty):\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&t[i][j]);
    
    while(!check(a,t)) {
        l++;
        d=1000;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][j]==0) {
                    x=i;
                    y=j;
                }
        
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                temp[i][j]=a[i][j];
                
        if(x!=0) {
            p=temp[x][y];
            temp[x][y]=temp[x-1][y];
            temp[x-1][y]=p;
            m=cal(temp,t);
            dmin=l+m;
            if(dmin<d) {
                d=dmin;
                for(i=0;i<n;i++)
                    for(j=0;j<n;j++)
                        r[i][j]=temp[i][j];
            }
        }
        
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                a[i][j]=r[i][j];
    }
    
    printf("Puzzle solved!\n");
    return 0;
}