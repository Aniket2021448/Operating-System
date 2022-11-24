#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <stdlib.h>

#define SYS_kern_2D_memcpy 451

int main(){
    float matrix1[4][3] = {{45.0,8.0,6.0},{4.0,78.0,44.0},{89.0,88.0,72.0},{56.0,71.0,36.0}};
    float matrix2[4][3] = {{7.0,7.0,7.0},{7.0,7.0,7.0},{7.0,7.0,7.0},{7.0,7.0,7.0}};

    printf("FIRST ORIGINAL MATRIX\n");
    printf("==========================================\n");

    for (int row1 = 0; row1 < 4; row1++)
    {
        for (int column1 = 0; column1 < 3; column1++)
        {
            printf("%f ", matrix1[row1][column1]);
        }
        printf("\n");
    }
    printf("\n");

    printf("SECOND ORIGINAL MATRIX\n");
    printf("========================================\n");

    for (int row2 = 0; row2 < 4; row2++)
    {
        for (int column2 = 0; column2 < 3; column2++)
        {
            printf("%f ", matrix2[row2][column2]);
        }
        printf("\n");
    }
    printf("\n");

    int usingSysCall = syscall(SYS_kern_2D_memcpy, matrix1, matrix2, 4,3);
    printf("RESULTING FIRST ORIGINAL MATRIX AFTER MAKING A SYSCALL\n");
    printf("=========================================\n");

    for (int frow1 = 0; frow1 < 4; frow1++)
    {
        for (int fcolumn1 = 0; fcolumn1 < 3; fcolumn1++)
        {
            printf("%f ", matrix1[frow1][fcolumn1]);
        }
        printf("\n");
    }
    printf("\n");

    printf("RESULTING SECOND ORIGINAL MATRIX AFTER MAKING A SYSCALL\n");
    printf("=================================\n");


    for (int frow2 = 0; frow2 < 4; frow2++)
    {
        for (int fcolumn2 = 0; fcolumn2 < 3; fcolumn2++)
        {
            printf("%f ", matrix2[frow2][fcolumn2]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
