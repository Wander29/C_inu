#include <stdio.h>

int fa(void *);
int f2(void *);

void main() {
    int scelta;
    int (*f[2])(void *) = {fa, f2};
    while (scanf("%d", &scelta) != 1)
    {
        scanf("%*[^/n]%*c");
    }
    int var = 97;
    scelta = (*f[scelta])(&var);
    return;
}

int fa(void *var)
{
    printf("%d\n", *(int *)var);
    return 0;
}

int f2(void *var)
{
    printf("%c\n", *(char *)var);
    return 1;
}