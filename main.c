#include <stdio.h>
#include "my_mat.h"
int main(){
    char c='A';
    int mat[10][10];
    int i=0,j=0;
    scanf(" %c",&c);
    while(c!='D')
    {
        switch (c){
            case 'A': inputToMat(mat,10);
                        break;
            case 'B':   scanf("%d %d",&i,&j);
                        path(mat,10,i,j);
                        break;
            case 'C':   scanf("%d %d",&i,&j);
                        shortestPath(mat,10,i,j);
                        break;

        }
        scanf(" %c",&c);
    }
    return 0;
}