void PrintLogs()
{
    FILE* DataEntry;
    char SingleLine[50];
    DataEntry = fopen("DataEntry.txt","r+");
    printf("\nStart of logs");
    printf("\n=======================================\n");
    while (fgets(SingleLine, 50, DataEntry) != NULL)
        {
            printf("%s", SingleLine);
        }
    printf("End of logs");
    printf("\n");
    sleep(10);
}
