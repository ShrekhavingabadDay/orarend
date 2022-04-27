#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    int a = 0;
    int sum = 0;
    printf("Add meg a sorszamokat...:\n");
    while (scanf("%d", &a) == 1)
    {
        sum = sum + a;
    }
    FILE  * f = fopen(argv[1], "w");
    fprintf(f, "%d", sum);
    fclose(f);
    printf("Ennyi az osszes szam: %d\n", sum);
    return 0;
}
