#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// фукнция транспонирования матрицы, просто проходимся по матрице
// только вместо [i][j] ставим [j][i] и выводим через printf("d",Matrix[i][j])
// тут "d" значит  что мы выводим число формата int
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
// Получение миноров
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

//рекурсивное вычисление дискриминанта
int determinant(int **Matrix, int size){
    if (size == 1)
        return Matrix[0][0];
    if (size == 2)
        return (Matrix[1][1] * Matrix[0][0]) - (Matrix[0][1] * Matrix[1][0]);
    //ans - определитель, ans - коэффицент перед дискриминантом минора, он меняет знак так как находисят в степени
    int ans = 0, sig = 1;
    //матрица вычисляется разложением по строке и столбцу
    for (int i = 0; i < size; ++i){
        ans += (sig * Matrix[0][i] * determinant(get_matrix(Matrix, size, i),size - 1));
        sig *= -1;
    }
    return ans;
}
// меняем местами элементы
void swap(int **Matrix, int line1, int line2,int column)
{
    for (int i = 0; i < column; i++)
    {
        int temp = Matrix[line1][i];
        Matrix[line1][i] = Matrix[line2][i];
        Matrix[line2][i] = temp;
    }
}

//нахождение ранга матрицы
int get_rank(int **Matrix, int lines, int columns)
{
    int rank = columns;

    for (int row = 0; row < rank; row++)
    {
        // Прежде чем мы перейдем к текущей строке 'row', мы сделаем
        // так чтобы mat[row][0],....mat[row][row-1]
        // были равны 0.

        // Диагональный элемент не равен нулю
        if (Matrix[row][row])
        {
            for (int col = 0; col < lines; col++)
            {
                if (col != row)
                {
                    // Это делает все значения текущего столбца равными 0,
                    // кроме 'mat[row][row]'
                    double res = (double)Matrix[col][row] /Matrix[row][row];
                    for (int i = 0; i < rank; i++)
                        Matrix[col][i] -= res * Matrix[row][i];
                }
            }
        }

            // Диагональный элемент уже равен нулю. Два случая возникать:
            //1) Если под ним есть строка с ненулевым
            // значением, затем меняем местами эту строку с той строкой
            // и обработайте её
            // 2) Если все элементы в текущем столбце меньше
            // mat[r][row] равны 0, затем удаляем этот столбец
            // заменив его на последний столбец и
            // уменьшив количество столбцов на 1.
        else
        {
            bool reduce = true;

            /* Найдём ненулевой элемент в текущем
                колонка  */
            for (int i = row + 1; i < lines;  i++)
            {
                // Поменяем местами строку с ненулевым элементом
                // с этой строкой.
                if (Matrix[i][row])
                {
                    swap(Matrix, row, i, rank);
                    reduce = false;
                    break ;
                }
            }

            // Если мы не нашли ни одной строки с ненулевым
            // элемент в текущем столбце, значит все
            // значения в этом столбце равны 0.
            if (reduce)
            {
                // уменьшаем количество столбцов
                rank--;

                // скопируем последний столбец сюда
                for (int i = 0; i < lines; i ++)
                    Matrix[i][row] = Matrix[i][rank];
            }

            // Обработаем эту строку еще раз
            row--;
        }

        // если нужно увидеть промежутчной результат, разкоментит эти строки
        // display(mat, R, C);
        // printf("\n");
    }
    return rank;
}
int main() {
    int lines, columns, **Matrix;

    //ввод количества столбцов и строк
    printf("Type the matrix lines:\n");
    scanf("%d", &lines);
    printf("Type the matrix columns:\n");
    scanf("%d", &columns);

    //выделяем память под строки
    Matrix = (int **)malloc(lines * sizeof(int *));

    // каждой строке выделяем место для столбцов
    for (int i = 0; i < lines; ++i)
        Matrix[i] = (int *)malloc(columns * sizeof(int));

    //ввод элементов матрицы
    for (int i = 0; i < lines; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            printf("Type a number for <line: %d, column: %d>\n", i+1, j+1);
            scanf("%d", &Matrix[i][j]);
        }
    }
    //вывод введёной матрицы
    for (int i = 0; i < lines; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
    //функции
    transpose(Matrix, lines, columns);
    printf("%d\n", determinant(Matrix,lines));
    printf("%d\n", get_rank(Matrix,lines,columns));


}
