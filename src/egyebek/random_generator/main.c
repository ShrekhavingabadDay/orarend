#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define lenght 15
/* 
enum Subject
{
    English,
    Math,
    History,
    Chemistry,
    Biology,
    Phisics,
    PE,
};*/
char * subjects(int enum_num)
{
   char subject_name[lenght];
   char  * back;
   switch (enum_num) 
   {
    case 0:strcpy(subject_name, "English");back = subject_name;return  back;break;
    case 1:strcpy(subject_name, "Math");back = subject_name;return  back;break;
    case 3:strcpy(subject_name, "History");back = subject_name;return back;break;
    case 4:strcpy(subject_name, "Chemistry");back = subject_name;return  back;break;
    case 5:strcpy(subject_name, "Biology");back = subject_name;return back;break;
    case 6:strcpy(subject_name, "Phisics");back = subject_name;return  back;break;
    case 7:strcpy(subject_name, "PE");back = subject_name;return back;break;
    default : return NULL;break;
   };   
}
void writer(char * file_name,int limit )
{
    srand(time(NULL));
    FILE * f = fopen(file_name, "w");
    for(int i = 0; i < limit; i++)
    {
        int num;
        num = rand();
        num = num % 7;
        char * subject_name =  subjects(num);
        fprintf(f,"%s\n",subject_name);
    }
    fclose(f);
}
int main(int argc, char * argv[])
{
    char filname[] = "test.txt";
    int number = 0;
    printf("How many row would you like to have?:\n");
    scanf("%d", &number);
    writer(filname, number);
    printf("Generation has been finished....\n");
    return 0;
}
