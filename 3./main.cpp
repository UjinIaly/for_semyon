#include <iostream>

int main()
{
    int number = 0;
    std::cout<<"введите число"<<std::endl;
    std::cin>>number;

    int sum = 0;
    
    for( int i=0; i < number; ++i )
    {
        if (( i % 3 == 0 ) || ( i % 5 == 0 ))
        {   
            sum += i;
        }

    }
    std::cout << "сумма: " << sum << std::endl;

    return 0;
}