#include <iostream>
#include <locale.h>
#define is_range(x,y) ((((x)>=0)&&((x)<(y)))?true:false)
#define ell_arr(arr,i,j) (*( *( (arr) + (i) ) + (j) ))
void first_task(void);//Первое задание
void second_task(void);//Второе задание
int main()
{
    setlocale(LC_CTYPE, "");

    //first_task();
    second_task();
    return 0;
}
void first_task()
{
    int x, y;
    std::cout << "Введите Х:\n<";
    std::cin >> x;
    std::cout << "Введите Y:\n<";
    std::cin >> y;
    std::cout << std::boolalpha << is_range(x,y)<<"\n";
}
void second_task()
{
    int n, m;
    std::cout << "Введите кол-во строк:\n<";
    std::cin >> n;
    std::cout << "Введите кол-во столбцов:\n<";
    std::cin >> m;
    int** arr = new int*[n];
    for(int i=0;i<n;i++)
        arr[i] = new int[m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            arr[i][j]=rand()%15+1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << ell_arr(arr,1,2) <<"\n";
}
