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
    float average;
    float temp = 0;
    int size = 0;
    for(int i = 0;i<3;++i){
        for(int j = 0;j<3;++j){
            if(info[j].city == info[i].city){
                temp += info[j].temperature;
                ++size;
            }

        }
        temp/=size;
        if(temp > average){
            average = temp;
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
