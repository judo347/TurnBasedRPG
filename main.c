#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>

#define CAMPCHANCE 4 /* CHANCE OF GETTING INTO CAMP */

//#include <conio.h>

void clearScr(); /* CLEARS THE SCREEN */
int mainMenu(); /* returns: 0 = new game, 1 = load game, 2 = exit */
int campAccess(int campValue); /* 0 = enter without roll, 1 = roll */
int campAccess2();
int campMenu();

//FIX: failing at main manu? enter?=?
//Working on:CAMP og CAMPACCESS

int main()
{
    srand(time(NULL));

    int mainMenuChoice = mainMenu();

    if(mainMenuChoice == 2) /* EXIT GAME */
        return 0;
    else if(mainMenuChoice == 1) /* LOAD GAME */
    {
        printf("This function has not yet been created: LOAD GAME\n");
        return 0;
    }
    else if(mainMenuChoice == 0)
    {}    /*The game wil start as a new one */
    else
    {
        printf("The game failed at the mainMenu choice!\n");
        return 0;
    }



    int campValue = 1; /* 0 = enters camp without roll */

    int campReturn;
    campAccess(campValue);

    if(campReturn == 3)
        return 0;
    if(campReturn == 2)
        printf("%s\n", "You will be returning to a fight!");

    return 0;
}

int rng(int possible)
{
    return possible = rand() % possible;
}

int campAccess(int campValue)
{
    int campReturn;
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

    do {
        int choice = campMenu();
        printf("THE RETURNED VALUE FROM CAMPMENU!! %d\n", choice); /* TEMP */

        if(choice == 0)
            printf("%s\n", "OPEN THE INVENTORY MENU!");
        else if(choice == 1)
            printf("%s\n", "GAME SAVED!");
        else
            return 0;
    } while(choice >= 0 && choice <= 2);

    return choice;
}

int campMenu()
{
    int choice = 0, input1, input2;
    //clearScr();
    /* COZY GRAPHIC */
    while(1)
    {
        printf("Hello traveller, welcome to the camp!\n");
        printf("What is your desired action?\n");
        (choice == 0) ? (printf("\t  ->INVENTORY<-\n")) : (printf("\t   inventory\n")); /* MARKED THEN UNMARKED */
        (choice == 1) ? (printf("\t->SAVE GAME<-\n")) : (printf("\t   save game\n"));
        (choice == 2) ? (printf("\t->RETURN TO FIGHTING<-\n")) : (printf("\t   return to fighting\n"));
        (choice == 3) ? (printf("\t   ->EXIT<-\n")) : (printf("\t    exit\n"));
        input1 = getch(); input2 = getch(); /* NEED SECOND BYTE */
        //printf("%d, %d\n", input1, input2); /* TEMP */
        switch (input2) {
            case 72: if(choice > 0) choice--; break; /* ARROW - UP */
            case 80: if(choice < 3) choice++; break; /* ARROW - DOWN */
            case 13: return choice; break; /* ENTER */
        }
        //clearScr();
    }

}

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

void clearScr() /* CLEARS THE SCREEN */
{
    system("@cls||clear");
}
