#include <stdio.h>
//функция првоерки
int check(int number, int n){
    //перекидываем все цифры в массив интов, чтобы потом пройтись по нему и проверить
    int array[n];
    for(int i = 0;i<n;++i){
        //закидываем последюю цифру
        array[i] = number%10;
        //делим число на 10, чтобы убрать последнюю цифру
        number/=10;
    }
    //простой вложенный цикл, тут ищем одинаковые цифры
    for(int i = 0;i<n;++i){
        for(int j = i+1;j<n ;++j){
            if(array[i] == array[j])
                //если нашли выводим 1
                return 1;
        }
    }
    //если нет 0
    return 0;

}

int main() {
    //инициализируем переменные
    int n;
    int number=1;
    scanf("%d",&n);
    //очень топорно получем первое число разряда n-значных чисел
    for(int i = 0;i<n-1;++i){
        number*=10;
    }
    //танцы с бубном, чтобы вевести красиво 0 если введут 1-значные числа
    //типа если числа однозначые, то временная переменная равна 0
    // и потом от 0 будем проверять числа
    int temp = (number/10)==0?0:number;
    // цикл, который проверят каждое число есть ли в нём повторяющиеся цифры
    for(int i = temp;i<number*10;++i){
        //если проверка прошла успешно, выводим число
        if(check(i,n) == 0)
            printf("%d, ",i);
    }



}