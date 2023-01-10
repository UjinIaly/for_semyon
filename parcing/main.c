#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char city[20];
    int day;
    float temperature;
    float wetness;
};

void check_and_print(FILE *file, struct data info[],char file_name[],char highest[]){
    file = fopen("/home/iwaly/for_semyon/parcing/file.txt","r");
    if(file == NULL){
        printf("error");
        return;
    }
    float max = 0;
    for(int i = 0; !feof(file);++i){
        fscanf(file,"%s",info[i].city);
        fscanf(file,"%d",&info[i].day);
        fscanf(file,"%f",&info[i].temperature);
        fscanf(file,"%f",&info[i].wetness);
        printf("%s ",info[i].city);
        printf("%.d ",info[i].day);
        printf("%.1f ",info[i].temperature);
        printf("%.2f ",info[i].wetness);
        printf("\n");
    }
    //хранит в себе максимальную среднюю темпу
    float average;
    //сюда записывается сумма температуры за месяц в 1 городе
    float temp = 0;
    //количество измерений 1 города
    int size = 0;
    // 2 цикла потому что мы берём каждый город и складываем его измерения
    //чтобы потом получить среднюю
    for(int i = 0;i<3;++i){
        for(int j = 0;j<3;++j){
            if(info[j].city == info[i].city){
                //складываем каждое измерение и считаем количество измерений
                temp += info[j].temperature;
                ++size;
            }

        }
        //считаем среднемесячную
        temp/=size;
        //если среднемесячная выше чем самая высокая на данных момент меняем её
        if(temp > average){
            //меняем значение самой высокой
            average = temp;
            //копируем в переменную
            strcpy(highest,info[i].city);
        }
        temp = 0;
        size = 0;
    }


}



int main() {
    struct data info[3];
    char file_name[100];
    scanf( "%s", file_name);
    FILE *file = NULL;
    char highest[21];
    check_and_print(file,info,file_name,highest);
    printf("%s",highest);







}
