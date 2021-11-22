#include <stdio.h>
#include "my_mat.h"
void copyMat(int mat1[10][10],int mat[10][10],int len);
int INF= 99999;
void inputToMat(int mat[10][10],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
}
void shortestPath(int mat[10][10],int len, int i, int j)
{
    
    int dist[len][len];
    copyMat(dist,mat,len);
    for(int k=0;k<len;k++)
    {
        for(int m=0;m<len;m++)
        {
            for(int l=0;l<len;l++)
            {
                if(dist[m][k]+dist[k][l]<dist[m][j])
                {
                    dist[m][j]=dist[m][k]+dist[k][l];
                }
            }
        }
    }
    if( dist[i][j]!=INF )
        printf("%d",dist[i][j]);
    else 
        printf("-1");
}
void path (int mat[10][10],int len, int i, int j)
{
    int dist[len][len];
    copyMat(dist,mat,len);
    for(int k=0;k<len;k++)
    {
        for(int m=0;m<len;m++)
        {
            for(int l=0;l<len;l++)
            {
                if(dist[m][k]+dist[k][l]<dist[m][j])
                {
                    dist[m][j]=dist[m][k]+dist[k][l];
                }
            }
        }
    }
    if(i!=j && dist[i][j]!=INF)
        printf("True");
    else if(i!=j && dist[i][j]==INF)
        printf("False");
    else
        printf("True");
        
}
void copyMat(int mat1[10][10],int mat[10][10],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(i!=j && mat[i][j]==0)
                mat1[i][j]=INF;
            else
                mat1[i][j]=mat[i][j];
        }
    }
}