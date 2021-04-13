#include <iostream>
//namespace HW5
//{
int sum_el_arr(int*,int);
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

//}


