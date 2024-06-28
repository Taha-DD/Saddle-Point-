#include <stdio.h>
#include <stdlib.h>

#define H 100

int sad( int **mat, int rows, int cols, int pointRow, int pointCol ){
    for ( int i = 0; i < cols; ++i )
        if( mat[pointRow][pointCol] < mat[pointRow][i] )
            return 0;
            
    for ( int i = 0; i < rows; ++i )
        if( mat[pointRow][pointCol] > mat[i][pointCol] )
            return 0;

    return 1;
}

int dle( int **mat, int rows, int cols, int pointRow, int pointCol ){
    for ( int i = 0; i < cols; ++i )
        if( mat[pointRow][pointCol] > mat[pointRow][i] )
            return 0;
        
            
    for ( int i = 0; i < rows; ++i )
        if( mat[pointRow][pointCol] < mat[i][pointCol] )
            return 0;

    return 1;
}

int main()
{
    int rowsN, columnM, **T, c = 0;
    
    printf(" enter your array's sizes:\n N = ");
    scanf("%d", &rowsN);
    
    printf(" M = ");
    scanf("%d", &columnM);
    
    T = malloc(rowsN*sizeof(int*));
    
    for ( int i = 0; i < rowsN; i++ ){
        T[i] = malloc(columnM*sizeof(int));
        for ( int j = 0; j < columnM; j++ )
        {
            printf(" T[%d][%d] = ", i, j);
            scanf("%d", &T[i][j]);
        }
    }
    
    for ( int i = 0; i < rowsN; i++ )
        for ( int j = 0; j < columnM; j++ )
            if( sad(T, rowsN, columnM, i, j) || dle(T, rowsN, columnM, i, j) ){
                c++;    
                printf("there's a saddle point in the position T[%d][%d] and its value is %d\n", i, j, T[i][j]);
            }
    
    if ( c == 0 )
        printf(" seems like there's no saddle points ");
    
    return 0;
}
