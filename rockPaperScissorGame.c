#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randomNumberGenrate(int n)//it genrates a random number
{
    srand(time(NULL));
    return rand() % n;
}

void yourChoice(int n)//it is a function to tell you what you have chosen
{
    if (n == 0)
    {
        printf("You have choosen rock\n");
    }
    else if (n == 1)
    {
        printf("You have choosen paper\n");
    }
    else if (n == 2)
    {
        printf("You have choosen scissor\n");
    }
}

void comuterChoice(int n)//it is a function to tell you computer's choice
{
    if (n == 0)
    {
        printf("Computer has choosen rock\n");
    }
    else if (n == 1)
    {
        printf("Computer has choosen paper\n");
    }
    else if (n == 2)
    {
        printf("Computer has choosen scissor\n");
    }
}

int winner(int user, int comp)// it chooses the winner by getting both choices ours as well as computer's 
{
    if (user == 0 && comp == 1)//user rock and computer paper
    {
        return 1;
    }
    else if (user == 1 && comp == 2)//user paper and computer scissor
    {
        return 1;
    }
    else if (user == 2 && comp == 0)//user scissor and computer rock
    {
        return 1;
    }
    else if (user == comp)//both computer and user have made the same choice
    {
        return 2;
    }
    else//remaing possibilities
    {
        return 0;
    }
}
int main()
{
    int len, n, you = 0, comp = 0;
    void *ptr;
    printf("Enter the number of characters in your name including spaces\n");
    scanf("%d", &len);
    getchar();
    ptr = (char *)calloc(len + 1, sizeof(char));
    printf("Enter your name:  \n");
    gets(ptr);

    printf("RULES: \n");
    printf("If you chose rock you input 0\n");
    printf("If you chose paper you input 1\n");
    printf("If you chose scissor you input 2\n");

    printf("\nGAME STARS\n");
    printf("Player :  ");
    puts(ptr);

    for (int k = 0; k < 3; k++)
    {
        printf("\n\n%d Round\n", k + 1);
        printf("Your turn\n");
        scanf("%d", &n);
        getchar();
        yourChoice(n);
        int a = randomNumberGenrate(3);//random number for computer's choice
        comuterChoice(a);
        int x = winner(n, a);
        if (x == 0)
        {
            printf("You have won\n");
            you += 1;
        }
        else if (x == 2)
        {
            printf("It is a tie\n");
        }
        else if (x == 1)
        {
            printf("Computer has won\n");
            comp += 1;
        }
    }

    if (you > comp)
    {
        printf("\nYOU HAVE WON\n");
    }
    else if (you == comp)
    {
        printf("\nIT WAS A TIE\n");
    }
    else if (you < comp)
    {
        printf("\nCOMPUTER HAS WON\n");
    }
    printf("Your Score:  %d", you);
    printf("Computer's Score:  %d", comp);
    return 0;
}
