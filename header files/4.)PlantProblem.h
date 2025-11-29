void PlantProblems()
 {
    int ProblemNumber;
    do
    {
        printf("\nWhat problem does your plant have?");
        printf("\n1.)Pale/Yellowish green leaves\n2.)Darker green leaves\n3.)Brown leaf tips/Reduced/slow plant growth\n4.)Brown spots on leaves");
        printf("\n5.)Purple spots on leaves\n6.)Small leaves\n7.)Reduced shoot growth\n8.)Wilting\n9.)Death of new leaves");
        printf("\nEnter the number Corresponding to the problem you are facing:");
        scanf("%d", &ProblemNumber);
    }while(ProblemNumber < 1 || ProblemNumber > 9);
    if (ProblemNumber == 1)
    {
        printf("\nYour plant could either be suffering from either\nNitrogen deficiency\n     or\nlight deficiency");
        printf("\nPlease look into the problem and solve it by either\nUsing a fertilizer with a higher Nitrogen concentration for a week if the problem is Nitrogen deficiency");
        printf("\n                           OR BY \nKeeping your plant in a place where it recieves plenty of sunlight if you think it doesnt in the place where its kept right now.");
    }
    else if(ProblemNumber == 2)
    {
        printf("\nYour plant could be suffering from either\nPhosphorus deficiency\n     or\nLow pH");
        printf("\nPlease look into the problem and solve it by either \nUsing a fertilizer with higher Phosphorus concentration for a week if the problem is Phosphorus deficiency");
        printf("\n                      OR BY \nUsing more water in your solutions to balance the pH if the problem is low pH.");
    }
    else if(ProblemNumber == 3)
    {
        printf("\nYour plant could be suffering from either\nPotassium deficiency\n     or\nwater deficiency");
        printf("\nPlease look into the problem and solve it by either\nUsing a fertilizer with a higher Potassium concentration for a week if the problem is Potassium deficiency");
        printf("\n                       OR BY \nSupplying the plant with a lot of water if the problem is water deficiency.");
    }
    else if(ProblemNumber == 4)
    {
        printf("\nYour plant could be suffering from either\nHigh pH\n     or\nLow pH");
        printf("\nPlease look into the problem and solve it by\nUsing more water in your solutions to balance the pH.");
    }
    else if(ProblemNumber == 5 || ProblemNumber == 6)
    {
        printf("\nYour plant could be suffering from Phosphorus deficiency\nUse a fertilizer with higher Phosphorus concentration for a week, this should solve the problem.");
    }
    else if(ProblemNumber == 7)
    {
        printf("\nYour plant could be suffering from Nitrogen deficiency\nUse a fertilizer with higher Nitrogen concentration for a week, this should solve the problem.");
    }
    else if(ProblemNumber == 8)
    {
	    printf("\nYour plant is suffering from water deficiency\nMake sure to water the plant more frequently.");
    }
    else if(ProblemNumber == 9)
    {
        printf("\nYour plant could be suffering from High pH\nMake sure to add more water in the solution to balance the pH.");
    }
    printf("\nYou will now be returned to the menu");
    sleep(5);
}
