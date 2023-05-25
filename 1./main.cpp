#include "iostream"
#include "string"
int main()
{
    //переменные для количества знаков для каждого разряда
    int numb_m = 0, numb_cm = 0, numb_d = 0, numb_cd = 0, numb_c = 0, numb_xc = 0, numb_l = 0, numb_xl = 0, numb_x = 0, numb_ix = 0, numb_v = 0, numb_iv = 0, numb_i = 0;

    int numb_arab = 0;

    std::cout << "Введите число : ";

    std::cin >> numb_arab;

    //сначала делим число на тысячу, чтобы узнать количество целых тысяч и записываем в переменную
    numb_m = numb_arab / 1000;
    numb_arab%=1000;

    //то же самое проделываем с 500
    if (numb_arab % 1000 >= 900){
        numb_cm++;
        numb_arab%=900;
    }
    else if (numb_arab % 1000 >= 500){
        numb_d++;
        numb_arab%=500;
    }
    else if (numb_arab % 1000 >= 400){
        numb_cd++;
        numb_arab%=400;
    }
    
    //чтобы найти количество сотен из числа
    numb_c = numb_arab / 100;
    numb_arab%=100;

    if (numb_arab % 100 >= 90){
        numb_xc++;
        numb_arab%=90;
    }
    else if (numb_arab % 100 >= 50){
        numb_l++;
        numb_arab%=50;
    }
    if (numb_arab % 100 >= 40){
        numb_xl++;
        numb_arab%=40;
    }


    numb_x = numb_arab / 10;
    numb_arab%=10;

    if (numb_arab % 10 >= 9){
        numb_ix++;
        numb_arab%=9;
    }
    else if (numb_arab % 10 >= 5){
        numb_v++;
        numb_arab%=5;
    }
    else if (numb_arab % 10 >= 4){
        numb_iv++;
        numb_arab%=4;
    }

    numb_i = numb_arab;

    std::string numb_rome="";


    for (int i= 0; i < numb_m; i++)

        numb_rome += "M";

    if (numb_d > 0)
    {
        numb_rome += "D";
    }
    if (numb_cd > 0)
    {
        numb_rome += "CD";
    }
    if (numb_cm > 0)
    {
        numb_rome += "CM";
    }

    for (int i = 0; i < numb_c; i++)

        numb_rome += "C";

    if (numb_l > 0)
    {
        numb_rome += "L";
    }
    if (numb_xc > 0)
    {
        numb_rome += "XC";
    }
    if (numb_xl > 0)
    {
        numb_rome += "XL";
    }

    for (int i= 0; i < numb_x; i++)

        numb_rome += "X";

    if (numb_v > 0)
    {
        numb_rome += "V";
    }
    if (numb_ix > 0)
    {
        numb_rome += "IX";
    }
    if (numb_iv > 0)
    {
        numb_rome += "IV";
    }

    for (int i= 0; i < numb_i; i++)

        numb_rome += "I";

    std::cout << "Римское число : ";

        std::cout << numb_rome<<std::endl;
    
        std::cout << std::endl;
}