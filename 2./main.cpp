#include "iostream"

int main () {

setlocale( LC_ALL,"Russian" );

int numb_m = 0, numb_d=0, numb_c=0, numb_l=0, numb_x=0, numb_v=0, numb_i=0;

int numb_arab;

std::cout<<"Введите арабское число : ";

std::cin>>numb_arab;

numb_m=numb_arab/1000;

if (numb_arab%1000>=500) numb_d++;

numb_c=(numb_arab-numb_arab/1000*1000-numb_d*500)/100;

if (numb_arab%100>=50) numb_l++;

numb_x=(numb_arab-numb_arab/100*100-numb_l*50)/10;

if (numb_arab%10>=5) numb_v++;

numb_i = numb_arab-numb_arab/10*10-numb_v*5;

int size = numb_m+numb_d+numb_c+numb_l+numb_x+numb_v+numb_i;

char numb_rome[size];

int ptr = 0;

for (; ptr<numb_m; ptr++)

numb_rome[ptr]='M';

if (numb_d>0) {numb_rome[ptr] = 'D'; ptr++;}

for (; ptr<numb_m+numb_d+numb_c; ptr++)

numb_rome[ptr]='C';

if (numb_l>0) {numb_rome[ptr] = 'L'; ptr++;}

for (; ptr<size-numb_v-numb_i; ptr++)

numb_rome[ptr]='X';

if (numb_v>0) {numb_rome[ptr] = 'V'; ptr++;}

for (; ptr<size; ptr++)

numb_rome[ptr]='I';

std::cout<<"Римское число : ";

for (int i=0; i<size; i++) {

std::cout<<numb_rome[i];

}

}