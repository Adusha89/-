#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
void create(const char*);//Создание .txt
void con(fstream&,fstream&,fstream&);//Объединение файлов
void zap(fstream&);//Заполнение .txt
int value(fstream&);//Размер файла
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
    int raz=value(f)+value(f1);
    char* buf=new char [raz];
    f.clear();
    f.seekg( 0 );
    f1.clear();
    f1.seekg( 0 );
    f.getline(buf, raz);
    f1.getline((buf+value(f)),raz);
    cout << buf;
    b << buf;

}
int value(fstream& f)
{
    int i=0;
    f.clear();
    f.seekg( 0 );
    while(!f.eof())
    {
        f.get();
        i++;
    }
    return i-1;
}
