#include <iostream>
#include <locale.h>
#include <math.h>
void five_task()
{

}
template <typename FirstArg, typename... Arg>
void five_task(FirstArg first_arg, Arg... arg)
{
    std::cout << (first_arg^1) <<" ";
    five_task(arg...);
}
void first_task(int*, int);
void second_task(int*,int);
void print_arr(int*,int);
bool third_task(int*,int);
void four_task(int*,int,int);
int sum_el_arr(int*,int);
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
void four_task(int* arr,int len,int n)//Четвертое задание
{
    int swap;
    if(n>0)//Положительное число - сдвигаем вправо
    {
        for(int i=0;i<n;i++)
        {
            for(int j=len-1;j>0;j--)
            {
                swap=*(arr+j-1);
                *(arr+j-1)=*(arr+j);
                *(arr+j)=swap;
            }
        }
    }
    else //Отрицательное - влево
    {
        for(int i=0;i<abs(n);i++)
        {
            for(int j=0;j<len-1;j++)
            {
                swap=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=swap;
            }
        }
    }
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
