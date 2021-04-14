
#ifndef FOO_HPP
#define FOO_HPP
#include <iostream>
namespace HW5
{
void print_arr(int*,int);


int sum_el_arr(int*,int);
void first_task(int*, int);
void second_task(int*,int);
bool third_task(int*,int);
void four_task(int*,int,int);
void five_task();

template <typename FirstArg, typename... Arg>
void five_task(FirstArg first_arg, Arg... arg)
{
    std::cout << (first_arg^1) <<" ";
    five_task(arg...);
}
}
#endif // FOO_HPP

