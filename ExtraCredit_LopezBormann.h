#include <iostream>
#include <string.h>
#include <stdio.h>

void SecondAlgo(int allPreferences[10][5])
{
    int studentsChosen[5] = {0};                     // if the student has been chosen
    int studentAssignment[5] = {-1, -1, -1, -1, -1}; // what the student has been assigned to
    int alreadychosen[5] = {0};                      // If the Department has chosen
    int DeptAssignment[5] = {-1, -1, -1, -1, -1};    // what the Department has chosen

    for (int i = 0; i < 5; ++i) // Row
    {
        for (int j = 0; j < 5; ++j) // column
        {
            if (alreadychosen[j] == 0) // Department has not chosen
            {
                if (studentsChosen[allPreferences[i][j] - 1] == 0) // student is Available
                {
                    studentAssignment[allPreferences[i][j] - 1] = j; // Student is assigned to Department
                    studentsChosen[allPreferences[i][j] - 1] = 1;    // Student chosen is set to true
                    alreadychosen[j] = 1;                            // Department  changes to chosen
                }
                else // Student not available
                {
                    for (int k = 5; k < 10; ++k)
                    {

                        if ((studentAssignment[allPreferences[i][j] - 1] + 1) == allPreferences[k][allPreferences[i][j] - 1]) // if Previous index == Programmer Choice
                        {
                            break;
                        }
                        else if (j + 1 == allPreferences[k][allPreferences[i][j] - 1]) // if Current index == Programmer Choice
                        {
                            alreadychosen[studentAssignment[allPreferences[i][j] - 1]] = 0; // Reset old department to unchosen
                            alreadychosen[j] = 1;                                           // Set new department to chosen
                            studentAssignment[allPreferences[i][j] - 1] = j;                // assign student to new department
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 5; ++i) // Convert to Department Assignments
    {
        DeptAssignment[i] = studentAssignment[5 - i] + 1;
    }

    for (int i = 0; i < 5; ++i) // Output
    {
        std::cout << "Department #" << i + 1 << " will get programmer #" << DeptAssignment[i] << std::endl;
    }
}