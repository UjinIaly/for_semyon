#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char city[21];
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
    char city[21];
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
        if(info[i].temperature>max){
            max = info[i].temperature;
            strcpy(city,info[i].city);
        }
    }
    strcpy(highest,city);

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
