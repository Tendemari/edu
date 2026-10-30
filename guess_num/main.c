#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int mode;
    printf("GUESS NUMBER!\n");
    printf("Choose mode (1 for programm random number or 2 for your random number): ");
    scanf("%d", &mode);

    if (mode == 1)
    {
        int random_num = rand() % 1000 + 1;

        printf("I pick a number between 1 and 1000, you should try to guess it\n");

        int user_input = 0;
        int guess_count = 0;
        do
        {
            printf("Your turn: ");
            scanf("%d", &user_input);

            ++guess_count;

            if (user_input == random_num)
                printf("Guessed!\n");
            else if (user_input < random_num)
                printf("My number is bigger\n");
            else if (user_input > random_num)
                printf("My number is smaller\n");
        } while (user_input != random_num);
        
        printf("Congratulations, you win! Guess count: %d\n", guess_count);
    }
    else if (mode == 2)
    {
        printf("You pick a number between 1 and 1000, I should try to guess it\n");

        int random_num = 0;
        while (random_num > 1000 || random_num < 1)
        {
            printf("Choose number: ");
            scanf("%d", &random_num);
        }
        
        char user_input;
        int programm_input = 0;
        int min = 1;
        int max = 1000;
        int guess_count = 0;
        do
        {
            programm_input = rand() % (max - min + 1) + min;

            ++guess_count;

            printf("Is it %d? (>, <, =): ", programm_input);
            scanf(" %c", &user_input);

            if (user_input == '=')
                printf("Guessed!\n");
            else if (user_input == '>')
                max = programm_input - 1;
            else if (user_input == '<')
                min = programm_input + 1;
        } while (programm_input != random_num);
        
        printf("I win! Guess count: %d\n", guess_count);
    }

    return 0;
}