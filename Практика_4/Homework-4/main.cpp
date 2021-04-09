#include <iostream>
#include <locale.h>

using namespace std;
const int a3=10, b3=10;


int main()
{
    setlocale(LC_CTYPE, "");
    int input;
    while(true)
    {
        cout << "Выберете задание:\n1.Первое\n2.Второе\n3.Третье\n4.Четвертое\n0.Выход\n<";
        cin >> input;

        switch(input)
        {
            case 1:
            {
                //Первое задание
                cout << "Первое задание:\n";
                float a1, b1;//переменные для первого задания
                cout << "Введите первое число:\n>";
                cin >> a1;
                cout << "Введите второе число:\n>";
                cin >> b1;
                cout << (((a1+b1)>=10&&(a1+b1)<=20)?"True":"False")<<"\n";
                break;
            }
            case 2:
            {
                //Второе задание
                cout << "Второе задание:\n";
                int a2, ch=0;//Переменные для второго задания
                do{
                    cout << "Введите целое положительное число больше 1:\n>";
                    cin >> a2;
                }while(a2<=1);
                for(int i=2;i<=a2;i++)
                {
                    if(a2%i==0) ch++;
                    if(ch>1) break;
                }
                cout << ((ch>1)?"Не простое":"Простое") <<"\n";
                break;
            }
            case 3:
            {
                //Третье задание
                cout << "Третье задание:\n";
                cout << ((((a3==10)&&(b3==10))||((a3+b3)==10))?"Истина":"Ложь") <<"\n";
                break;
            }
            case 4:
            {
                //Четвертое задание
                cout << "Четвертое задание:\n";
                int year;
                bool flag=false;
                do{
                        cout << "Введите год:\n>";
                        cin >> year;
                }while(year<1);
                if (year%4==0)
                {
                        flag=true;
                        if((year%100==0)&&!(year%400==0)) flag = false;
                }
                cout << ((flag)?"Високосный":"Не високосный") << "\n";
                break;
            }
            case 0: return 0;
        }
    }
    return 0;
}
