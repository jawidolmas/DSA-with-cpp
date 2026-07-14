#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[10];
    char *characters[10];
    numbers[7]=458215911;
    numbers[10]=1254;
    printf("%d\n%d\n", numbers[7], numbers[10]);
    numbers[7]=1;
    printf("%d\n", numbers[7]);
    numbers[5]=19;
    printf("%d\n", numbers[5]);
    characters[5]="Jawid ";
    printf("%s", characters[5]);
    characters[8]="Olmas\n";
    printf("%s", characters[8]);
    char name[10];
    printf("Enter your name:");
    fgets(name,21, stdin);
    printf("Your name is %s \n", name);


    return 0;
}






