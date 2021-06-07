#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#define D double

void Pre();
void Menu();
D Check_ptt(D d, int n);
D Check_score(D a, D p, D b, D c);
void color(const unsigned short textColor);
void ConPrintAt(int x, int y, char *CharBuffer, int len);

int main()
{
    Pre();
    Menu();

    system("pause");
}

void Menu()
{
    system("cls");
    ConPrintAt(20, 3, "Welcome to Arcaea-Checker!!!\n", 29);

}

void color(const unsigned short textColor)
{
    if (textColor >= 0 && textColor <= 15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

D Check_ptt(D d, int n)
{
    const int PM = 10000000, EX = 9800000;
    if (n >= PM)
        return 2.0 + d;
    else
    {
        D ptt;
        if (n >= EX)
            ptt = 2.0 + d + ((n - PM) / 200000);
        else
            ptt = 1.0 + d + ((n - EX) / 300000);
        if (ptt > 0)
            return ptt;
        else
            return 0;
    }
}

D Check_score(D a, D p, D b, D c)
{
    double dan, sum, score;
    sum = a + b + c;
    dan = (10000000 + sum) / sum;
    if (p == 0)
        p = a;
    score = a * dan + 0.5 * b * dan - (a - p) - b;
    return score;
}

void Pre()
{
    system("mode con cols=70 lines=23");
    system("color fc");
}

void ConPrintAt(int x, int y, char *CharBuffer, int len)
{
    DWORD count;
    COORD coord = {x, y};
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, coord);
    WriteConsole(hStdOut, CharBuffer, len, &count, NULL);
}