#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
void create(const char*);//Создание .txt
void con(fstream&,fstream&,fstream&);//Объединение файлов
void zap(fstream&);//Заполнение .txt
int value(fstream&);//Размер файла
void search(void);
int main()
{
    const char name[]="file.txt";
    const char name1[]="file1.txt";
    const char boof[]="boof.txt";
    create(name);
    create(name1);
    create(boof);
    fstream f(name), f1(name1),b(boof);
    zap(f);
    zap(f1);
    con(f,f1,b);
    f.close();
    f1.close();
    b.close();

    return 0;
}
void create(const char* name)//Создание .txt
{
    ofstream f(name);
    f.close();
}
void zap(fstream& f)//Заполнение файла .txt
{
    char sym;
    for(int i=0;i<rand()%149+50;i++)
    {
        sym=rand()%77+48;
        f << sym;
    }
}
void con(fstream& f,fstream& f1,fstream& b)//Объединение файлов
{
    int raz1=value(f);
    int lenght=raz1+value(f1);
    char* buf=new char [lenght];
    f.read(buf,lenght);
    f1.read((buf+raz1),lenght);
    b.write(buf,lenght);
    delete []buf;

}
int value(fstream& f)//Размер файла
{
    int i=0;
    f.seekg(0,ios::end);
    i=f.tellg();
    f.seekg(0,ios::beg);
    return i;
}
void search()
{
    char name3[50];
    char sword;
    cout << "Введите название файла\n";
    cin >> name3;
    cout << "Введите слово для поиска\n";
    cin >> sword;
}
