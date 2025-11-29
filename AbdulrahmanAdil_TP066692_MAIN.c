#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

/*
______________________________________________________________________
____________________________INFORMATION_______________________________
Code by Abdulrahman Adil

TP No. TP066692

Assignment: Hydroponics system

Module: Introduction to C Programming

Done on onlinegbd.com with windows OS
_____________________________________________________________________
*/

void InputData();
void CheckControlSystems();
void ChangeControlSystems();
void CalculateAmounts();
void PlantProblems();
void WhichSetting();
void SettingValue();
void Timer();
int ValidationSetting();

int main()
{
    int Choice;
    do
    {
    printf("\n\n");
    printf("\n|____________________________________________|");
    printf("\n|        Hydroponics Data Entry System       |");
    printf("\n|____________________________________________|");
    printf("\n|    1.Input data into logs                  |");
    printf("\n|    2.Check/change control system settings  |");
    printf("\n|    3.Amount calculations                   |");
    printf("\n|    4.Plant problems & their solutions      |");
    printf("\n|    5.Print logs                            |");
    printf("\n|    6.Timer alarm                           |");
    printf("\n|    7.Exit system                           |");
    printf("\n|____________________________________________|");
    printf("\nEnter Number Corresponding To Your Choice: ");
    scanf("%d", &Choice);
    printf("Choice %d selected", Choice);
    switch(Choice)
        {
        case 1:
            printf("Input Data into system");
            InputData();
            break;
        case 2:
            CheckControlSystems();
            break;
        case 3:
            CalculateAmounts();
            break;
        case 4:
            PlantProblems();
            break;
        case 5:
            printf("\n\n");
            PrintLogs();
            break;
        case 6:
            Timer();
            break;
        case 7:
            printf("\nGood bye!");
            printf("\nExiting");
            exit(1);
        default:
            printf("\nInvalid choice! Try again.");
            break;
        }
    }while(Choice != 7); // Loops until choice is 7
}
