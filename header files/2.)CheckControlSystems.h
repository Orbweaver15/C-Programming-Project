#define FileNameSize 1024
#define MaxLine 3000

void CheckControlSystems()
{
    FILE *ControlFile = fopen("ControlFile.txt", "r");
    if(ControlFile == NULL)
    {
        FILE *ControlFile;
        char *pHLine[20];
        char *HumidityLine[20];
        char *LightingLine[20];
        char *TemperatureLine[20];
        int y;
        printf("\nThis is the first time the program is running, please setup the system settings.");
        printf("\nPlease enter the setting for pH,\nEnter one from 'increase', 'constant', 'decrease':");
        scanf("%s", pHLine);
        y = ValidationSetting(pHLine);
        while(y == 1)
        {
            printf("\nInvalid input!");
            printf("\nMake sure all letters are in lowercase :)");
            printf("\nPlease enter the setting for pH");
            printf("\nPlease enter one from 'increase', 'constant', 'decrease':");
            scanf("%s", pHLine);
            y = ValidationSetting(pHLine);
        }
        printf("\nPlease enter the setting for humidity,\nEnter one from 'increase', 'constant', 'decrease':");
        scanf("%s", HumidityLine);
        y = ValidationSetting(HumidityLine);
        while(y == 1)
        {
            printf("\nInvalid input!");
            printf("\nMake sure all letters are in lowercase :)");
            printf("\nPlease enter the setting for Humidity");
            printf("\nPlease enter one from 'increase', 'constant', 'decrease':");
            scanf("%s", HumidityLine);
            y = ValidationSetting(HumidityLine);
        }
        printf("\nPlease enter the setting for Lighting,\nEnter one from 'increase', 'constant', 'decrease':");
        scanf("%s", LightingLine);
        y = ValidationSetting(LightingLine);
        while(y == 1)
        {
            printf("\nInvalid input!");
            printf("\nMake sure all letters are in lowercase :)");
            printf("\nPlease enter the setting for Lighting");
            printf("\nPlease enter one from 'increase', 'constant', 'decrease':");
            scanf("%s", LightingLine);
            y = ValidationSetting(LightingLine);
        }
        printf("\nPlease enter the setting for temperature,\nEnter one from 'increase', 'constant', 'decrease':");
        scanf("%s", TemperatureLine);
        y = ValidationSetting(TemperatureLine);
        while(y == 1)
        {
            printf("\nInvalid input!");
            printf("\nMake sure all letters are in lowercase :)");
            printf("\nPlease enter the setting for Temperature");
            printf("\nPlease enter one from 'increase', 'constant', 'decrease':");
            scanf("%s", TemperatureLine);
            y = ValidationSetting(TemperatureLine);
        }
        ControlFile = fopen("ControlFile.txt", "a+");
        fprintf(ControlFile, "pH:        %s", pHLine);
        fprintf(ControlFile, "\nHumidity:  %s", HumidityLine);
        fprintf(ControlFile, "\nLight:     %s", LightingLine);
        fprintf(ControlFile, "\nTemp:      %s", TemperatureLine);
        fprintf(ControlFile, "\n");
        fclose(ControlFile);
        printf("\nSysterm settings setup complete\n");
    }
    else
    {
        char YesOrNo[5];
        char SingleLine[20];
        int result1, result2;
        int CurrentLine = 1;
        printf("\nCurrent control system settings are:");
        printf("\n");
        while (fgets(SingleLine, 50, ControlFile) != NULL)
        {
            printf("%s", SingleLine);
        }
        printf("\nWould you like to change any setting?");
        printf("\nEnter 'y' for yes and 'n' for no:");
        scanf(" %s", YesOrNo);
        result1 = strcmp(YesOrNo, "y");
        result2 = strcmp(YesOrNo, "n");
        while(result1 != 0 && result2 != 0)
        {
            printf("\nInvalid input!");
            printf("\nMake sure you enter in lowercase :)");
            printf("\nWould you like to change any setting?");
            printf("\nEnter 'y' for yes and 'n' for no:");
            scanf(" %s", YesOrNo);
            result1 = strcmp(YesOrNo, "y");
            result2 = strcmp(YesOrNo, "n");
        }
        if (result1 == 0)
        {
            printf("\nChoice y entered");
            ChangeControlSystems();
        }
        else if (result2 == 0)
        {
            printf("\nChoice n entered");
            printf("\nYou will now be returned to the menu");
        }
    }
}

void ChangeControlSystems()
{
    FILE *ControlFile = fopen("ControlFile.txt", "r");
    FILE *Temp;
    int validation, ParameterNumber;
    int CurrentLine = 1;
    char ParameterName[50];
    char SettingLevel[10];
    char FileName[FileNameSize] = "ControlFile.txt";
    char TempFileName[FileNameSize];
    char Buffer[MaxLine];
    fflush(stdin);
    printf("\nWhat would you like to change, \n1.)pH\n2.)Humidity\n3.)Lighting\n4.)Temperature\nEnter one from '1', '2', '3', '4':");
    scanf("%d", &ParameterNumber);
    while(ParameterNumber < 1 || ParameterNumber > 4)
    {
        printf("\nInvalid input,");
        printf("\nWhat would you like to change,\n1.)pH\n2.)Humidity\n3.)Lighting\n4.)Temperature\nEnter one from '1', '2', '3', '4':");
        scanf("%i", &ParameterNumber);
    }
    if(ParameterNumber == 1)
    {
        strcpy(ParameterName, "pH:        ");
    }
    else if(ParameterNumber == 2)
    {
        strcpy(ParameterName, "Humidity:  ");
    }
    else if(ParameterNumber == 3)
    {
        strcpy(ParameterName, "Light:     ");
    }
    else if(ParameterNumber == 4)
    {
        strcpy(ParameterName, "Temp:      ");
    }
    printf("\nWhat would you like to change the setting to,\nPlease enter one from 'increase', 'constant', 'decrease':");
    scanf(" %s", SettingLevel);
    validation = ValidationSetting(SettingLevel);
    while(validation == 1)
    {
        printf("\nInvalid input,");
        printf("\nMake sure you enter in lowercase :)");
        printf("\nPlease enter one from 'increase', 'constant', 'decrease':");
        scanf("%s", SettingLevel);
        validation = ValidationSetting(SettingLevel);
    }
    strcat(ParameterName, SettingLevel);
    strcpy(TempFileName, "Temp");
    strcat(TempFileName, FileName);
    Temp = fopen("Temp.txt", "w");
    bool KeepReading = true;
    do
    {
        fgets(Buffer, MaxLine, ControlFile);
        if (feof(ControlFile))
        {
            KeepReading = false;
        }
        else if (CurrentLine == ParameterNumber)
        {
            fputs(ParameterName, Temp);
	        fprintf(Temp, "\n");
        }
        else
        {
            fputs(Buffer, Temp);
        }
	CurrentLine++;
    }while(KeepReading);
    printf("Changes made, you will be returned to the menu\n");
    fclose(ControlFile);
    remove(ControlFile);
    rename(Temp, "ControlFile.txt");
    fclose(Temp);
}

int ValidationSetting(char* input[20])
{
    int result1, result2, result3;
    result1 = strcmp(input, "increase");
    result2 = strcmp(input, "constant");
    result3 = strcmp(input, "decrease");
    if(result1 != 0 && result2 != 0 && result3 != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
