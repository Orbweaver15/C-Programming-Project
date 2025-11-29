void CalculateAmounts()
{
    float MrX, NumberOfAtomsOfX, MrTotal, SemiAmount, FinalAmount;
    printf("\nEnter atomic mass of the element u want to find the amount of, enter 3 decimal places:");
    scanf("%f", &MrX);
    printf("Enter number of atoms of the element that are present in the fertilizer:");
    scanf("%f", &NumberOfAtomsOfX);
    printf("Enter total atomic mass of the compound in the fertilizer:");
    scanf("%f", &MrTotal);
    SemiAmount = MrX*NumberOfAtomsOfX/MrTotal;
    FinalAmount = SemiAmount*100;
    printf("\nYou have %fgrams of the element in 100g of the compound", FinalAmount);
    printf("\nor in other words, the fertilizer contains %f%% of the element", FinalAmount);
}
