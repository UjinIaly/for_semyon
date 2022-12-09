#include <stdio.h>
#include <math.h>
int check(int number, int n){
    int array[n];
    for(int i = 0;i<n;++i){
        array[i] = number%10;
        number/=10;
    }
    for(int i = 0;i<n;++i){
        for(int j = i+1;j<n;++j){
            if(array[i] == array[j])
                return 1;
        }
    }
    return 0;

}

int main() {
    int n;
    int number=1;
    scanf("%d",&n);
    for(int i = 0;i<n-1;++i){
        number*=10;
    }
    for(int i = number;i<number*10;++i){
        if(check(i,n) == 0)
            printf("%d, ",i);
    }



}
