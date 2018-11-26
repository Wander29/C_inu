#include <stdio.h>

void stampaChar(char s);
void func(int a, void (*nome)(char c), char ch);

int main()
{
    func(4, (*stampaChar), 'A');
}

void func(int a, void (*nome)(char c), char ch)
{
    if (a == 3)
        (*nome)(ch);
    else
        (*nome)(ch+32);
}

void stampaChar(char s)
{
    printf("%c\n", s);
}