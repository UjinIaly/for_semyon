#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void transpose(int **Matrix, int lines, int columns){
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < lines; ++j)
        {

            printf("%d ", Matrix[j][i]);
        }
        printf("\n");
    }
}
int **get_matrix(int **Matrix, int size, int less_size){
    int ** res = (int **)malloc((size - 1) * sizeof(int *));
    for (int i = 0; i < size - 1; ++i)
        res[i] = (int *)malloc((size- 1) * sizeof(int));
    for (int i = 1; i < size; ++i) {
        int k = 0;
        for (int j = 0; j < size; ++j, ++k) {
            if (j == less_size) {
                --k;
                continue;
            }
            res[i - 1][k] = Matrix[i][j];
        }
    }
    return res;
}
int determinant(int **Matrix, int size){
    if (size == 1)
        return Matrix[0][0];
    if (size == 2)
        return (Matrix[1][1] * Matrix[0][0]) - (Matrix[0][1] * Matrix[1][0]);
    int ans = 0, sig = 1;
    for (int i = 0; i < size; ++i){
        ans += (sig * Matrix[0][i] * determinant(get_matrix(Matrix, size, i),size - 1));
        sig *= -1;
    }
    return ans;
}
int get_rank(int ** Matrix, int lines, int columns){
    const double EPS = 1E-9;

    int rank;
    if(lines>columns)rank = lines;
    else rank = columns;
    char line_used[lines];
    for (int i=0; i<columns; ++i) {
        int j;
        for (j=0; j<lines; ++j)
            if (!line_used[j] && abs(Matrix[j][i]) > EPS)
                break;
        if (j == lines)
            --rank;
        else {
            line_used[j] = true;
            for (int p=i+1; p<columns; ++p)
                Matrix[j][p] /= Matrix[j][i];
            for (int k=0; k<lines; ++k)
                if (k != j && abs (Matrix[k][i]) > EPS)
                    for (int p=i+1; p<columns; ++p)
                        Matrix[k][p] -= Matrix[j][p] * Matrix[k][i];
        }
    }
    return rank;
}
int main() {
    int lines, columns, **Matrix;

    printf("Type the matrix lines:\n");
    scanf("%d", &lines);
    printf("Type the matrix columns:\n");
    scanf("%d", &columns);

    Matrix = (int **)malloc(lines * sizeof(int *));


    for (int i = 0; i < lines; ++i)
        Matrix[i] = (int *)malloc(columns * sizeof(int));


    for (int i = 0; i < lines; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            printf("Type a number for <line: %d, column: %d>\n", i+1, j+1);
            scanf("%d", &Matrix[i][j]);
        }
    }
    for (int i = 0; i < lines; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }

    transpose(Matrix, lines, columns);
    printf("%d\n", determinant(Matrix,lines));
    printf("%d\n", get_rank(Matrix,lines,columns));


}
