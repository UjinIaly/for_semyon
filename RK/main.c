#include <stdio.h>
#include <string.h>

struct data{
    char name[80];
    float price;
    int number;
};


void check_and_print(FILE *file, struct data info[],char file_name[]){
    file = fopen("/home/iwaly/for_semyon/parcing/file.txt","r");
    if(file == NULL){
        printf("error");
        return;
    }
    float money = 0;
    int size = 0;
    for(int i = 0; !feof(file);++i){
        fscanf(file,"%s",info[i].name);
        fscanf(file,"%f",&info[i].price);
        fscanf(file,"%d",&info[i].number);
        //printf("%s ",info[i].name);
        //printf("%.f ",info[i].price);
        //printf("%.d ",info[i].number);
        //printf("\n");
        money += info[i].price;
        ++size;
    }
    float array[size];
    for(int i = 0;i<size;++i){
        array[i] = info[i].price;
    }
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (array[j - 1] > array[j])
            {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
    for(int j = 0;j<3;++j){
        for(int i = 0;i<size;++i){
            if(array[j] == info[i].price){
                printf("%s ",info[i].name);
                break;
            }
        }
    }
    printf("\n%.f ",money);

}



int main() {
    struct data info[3];
    char file_name[100];
    scanf( "%s", file_name);
    FILE *file = NULL;
    check_and_print(file,info,file_name);







}