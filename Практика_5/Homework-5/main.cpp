#include <iostream>
#include <locale.h>

void first_task(int*, int);
void second_task(int*,int);
void print_arr(int*,int);
bool third_task(int*,int);
int sum_el_arr(int*,int);
int main()
{
    setlocale(LC_CTYPE, "");
//    int arr[]={1,0,1,1,1,1,0,1,1};//Массив для первого задания
//    std::cout << "Оригинальный массив для первого задания:\n";
//    print_arr(arr,9);
//    first_task(arr,9);
//    std::cout << "Инвертированный массив для первого задания:\n";
//    print_arr(arr,9);//Функция печати массива для проверки
//    int arr2[8]{};//Массив для второго задания
//    second_task(arr2,8);
//    std::cout << "Заполненный массив для второго задания:\n";
//    print_arr(arr2,8);
    int arr3[]={6,6,1,13,26};
    if(third_task(arr3,sizeof (arr3)/sizeof(int))) std::cout << "True\n";
    else std::cout << "False\n";
    return 0;
}

void first_task(int* arr, int len)//Первое задание
{
    *arr=(*arr)^1;
    if(len-->1) first_task(arr+1,len);
}
void second_task(int* arr,int len)//Второе задание
{
    for(int i=0, j=1;i<len;i++, j+=3)
        *(arr+i)=j;
}
bool third_task(int* arr, int len)//Третье задание
{
    for(int i=0;i<len;i++)
    {
        if(sum_el_arr(arr,i+1)==sum_el_arr(arr+i+1,len-i-1)) return true;
    }
    return false;
}
int sum_el_arr(int* arr,int len)//Сумма элементов массива
{
    int sum=0;
    for(int i=0;i<len;i++)
        sum+=*(arr+i);
    return sum;
}
void print_arr(int* arr,int len)//Печать массива
{
    for(int i=0;i<len;i++)
        std::cout << arr[i]<<" ";
    std::cout << "\n";
}
