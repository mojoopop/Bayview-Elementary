/*File: bayviewApp.c
Author: Michael Wojtysiak
Description: Contains driver procedure to display the menu.
As well as the display menu procedure which is the base CLI
for the Bayview Elementary Student Record Keeper.
 */

#include <stdio.h>

#include "classRoster.h"
#include "attendence.h"
#include "whoCanISpeakTo.h"
#include "hallpass.h"

main()
{
    displayMenu();
}

displayMenu()
{
    int option;



    printf("\tWelcome to Bayview Elemntary School Database\t\n");
    printf("\n\n\nPlease select what you would like to do:\n");
    printf("\n1. Hall Pass\n2. Class Roster\n3. Attendence\n4. Who can I speak to?\n5. Close Program\n");

    printf("\nOption Selected(Press enter):");
    scanf("%d", &option);

    if (option == 1)
    {

        //initalize stack
        Stack* s = initStack();

HPLABEL:

        option = 0;
        system("cls");
        printf("\tHallpass\t\n\n");
        printf("\nPlease select what you would like to do:\n");
        printf("\n1. Sign Out\n2. Sign In\n3. View Last Student to Sign Out\n4. Where is my student?\n5. Previous Menu\n");

        printf("\nOption Selected(Press enter):");
        scanf("%d", &option);



        if (option == 1)
        {
            int fperson;
            int sperson;

            system("cls");
            printf("\nPlease enter your student number(XXXXXX): \n");
            scanf("%d", &fperson);

            printf("\n\nWhat is your hall buddies student number(XXXXXX)?\n");
            scanf("%d", &sperson);



            if (push(s, fperson) == 1 && push(s, sperson))
            {
                printf("\n%d You have been signed out with %d!\n", fperson, sperson);
            }

            sleep(2.5);
            goto HPLABEL;


        } else if (option == 2)
        {

            printf("\n%d Has signed in with his hall buddy: %d\n", pop(s), pop(s));

            sleep(2);
            goto HPLABEL;

        } else if (option == 3)
        {

            int curSigOut = peek(s);

            if (curSigOut == -1)
            {
                printf("\nStack Empty: Everyone is in class!\n");
                sleep(2);
            } else
            {
                printf("\n%d is currently signed out\n", peek(s));
                sleep(2);
            }
            goto HPLABEL;

        } else if (option == 4)
        {
            int sn, key, result = 0;
            Stack* tempStack = initStack();


            
            printf("\nEnter the student number: \n");
            scanf("%d", &key);

            //Find the key 
            while (!empty(s))
            {
                result = pop(s);
                push(tempStack, result);

                if (result == key)
                {
                    printf("\nStudent %d is not in class!\n");
                    break;
                }
            }
            
            //print a message if the key is not found in the stack.
            if(result != key)
            {
                printf("\nStudent: %d is in class!\n",key);
            }
            
            //Re-stack in the proper order
            while (!empty(tempStack))
            {
                push(s, pop(tempStack));
            }
            goto HPLABEL;


        } else if (option == 5)
        {
            system("cls");
            displayMenu();
        } else
        {
            system("cls");
            printf("\n\n\n\nYou have selected an invalid option. Please try again... ");
            sleep(2);
            system("cls");
            goto HPLABEL;
        }

    } else if (option == 2)
    {
        option = 0;
        system("cls");
        printf("\tClass Roster\t\n\n");
        printf("\nPlease select what you would like to do:\n");
        printf("\n1. Add Student\n2. Remove Student\n3. View Roster\n4. Previous Menu\n");

        printf("\nOption Selected(Press enter):");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Add Student");
            /*INSERT crAddStudent() METHOD HERE*/
        } else if (option == 2)
        {
            printf("Remove Student");
            /*INSERT crRemoveStudent() METHOD HERE*/
        } else if (option == 3)
        {
            printf("View Roster");
            /*INSERT crViewRoster() METHOD HERE*/
        } else if (option == 4)
        {
            system("cls");
            displayMenu();
        } else
        {
            system("cls");
            printf("You have selected an invalid option. Please try again... ");
            sleep(2);
            system("cls");
            displayMenu();
        }
    } else if (option == 3)
    {
        option = 0;
        system("cls");
        printf("\nAttendence\t\n\n");
        printf("\nPlease select what you would like to do:\n");
        printf("\n1. Present Student\n2. Student Dismissed\n3. View Attendence\n4. Previous Menu\n");

        printf("\nOption Selected(Press enter):");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Present Student");
            /*INSERT attStudPresent() METHOD HERE*/
        } else if (option == 2)
        {
            printf("Student Dismissed");
            /*INSERT attStudDismissed() METHOD HERE*/
        } else if (option == 3)
        {
            printf("View Attendence");
            /*INSERT attViewAttendence() METHOD HERE*/
        } else if (option == 4)
        {
            system("cls");
            displayMenu();
        } else
        {
            system("cls");
            printf("You have selected an invalid option. Please try again... ");
            sleep(2);
            system("cls");
            displayMenu();
        }
    } else if (option == 4)
    {
        option = 0;
        system("cls");
        printf("\tWho Can I Speak To?\t\n\n");
        printf("\nPlease select what you would like to do:\n");
        printf("\n1. Add Employee\n2. Remove Employee\n3. View Employees\n4. Find Employee\n5. Previous Menu\n");

        printf("\nOption Selected(Press enter):");
        scanf("%d", &option);

        if (option == 1)
        {
            printf("Add Employee");
            /*INSERT whoAddEmp() METHOD HERE*/
        } else if (option == 2)
        {
            printf("Remove Employees");
            /*INSERT whoRemEmp() METHOD HERE*/
        } else if (option == 3)
        {
            printf("View Employees");
            /*INSERT whoViewEmp() METHOD HERE*/
        } else if (option == 4)
        {
            printf("Find Employee");
        } else if (option == 5)
        {
            system("cls");
            displayMenu();
        } else
        {
            system("cls");
            printf("You have selected an invalid option. Please try again... ");
            sleep(2);
            system("cls");
            displayMenu();
        }
    } else if (option == 5)
    {
        int i;
        for (i = 0; i < 3; i++)
        {
            printf("Now closing program");
            if (i == 0)
            {
                system("cls");
                printf("Now closing program.");
                sleep(1);

            } else if (i == 1)
            {
                system("cls");
                printf("Now closing program..");
                sleep(1);
            } else
            {
                system("cls");
                printf("Now closing program...");
                sleep(1);
            }

        }
        exit(1);
    } else
    {
        system("cls");
        printf("You have selected an invalid option. Please try again... ");
        sleep(2);
        system("cls");
        displayMenu();
    }

}
