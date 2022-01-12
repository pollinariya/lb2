// Printer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct Paper
{
    char size[3] = "A4";
    int letter_size=10;
};



struct Electricity
{
    int voltage = 220;
};

struct TaskToPrint
{
    char text[3000];
    char required_paper_size[3] = "A4";
};
struct Printer
{
    struct Сartridge
    {
        int level;
    };

    char name[30];
    int paper_count=0;
    int require_voltage=210;
    Сartridge cartridge;
    Paper* paper;

    Printer(char name[30], int paper_count)
    {
        this->paper_count = paper_count;
        paper = new Paper[paper_count];
        for (int i = 0; i < paper_count; i++)
        {
            paper[i] =  Paper();
        }
        strcpy_s(this -> name, name);
        cartridge.level = 50;
       
    }
    void Print(TaskToPrint ttp, Electricity el)
    {
        if (el.voltage >= require_voltage)
        {
            if (cartridge.level > strlen(ttp.text) / paper[0].letter_size)
            {
                if ((strlen(ttp.text) / paper[0].letter_size) < paper_count)
                {
                    if (strcmp(ttp.required_paper_size, paper[0].size) == 0)
                    {
                        
                        cout << endl;
                        for (int i = 0; i < strlen(ttp.text); i++)
                        {
                            
                                if ((i % paper[0].letter_size == 0 && i != 0))
                                {
                                    paper_count--;
                                        cartridge.level--;
                                        cout << endl;
                                }
                                cout << ttp.text[i];
                            

                            
                           
                            
                           
                        }
                        cartridge.level --;
                        paper_count--;
                    }
                    else
                    {
                        cout << "\nНеправильный размер бумаги";
                    }
                }
                else {
                    cout << "\nНедостаточно бумаги";
                }
            }
            else { cout << "\nНе хватит картриджа"; };
        }
    }

    void PrinterInfo()
    {
        cout << endl<<endl<<name;
        cout <<"\t"<< paper_count;
        cout << "\t" << cartridge.level;
        cout << "\t" << paper[0].letter_size;
        cout << endl;
    }
    
    ~Printer()
    {
        delete[]paper;
    }
};


int main()
{

    //Смоделировать работу принтера.

   
    setlocale(LC_ALL, "RUS");

    char name[] = "Phillips";
    char text[] = "начинает сравнивать по одному символу и как только будут найдены первые неодинаковые символы, функция проанализирует числовые коды этих символов. Чей код окажется больше, та строка и будет считаться большей.";
    
    Printer *pr=new Printer(name,5000) ;
    TaskToPrint ttp;
    strcpy_s(ttp.text,text);
    
    Electricity el;
    pr->PrinterInfo();
       
    pr->Print(ttp, el);

    pr->PrinterInfo();
    //Загрузка новой бумаги другого размера
    Paper* paper = new Paper[40];
    char s[3] = "A1";
    pr->paper_count = 40;
    for (int i = 0; i < 40; i++)
    {
        paper[i] = Paper();
        strcpy_s(paper[i].size, s);
        paper[i].letter_size = 20;
    }
    delete[] pr->paper;
    pr->paper = paper;


    strcpy_s(ttp.required_paper_size, s);// Меняем размер бумаги в задании для принтера;
    pr->Print(ttp, el);
    pr->PrinterInfo();


   
    delete pr;
       
}
