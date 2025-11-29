typedef struct Contitions
{
    int DigitalPin1;//pH input
    int DigitalPin2;//Humidity input
    int DigitalPin3;//Lighting input
    int DigitalPin4;//Temperature input 
}Conditions;

void InputData()
{
    Conditions lettuce;
    FILE *DataFile;
    char Name[30];
    char* NamePointer;
    printf("\nPlease enter your last name:");
    scanf("%s", Name);
    NamePointer = &Name[0];
    printf("Please enter the pH:");
    scanf("%d", &lettuce.DigitalPin1);
    while (lettuce.DigitalPin1 < 0 || lettuce.DigitalPin1 > 14)
    {
        printf("Invalid value entered");
        printf("\nPlease enter the pH:");
        scanf("%d", &lettuce.DigitalPin1);
    }
    printf("Please enter the humidity in percentage:");
    scanf("%d", &lettuce.DigitalPin2);
    while (lettuce.DigitalPin2 <= 0 || lettuce.DigitalPin2 > 100)
    {
        printf("Invalid value entered");
        printf("\nPlease enter the humidity in percentage:");
        scanf("%d", &lettuce.DigitalPin2);
    }
    printf("Please enter the amount of Lighting in hours:");
    scanf("%d", &lettuce.DigitalPin3);
    while (lettuce.DigitalPin3 < 0 || lettuce.DigitalPin3 > 24)
    {
        printf("Invalid value entered");
        printf("\nPlease enter the amount of lighting in hours:");
        scanf("%d", &lettuce.DigitalPin3);
    }
    printf("Please enter the temperature in celcius:");
    scanf("%d", &lettuce.DigitalPin4);
    while (lettuce.DigitalPin4 <= 0 || lettuce.DigitalPin4 >= 70)
    {
        printf("Invalid value entered");
        printf("\nPlease enter the temperature in celcius:");
        scanf("%d", &lettuce.DigitalPin4);
    }
    if(lettuce.DigitalPin1 < 6 || lettuce.DigitalPin1 > 7 )
    {
        printf("\npH is not optimal, please maintain a pH of 6.0-7.0");
    }
    if(lettuce.DigitalPin2 < 50 || lettuce.DigitalPin2 > 70)
    {
        printf("\nHumidity is not optimal, please maintain a Humidity of 50-70%%");
    }
    if(lettuce.DigitalPin3 != 6)
    {
        printf("\nLighting is not optimal, please give the plant 6 hours of Light.");
    }
    if(lettuce.DigitalPin4 < 10 || lettuce.DigitalPin4 > 21)
    {
        printf("\nTemperature isn't optimal, please maintain a Temperature of 10-21°C");
    }
    time_t t;
    time(&t);
    DataFile = fopen("DataEntry.txt", "a+");
    fprintf(DataFile, "Operator name:%s", NamePointer);
    fprintf(DataFile, "\npH:           %d", lettuce.DigitalPin1);
    fprintf(DataFile, "\nHumidity:     %d %%", lettuce.DigitalPin2);
    fprintf(DataFile, "\nLighting:     %d Hours", lettuce.DigitalPin3);
    fprintf(DataFile, "\nTemperature:  %d°C", lettuce.DigitalPin4);
    fprintf(DataFile, "\nTime of entry:%s",ctime(&t));
    fprintf(DataFile, "=======================================\n");
    fclose(DataFile);
}
