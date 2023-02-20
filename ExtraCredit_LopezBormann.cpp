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
        sscanf(line, "%d\t%d\t%d\t%d\t%d", &input1, &input2, &input3, &input4, &input5); // Subtracting 1 so that it is 0 indexed

        // Department Preference

        allPreferences[i][0] = input1; // Adding 5 to each input, so that the index will go from 0-9
        allPreferences[i][1] = input2; // where dept preferences are 0-4 and student preferences will be index 5-9
        allPreferences[i][2] = input3;
        allPreferences[i][3] = input4;
        allPreferences[i][4] = input5;
        i++;
    }

    SecondAlgo(allPreferences); // Gale-Shapley Algorithm

    fclose(fp);
    return 0;
}