#include <iostream> 

int getodd(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++) {
         
        int count = 0;
         
        for (int j = 0; j < arr_size; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count % 2 != 0)
            return arr[i];
    }
    return -1;
}
 
int main()
    {
        int arr[] = { 0,1,0,1,0,1 };
        int n = sizeof(arr) / sizeof(arr[0]);
 
        std::cout << getodd(arr, n);
 
        return 0;
    }