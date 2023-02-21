#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ExtraCredit_LopezBormann.h"

int main()
{
    FILE *fp = fopen("matching-data.txt", "r");
    char line[64];
    int allPreferences[10][5];
    int input1, input2, input3, input4, input5;
    int i = 0;

    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%d\t%d\t%d\t%d\t%d", &input1, &input2, &input3, &input4, &input5); 

        allPreferences[i][0] = input1; 
        allPreferences[i][1] = input2; 
        allPreferences[i][2] = input3;
        allPreferences[i][3] = input4;
        allPreferences[i][4] = input5;
        i++;
    }

    PreferenceAlgo(allPreferences); 

    fclose(fp);
    return 0;
}