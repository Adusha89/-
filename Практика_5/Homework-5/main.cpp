#include <iostream>
#include <locale.h>

#include <math.h>
#include <iostream>
#include "foo.hpp"
using namespace HW5;


int main()
{
    setlocale(LC_CTYPE, "");
    int arr[]={1,0,1,1,1,1,0,1,1};//Массив для первого задания
    std::cout << "Оригинальный массив для первого задания:\n";
    void(*fpa)(int*,int)=print_arr;
    fpa(arr,sizeof (arr)/sizeof(int));
    void(*fft)(int*,int)=first_task;
    fft(arr,sizeof (arr)/sizeof(int));
    std::cout << "Инвертированный массив для первого задания:\n";
    fpa(arr,sizeof (arr)/sizeof(int));//Функция печати массива для проверки
    int arr2[8]{};//Массив для второго задания
    fft=second_task;
    fft(arr2,sizeof (arr2)/sizeof(int));
    std::cout << "Заполненный массив для второго задания:\n";
    fpa(arr2,sizeof (arr2)/sizeof(int));
    int arr3[]={6,6,1,13,26};
    std::cout << "Результат третьего задания:\n";
    bool(*ftt)(int*,int)=third_task;
    if(ftt(arr3,sizeof (arr3)/sizeof(int))) std::cout << "True\n";
    else std::cout << "False\n";
    int arr4[]={1,2,3,4,5,6};
    void(*frt)(int*,int,int)=four_task;
    frt(arr4,sizeof (arr4)/sizeof(int),3);
    std::cout << "Результат четвертого задания:\n";
    fpa(arr4,sizeof (arr4)/sizeof(int));
    std::cout << "Результат пятого задания:\n";
    five_task(1,1,0,0,1,0);//Пятое задание
    return 0;
}


