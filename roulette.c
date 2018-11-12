#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

//global variables
int money, bet;

//randomNumber generator function
int randomNumber ()
{   
    int timer = 0;
    while (timer < 4){
        printf(".\n");
        sleep(1);
        timer++;
    }
    srand (time (0));
    int num = (rand () % (36 - 0 + 1)) + 0;
    printf("%d\n", num);
num = 0;
    return num;
}

//tracks the amount
void amount ()
{
    printf ("Balance = %d\n", money);
    printf ("Bet = %d\n", bet);
}

int difficultyChoice()
{
    int selection, moneyback;
    printf("Choose difficulty\n");
    printf("1 - Easy (Minimum bet 1 of euro)\n");
    printf("2 - Normal (Minimum bet of 10 euros)\n");
    printf("3 - Hard (Minimum bet of 20 euro)\n");
    while (selection < 1 || selection > 3){    
        scanf("%d", &selection);
        if (selection == 1){
            moneyback = 1;
        }
        else if (selection == 2){
            moneyback = 10;
        }
        else if (selection == 3){
            moneyback = 20;
        }
        else{
            printf("That's not the right amount.\n");
        }
    }
    return moneyback;
}

//MainMenu explanation
void MainMenu ()
{
    printf ("Choose an option\n");
    printf ("b - amount of the bet\n");
    printf ("n - bet on a specific number (35-1)\n");
    printf ("e - bet on even numbers (2-1)\n");
    printf ("o - bet on odd numbers (2-1)\n");
    printf ("r - roll\n");
    printf ("h - help\n");
    printf ("s - show balace\n");
    printf ("c - cashout and go home\n");
}
 
int main ()
{
    money = 100;
    bet = 0;
    int numb, choice, difficulty;
    char input;
    difficulty = difficultyChoice();
    //Player choice/ menu interaction
    MainMenu ();
    amount ();
    while (input != 'c' && money != 0 && money >= difficulty){
        scanf (" %c", &input);
        //if player chooses "b"
        if (input == 'b'){
            printf ("How much do you want to bet?\n");
            scanf ("%d", &bet);
            if (bet > money || bet < difficulty){
                printf ("Wrong amount of money\n");
            }
            else {
	            printf ("Your bet is %d euros\n", bet);
	        }
        }
        //Player choses "n"
        else if (input == 'n'){
	        printf ("Choose number between 0 and 36\n");
	        scanf ("%d", &numb);
	        choice = 1;
	        if (numb < 0 || numb > 36){
	            printf ("I said between 0 and 36\n");
	            choice = 0;
	        }
	    }

        //Player choses "e"
        else if (input == 'e'){
	        printf ("We're even.\n");
	        choice = 2;
        }

        //Player choses "o"
        else if (input == 'o'){
	        printf ("That's an odd bet.\n");
	        choice = 3;
        }

        //Player choses "r"
        else if (input == 'r' && bet == 0){
	        printf ("Hey! Money first!!!\n");
	    }
        else if (input == 'r' && bet != 0){
	        if (choice == 1){
	            int num = randomNumber ();
	            if (numb == num && num != 0){
                    printf ("Bring the fireworks. You Won!!!\n");
                    money = money + (bet * 35);
                    bet = 0;
                    choice = 0;
	            }
                else{
                    printf ("Time to go home and cry, or lose more. You lost!!!\n");
                    money = money - bet;
                    bet = 0;
                    choice = 0;
	            }
            }
            else if (choice == 2){
                int num = randomNumber ();
                if (num % 2 == 0 && num != 0){
                    printf ("Bring the fireworks. You Won!!!\n");
                    money = money + (bet * 2);
                    bet = 0;
                    choice = 0;
                }
                else{
                    printf ("Time to go home and cry, or lose more. You lost!!!\n");
                    money = money - bet;
                    bet = 0;
                    choice = 0;
                }
    	    }
    	    else if (choice == 3){
    	        int num = randomNumber ();
    	        if (num % 2 == 1 && num != 0){
    	            printf ("Bring the fireworks. You Won!!!\n");
    	            money = money + (bet * 2);
    	            bet = 0;
    	            choice = 0;
    	        }
                else{
    	            printf ("Time to go home and cry, or lose more. You lost!!!\n");
    	            money = money - bet;
    	            bet = 0;
    	            choice = 0;
                }
            }
            else if (choice == 0){
                printf("You didn't tell me what do you want to bet on.");
            }
	    }
        else if (input == 'h'){
	        MainMenu ();
        }
        else if (input == 's'){
	        amount ();
        }
        else if (input == 'c'){
            printf("You got out with %d euros! impressive!!!\n", money);
        }
        else{
            printf ("Choose a valid option.\n");
        }
    }
    if (money == 0){
        printf("You're broke, don't worry, we won't tell your wife!\n");
    }
    else if (money < difficulty){
        printf("You're too poor to bet on anything!\n");
        
    }
    printf("FIN\n");
    return 0;
}
