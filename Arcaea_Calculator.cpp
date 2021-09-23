#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#define D double
using namespace std;

void Pre();
void End();
void Menu();
void Wrong1();
void Wrong2();
void Check_ptt();
void Check_score();
D C_ptt(D d, int n);
D C_score(D a, D p, D b, D c);
void color(const unsigned short textColor);
void ConPrintAt(int x, int y, char *CharBuffer, int len);

int main()
{
    Pre();
    Menu();

    system("pause");
}

D C_ptt(D d, int n)
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

D C_score(D a, D p, D b, D c)
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
    system("mode con cols=70 lines=22");
    system("color fc");
}

void End()
{
    system("cls");
    ConPrintAt(26, 8, "??§Ý???????????\n", 20);
    ConPrintAt(26, 11, "???????EdisonBa\n", 18);
    Sleep(1700);
    exit(0);
}

void color(const unsigned short textColor)
{
    if (textColor >= 0 && textColor <= 15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Wrong1()
{
    ConPrintAt(26, 18, "??????§¹?????", 16);
    Sleep(400);
    system("cls");
}

void Wrong2()
{
    ConPrintAt(26, 18, "?????????????", 16);
    Sleep(400);
    system("cls");
}

void ConPrintAt(int x, int y, char *CharBuffer, int len)
{
    DWORD count;
    COORD coord = {x, y};
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, coord);
    WriteConsole(hStdOut, CharBuffer, len, &count, NULL);
}

void Menu()
{
    system("cls");
    ConPrintAt(20, 3, "Welcome to Arcaea_Calculator!!!\n", 33);
    ConPrintAt(19, 6, "???? 1 ???????????????????¡Â?\n", 33);
    ConPrintAt(19, 9, "???? 2 ?????¡Â????????? Ptt\n", 32);
    ConPrintAt(27, 12, "???? 0 ?????\n", 15);
    ConPrintAt(22, 15, "??????????????????\n", 26);
    ConPrintAt(32, 18, " ", 1);
    string opt;
    cin >> opt;
    if (opt[0] == '1')
        Check_score();
    else if (opt[0] == '2')
        Check_ptt();
    else if (opt[0] == '0')
        End();
    else if (opt[0] == EOF)
        Wrong2();
    else
        Wrong1();
    Menu();
}

void Check_ptt()
{
    system("cls");
    D d;
    int n;
    ConPrintAt(29, 4, "???? Ptt\n", 10);
    ConPrintAt(24, 8, "??????????", 12);
    cin >> d;
    ConPrintAt(24, 12, "??????¡Â??", 12);
    cin >> n;
    D ans = C_ptt(d, n);
    ConPrintAt(24, 16, "????Ptt???", 11);
    printf("%.4lf", ans);
    Sleep(600);
    ConPrintAt(48, 20, " ", 1);
    system("pause");
    Menu();
}

void Check_score()
{
    system("cls");
    D a, p, b, c;
    ConPrintAt(29, 3, "????¡Â?\n", 10);
    ConPrintAt(22, 6, "???????? PURE ??????", 20);
    cin >> a;
    ConPrintAt(22, 9, "??????? PURE ??????", 20);
    cin >> p;
    ConPrintAt(22, 12, "?????? FAR ??????", 17);
    cin >> b;
    ConPrintAt(22, 15, "?????? LOST ??????", 18);
    cin >> c;
    D ans = C_score(a, p, b, c);
    ConPrintAt(22, 18, "????????????", 14);
    printf("%08d", (int)ans);
    Sleep(600);
    ConPrintAt(48, 20, " ", 1);
    system("pause");
    Menu();
}
