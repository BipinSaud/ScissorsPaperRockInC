#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int getRandom(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main()
{
    // Array of strings representing the choices
    const char *choices[] = {"scissors", "rock", "paper"};

    int userChoice, continuePlaying = 1;

    printf("\n----------Lets play Scissors,Paper,Rock----------\n");

    while (continuePlaying)
    {
        printf("Choices you can make : \n1. Scissors\n2. Rock\n3. Paper\nEnter your choice: ");
        scanf("%d", &userChoice);

        // this validates user inpuut
        if (userChoice < 1 || userChoice > 3)
        {
            printf("Invalid choice. Please choose a number between 1 and 3.\n");
            continue; // Restart the loop
        }

        int computerChoice = getRandom(0, 2);

        printf("\tYour choice: %s\n", choices[userChoice]);
        printf("\tComputer's choice: %s\n", choices[computerChoice]);

        // Compare choices to determine the winner
        if (userChoice == computerChoice)
        {
            printf("\t\tIt's a tie!\n");
        }
        else if ((userChoice == 0 && computerChoice == 1) ||
                 (userChoice == 1 && computerChoice == 2) ||
                 (userChoice == 2 && computerChoice == 0))
        {
            printf("\t\tComputer wins!\n");
        }
        else
        {
            printf("\t\tYou win!\n");
        }

        // Ask user if they want to continue playing
        printf("Do you want to continue playing?\n1-yes\n0-no\nEnter your choice: ");
        scanf("%d", &continuePlaying);
    }

    printf("Thanks for playing!\n");

    return 0;
}
