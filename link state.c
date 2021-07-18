#include <stdio.h>
#include <string.h>
int main()
{
    int count,src_node,i,j,k,w,v,min;
    int cost_matrix[100][100],dist[100],last[100];
    int flag[100];

    printf("\n Enter the no of nodes");
    scanf("%d",&count);
    printf("\n Enter the cost matrix values:");

    for(i=0;i<count;i++)
    {
        for(j=0;j<count;j++)
        {
            printf("\n%d->%d:",i,j);
            scanf("%d",&cost_matrix[i][j]);
            if(cost_matrix[i][j]<0)cost_matrix[i][j]=1000;
        }
    }
    printf("\n Enter the source node:");
    scanf("%d",&src_node);
    for(v=0;v<count;v++)
    {
    flag[v]=0;
    last[v]=src_node;
    dist[v]=cost_matrix[src_node][v];
    }
    flag[src_node]=1;

    for(i=0;i<count;i++)
    {
        min=1000;
        for(w=0;w<count;w++)
        {

            if(!flag[w])
            if(dist[w]<min)
            {
                v=w;
                min=dist[w];
            }
        }
    flag[v]=1;
    for(w=0;w<count;w++)
    {
        if(!flag[w])
        if(min+cost_matrix[v][w]<dist[w])
        {
            dist[w]=min+cost_matrix[v][w];
            last[w]=v;
        }
    }
    }
    for(i=0;i<count;i++)
    {
        printf("\n%d==>%d:Path taken:%d",src_node,i,i);
        w=i;
        while(w!=src_node)
        {
            printf("\n<--%d",last[w]);w=last[w];
        }
        printf("\n Shortest path cost:%d",dist[i]);
    }
}
