#include <iostream>
#include <locale.h>

#include "foo.hpp"
void five_task()
{

}
template <typename FirstArg, typename... Arg>
void five_task(FirstArg first_arg, Arg... arg)
{
    std::cout << (first_arg^1) <<" ";
    five_task(arg...);
}

int main()
{
    setlocale(LC_CTYPE, "");
    int arr[]={1,0,1,1,1,1,0,1,1};//Массив для первого задания
    std::cout << "Оригинальный массив для первого задания:\n";
    print_arr(arr,sizeof (arr)/sizeof(int));
    first_task(arr,sizeof (arr)/sizeof(int));
    std::cout << "Инвертированный массив для первого задания:\n";
    print_arr(arr,sizeof (arr)/sizeof(int));//Функция печати массива для проверки
    int arr2[8]{};//Массив для второго задания
    second_task(arr2,sizeof (arr2)/sizeof(int));
    std::cout << "Заполненный массив для второго задания:\n";
    print_arr(arr2,sizeof (arr2)/sizeof(int));
    int arr3[]={6,6,1,13,26};
    std::cout << "Результат третьего задания:\n";
    if(third_task(arr3,sizeof (arr3)/sizeof(int))) std::cout << "True\n";
    else std::cout << "False\n";
    int arr4[]={1,2,3,4,5,6};
    four_task(arr4,sizeof (arr4)/sizeof(int),3);
    std::cout << "Результат четвертого задания:\n";
    print_arr(arr4,sizeof (arr4)/sizeof(int));
    std::cout << "Результат пятого задания:\n";
    five_task(1,1,0,0,1,0);//Пятое задание
    return 0;
}


