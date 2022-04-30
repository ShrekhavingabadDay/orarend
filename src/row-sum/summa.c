#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int row_counter(char * filename)
{
    FILE * f = fopen(filename, "r");
    char letter;
    int counter = 0;
    while(fscanf(f, "%c", &letter) == 1)
    {
        if(letter == '\n') counter ++;
    }
    fclose(f);
    return counter;
}
int main(int argc, char * argv[])
{
    int sum = 0;
    if(strcmp("--help", argv[1]) == 0 || strcmp("-help", argv[1]) == 0 || strcmp("h", argv[1]) == 0 || strcmp("-h", argv[1] )== 0 )
    {
        printf("Usage: ./test <texfile> <testfile1> .....\n");
        return 0;
    }
    else{
        for(int i = 1; i< argc ; i++)
        {
            sum = sum + row_counter(argv[i]);
        }
        FILE  * f = fopen("sum.txt", "w");
        fprintf(f, "Ennyi sor van: %d", sum);
        fclose(f);
        printf("Ennyi az osszes szam: %d\n", sum);
        }
    return 0;
}
