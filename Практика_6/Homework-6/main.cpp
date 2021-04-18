#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
void create(const char*);//Создание .txt
void con(fstream&,fstream&,fstream&);//Объединение файлов
void zap(fstream&);//Заполнение .txt
size_t value(fstream&);//Размер файла
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
    search();
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
    size_t raz1=value(f);
    size_t lenght=raz1+value(f1);
    char* buf=new char [lenght];
    f.read(buf,lenght);
    f1.read((buf+raz1),lenght);
    b.write(buf,lenght);
    delete []buf;

}
size_t value(fstream& f)//Размер файла
{
    size_t i=0;
    f.seekg(0,ios_base::end);
    i=f.tellg();
    f.seekg(0,ios_base::beg);
    return i;
}
void search()
{
    char name3[50], sword[50];
    fstream f;
    bool flag=false;

    while(true)
    {
        cout << "Введите название файла (myfile.txt)\n";
        cin >> name3;
        f.open(name3);
        if(f.is_open()) break;
        cout << "Файл не открыт\n";

    }
    size_t lenght=value(f);
    char* boof = new char[lenght];
    cout << "Введите слово для поиска\n";
    cin >> sword;
    while(!f.eof())
    {
        f >> boof;
        for(int i=0;sword[i]!='\0';i++)
        {

            if(sword[i]==boof[i]) flag=true;
            else
            {
                flag=false;
                break;
            }
            if(((boof[i+1]=='\0')&&(sword[i+1]!='\0'))||((boof[i+1]!='\0')&&(sword[i+1]=='\0')))
            {
                flag=false;
                break;
            }
        }
        if(flag) break;
    }
    if(flag) cout << "Слово "<<sword<<" есть в файле\n";
    else cout << "Слова "<<sword<<" нет в файле\n";
    delete []boof;
    f.close();
}
