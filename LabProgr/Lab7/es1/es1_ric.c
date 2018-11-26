#include <stdio.h>

#define DIM 10

int read_int();
void func();

int main()
{
    func();
    return 0;
}

int read_int()
{
    int temp = 0;
    while (scanf("%d", &temp) != 1)
    {
        while(getchar() != '\n');
    }
    return temp;
}

void func()
{   
    static int cnt;

    int temp = read_int();
    cnt ++;

    if(cnt == DIM)
    {
        printf("%d\n", temp % 2 == 0 ? temp/2 : temp);
        return;   
    }
    func();
    
    printf("%d\n", temp % 2 == 0 ? temp/2 : temp);
    return;
}