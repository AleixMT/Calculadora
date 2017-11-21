#include <stdio.h>
#include <stdlib.h>
#include <String.h>
// https://es.wikipedia.org/wiki/String.h
#include <stdbool.h>

int length;
bool sintax_validation(char op[], int length)
{
    char number[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i, j;
    bool nombrellegit = false;
    for (i = 0; i < length; i++)
    {
        for (j = 0; i < 10; i++)
        {
            if (op[i] == number[j])
            {
                nombrellegit = true;
                break;
            }
            else
            {
                nombrellegit = false;
            }
        }
        if (op[i] == '(' && nombrellegit)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FILE *f;
    f = fopen("proves.txt","rt");
    char op[256], c;
    int i;

    while (c!= EOF)
    {
        i = 0;
        while((c=fgetc(f))!='\n' && c != EOF )
        {
            if (c != ' ' && c != '\n' && c != EOF)
            {
                op[i] = c;
                i++;
            }
        }
        length = i;
    }

    fclose(f);
    return 0;
}
