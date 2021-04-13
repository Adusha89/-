#include <math.h>
#include <iostream>

int sum_el_arr(int* arr,int len)//Сумма элементов массива
{
    int sum=0;
    for(int i=0;i<len;i++)
        sum+=*(arr+i);
    return sum;
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

void print_arr(int* arr,int len)//Печать массива
{
    for(int i=0;i<len;i++)
        std::cout << arr[i]<<" ";
    std::cout << "\n";
}
