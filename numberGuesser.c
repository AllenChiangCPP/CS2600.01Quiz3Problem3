#include <stdio.h> //this file is source code
#include <stdlib.h>
#include <time.h>
//guessingGame function, takes an int as the max number
int guessingGame(int max)
{
    //randomly generates a number based on int max using srand and rand
    srand(time(NULL)); //function to make rand() not generate in a fixed pattern
    int guessingNumber = rand() % max + 1; //generate a random number from 0-2 for the column row
    printf("Guess the number. max: %d\n", max); //remind user max number inputted
    //encased in a while loop, exits and returns to menu in main on a win
    while(1) //while loop for the game
    {
        char exitCheck; //char for checking for q to exit and ot stop chars from over printing
        int userGuess; //int for storing user input
        scanf("%d", &userGuess); //get user input int
        exitCheck = getchar(); //getchar to catch character inputs and for checking for q input
        //if user types q exits out loop which exits out function
        if (exitCheck == 'q') //check if user input q, if so break and end function
        {
            break;
        }
        else if (userGuess == guessingNumber) //check if equal, if so print correct and end function
        {
            printf("Correct!\n");
            break; 
        }
        //prints too high or too low based on player inputted guessed, takes user input
        else if (userGuess < guessingNumber) //check if too low
        {
            printf("Too low.\n");
        }
        else if (userGuess > guessingNumber) //check if too high
        {
            printf("Too high.\n");
        }
    }
    return 0;
}
int main() 
{
    int gameRunning = 1;
    int userGamePick = 0;
    //max number in main as an int, intial value of 10
    int maxNumber = 10;
    //encase entire program in while loop, should continue the game if 1 or 2 is selected
    //use file to save and read in data
    FILE * finout;
    while(gameRunning == 1)
    {
        while(1) //while loop for getting user input
        {
            printf("Press 1 to play the game\nPress 2 to change the max number\nPress 3 to quit\n");
            int userGameInput; //int for storing user input
            scanf("%d", &userGameInput); //get user input
            if (userGameInput == 1 || userGameInput == 2 || userGameInput == 3) //check if user input is a 1,2,or 3
            {
                userGamePick = userGameInput;
                break; //break out of loop to end question
            }
            printf("INVALID RESPONSE\n"); //print invalid response if user inputs an invalid answer
            getchar(); //prevent char input from ending program prematurely 
        }
        //if else statements for picking 1:play game, 2: change max number, and 3: quit
        //if 1 is picked: play game, function
        if(userGamePick == 1)
        {
            guessingGame(maxNumber);
        }
        //if 2 is picked: change max number in main and restart the loop
        if(userGamePick == 2)
        {
            while(1) //while loop for getting user input
        {
            int userNewMax; //int for storing user input
            printf("Enter new maximum amount.(default: 10, max: 100)\n");
            scanf("%d", &userNewMax); //get user input
            if (userNewMax >= 0 && userNewMax <= 100) //check if user input is a 1,2,or 3
            {
                maxNumber = userNewMax;
                break; //break out of loop to end question
            }
            printf("INVALID RESPONSE\n"); //print invalid response if user inputs an invalid answer
            getchar(); //prevent char input from ending program prematurely 
        }
        }
        //if 3 is picked: exit loop and rest of the program
        if(userGamePick == 3)
        {
            printf("Thank you for playing, goodbye. \n"); 
            gameRunning = 0; 
            break; //break out of question loop
        }
    }
} 
