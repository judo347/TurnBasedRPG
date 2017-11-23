#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>

#define CAMPCHANCE 4 /* CHANCE OF GETTING INTO CAMP */

#define EXITMODE 0
#define MAINMENUMODE 1
#define CAMPMODE 2
#define FIGHTMODE 3

/* TRY JENER METHOD OF STRUCTING */
struct character
{
    char name[20];
    int health;
    int attack;
};

typedef struct character character;


int rng(int possible);
void clearScr(); /* CLEARS THE SCREEN */
character firstPlayerCreation(character person);
character getCharacterName(character player);
int mainMenu(); /* returns: 0 = new game, 1 = load game, 2 = exit */
int campAccess(int campValue); /* 0 = enter without roll, 1 = roll */
int campAccess2();
int campMenu();

/*
ToDo:
Let user choose player name.

BUGS:
I campMenu() - crasher hvis man ikke trykker noget før man vaelger inventory.

*/

int main()
{
    srand(time(NULL));


    int state = MAINMENUMODE; /* 0 = exit game, 1 = main menu, 2 = camp, 3 = fight */
    int mainMenuChoice;
    int campValue = 0; /* 0 = enters camp without roll */
    int campReturn;

    while(state != EXITMODE)
    {
        if(state == MAINMENUMODE) /* MAIN MENU */
        {
            mainMenuChoice = mainMenu();
            if(mainMenuChoice == 0) /* NEW GAME = GO TO CAMP */
            {
                state = CAMPMODE;
                character player;
                player = getCharacterName(player);
                player = firstPlayerCreation(player);
                printf("%s, %d, %d\n", player.name, player.health, player.attack);
            }
            else if(mainMenuChoice == 1) /* LOAD GAME*/
                printf("LOAD GAME: THIS FUNCTION HAS NOT YET BEEN CREATED!\n");
            else if(mainMenuChoice == 2) /* EXIT GAME */
                state = EXITMODE;
        }
        else if(state == 2) /* CAMP */
        {
            campReturn = campAccess(campValue);
            if(campReturn == 9) /* 9 = did not get into camp  = RETURN TO FIGHT*/
                state = FIGHTMODE;
            else if(campReturn == 2) /* RETURN TO FIGHT */
                state = FIGHTMODE;
            else if(campReturn == 3) /* EXIT GAME */
                state = EXITMODE;
            else
                printf("SOMETHING WENT VERY WRONG!!\n");

        }
        else if(state == FIGHTMODE)
        {
            /* FIGHT */
        }
    }

    printf("You chose to close the game!\n");
    return 0;
}

/* HELP-FUNCTIONS SECTION */

int rng(int possible)
{
    return possible = rand() % possible;
}

void clearScr() /* CLEARS THE SCREEN */
{
    system("@cls||clear");
}

/* PRE-LAUCH SECTION */
int mainMenu()
{
    int choice = 0, input1, input2;
    while(1)
    {
        printf("Welcome to the Turn Based RPG: with focus on items!\n");
        (choice == 0) ? (printf("\t  ->NEW GAME<-\n")) : (printf("\t   new game\n")); /* MARKED THEN UNMARKED */
        (choice == 1) ? (printf("\t->LOAD GAME<-\n")) : (printf("\t   load game\n"));
        (choice == 2) ? (printf("\t   ->EXIT<-\n")) : (printf("\t    exit\n"));
        input1 = getch(); input2 = getch(); /* NEED SECOND BYTE */
        //printf("%d, %d\n", input1, input2); /* TEMP */
        switch (input2) {
            case 72: if(choice > 0) choice--; break; /* ARROW - UP */
            case 80: if(choice < 2) choice++; break; /* ARROW - DOWN */
            case 13: return choice; break; /* ENTER */
        }
        clearScr();
    }
}

character firstPlayerCreation(character player)
{
    player.health = 100;
    player.attack = 10;

    return player;
}

character getCharacterName(character player)
{
    printf("Please enter a character name:\n");
    scanf("%s", player.name);

    return player;
}

/* CAMP SECTION */

int campAccess(int campValue)
{
    int campReturn = 9;
    if(campValue == 0)
        campReturn = campAccess2();
    else if(campValue == 1) {
        if(rng(CAMPCHANCE) != 0) /* CHANCE OF GETTING INTO CAMP */
            campReturn = campAccess2();
        else
            printf("No camp for you!\n");
    }

    return campReturn;
}

int campAccess2()
{
    int choice = 0;

    while(choice < 2)
    {
        choice = campMenu();

        if(choice == 0)
            printf("%s\n", "OPEN THE INVENTORY MENU!");
        if(choice == 1)
            printf("%s\n", "GAME SAVED!");
    }

    return choice;

}

int campMenu()
{
    int currentPlace = 0, input1, input2, choice = 9;
    /* COZY GRAPHIC */
    while(choice == 9)
    {
        //Sleep(600); /* TMEP */
        clearScr();
        printf("Hello traveller, welcome to the camp!\n");
        printf("What is your desired action?\n");
        (currentPlace == 0) ? (printf("\t  ->INVENTORY<-\n")) : (printf("\t   inventory\n")); /* MARKED THEN UNMARKED */
        (currentPlace == 1) ? (printf("\t->SAVE GAME<-\n")) : (printf("\t   save game\n"));
        (currentPlace == 2) ? (printf("\t->RETURN TO FIGHTING<-\n")) : (printf("\t   return to fighting\n"));
        (currentPlace == 3) ? (printf("\t   ->EXIT<-\n")) : (printf("\t    exit\n"));
        input1 = getch(); input2 = getch(); /* NEED SECOND BYTE */
        //printf("%d, %d\n", input1, input2); /* TEMP */
        switch (input2) {
            case 72: if(currentPlace > 0) currentPlace--; break; /* ARROW - UP */
            case 80: if(currentPlace < 3) currentPlace++; break; /* ARROW - DOWN */
            case 13: choice = currentPlace; break; /* ENTER */
        }
    }
    return choice;
}



