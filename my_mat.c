#include <stdio.h>
#include "my_mat.h"
void copyMat(int mat1[10][10],int mat[10][10],int len);
int minus=-1;
void inputToMat(int mat[10][10],int len)
{
    int status;
    int flag=0;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(flag==0){
                status=scanf("%d",&mat[i][j]);
                if(status!=1)
                {
                    flag++;
                    mat[i][j]=0;
                }
            }
            else
                mat[i][j]=0;
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
                if(l==m)
                {
                    dist[m][l]=0;
                }
                else if(dist[m][l]==0 && (dist[m][k]==0 || dist[k][l]==0))
                {
                    dist[m][l]=0;
                }
                else if(dist[m][l]==0)
                {
                    dist[m][l]=dist[m][k]+dist[k][l];
                }
                else if(dist[m][k]>0 && dist[k][l] >0)
                {
                    if(dist[m][k]+dist[k][l]<dist[m][l])
                        dist[m][l]=dist[m][k]+dist[k][l];
                }
               
            }
        }
    }
    if( dist[i][j]!=0 )
        printf("%d\n",dist[i][j]);
    else 
        printf("%d\n",minus);
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
                if(l==m)
                {
                    dist[m][l]=0;
                }
                else if(dist[m][l]==0 && (dist[m][k]==0 || dist[k][l]==0))
                {
                    dist[m][l]=0;
                }
                else if(dist[m][l]==0)
                {
                    dist[m][l]=dist[m][k]+dist[k][l];
                }
                else if(dist[m][k]>0 && dist[k][l] >0)
                {
                    if(dist[m][k]+dist[k][l]<dist[m][l])
                        dist[m][l]=dist[m][k]+dist[k][l];
                }
               
            }
        }
    }
    if(dist[i][j]!=0)
        printf("True\n");
    else 
        printf("False\n");
        
}
void copyMat(int mat1[10][10],int mat[10][10],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            mat1[i][j]=mat[i][j];
        }
    }
}