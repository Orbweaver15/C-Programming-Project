void Timer()
{
    int SleepTimeHours, SleepTimeMinutes, SleepTimeSeconds, SleepTime;
    printf("\nHow many hours would you like to keep the timer:");
    scanf("%d", &SleepTimeHours);
    printf("How many minutes would you like to keep the timer:");
    scanf("%d", &SleepTimeMinutes);
    printf("How many seconds would you like to keeo the timer:");
    scanf("%d", &SleepTimeSeconds);
    printf("Alarm has been set for %d hours, %d minutes and %d seconds from now.", SleepTimeHours, SleepTimeMinutes, SleepTimeSeconds);
    SleepTime = SleepTimeHours*3600 + SleepTimeMinutes*60 + SleepTimeSeconds;
    printf("\n");
    sleep(SleepTime);
    printf("\a");
    printf("Timer for %d seconds complete", SleepTime);
}
