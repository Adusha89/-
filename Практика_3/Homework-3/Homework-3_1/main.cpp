#include <iostream>

using namespace std;
extern const int a,b,c,d; //Третье задание
int main()
{

    int input, i,j,k;
    int arr[3][3][3]={0};
    int* p;
    cout <<"Результат первого задания: "<< (float)a*((float)b + ((float)c / (float)d)) << endl;//Первое задание
    cout << "Введите целое число:\n";
    cin >> input;
    cout <<"Результат второго задания: "<< ((input>21)?(2*(input-21)):(input-21))<< endl;//Второе задание
    //cout << "Введите значения массива:"<<endl;
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
            for(k=0;k<3;k++)
            {
                //cout << "Введите элемент arr["<<i<<"]["<<j<<"]["<<k<<"]"<<endl;
                //cin >>arr[i][j][k];
                arr[i][j][k]=rand()%15+1;//заполнение массива случайными числами от 1 до 15
            }
    p=&arr[1][1][1];
    cout <<"Результат четвертого задания: "<<*p<<endl;//Четвертое задание
    cout << arr[1][1][1]<<endl;//Проверка
    return 0;
}
