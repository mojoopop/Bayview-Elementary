/*File: bayviewApp.c
Author: Michael Wojtysiak
Description: Contains driver procedure to display the menu.
As well as the display menu procedure which is the base CLI
for the Bayview Elementary Student Record Keeper.
 */

#include <stdio.h>
#include <string.h>

#include "classRoster.h"
#include "attendence.h"
#include "whoCanISpeakTo.h"
#include "manageEmployees.h"

main() {
    displayMenu();
}

displayMenu() {
    int option;



    printf("\tWelcome to Bayview Elemntary School Database\t\n");
    printf("\n\n\nPlease select what you would like to do:\n");
    printf("\n1. Manage Employees\n2. Class Roster\n3. Attendence\n4. Who can I speak to?\n5. Close Program\n");

    printf("\nOption Selected(Press enter):");
    scanf("%d", &option);

    if (option == 1) {

        //initalize stack
        Stack* s = initStack();

HPLABEL:

        option = 0;

        printf("\tManage Employees List\t\n\n");
        printf("\nPlease select what you would like to do:\n");
        printf("\n1. Hire\n2. Fire\n3. View least senior employeee\n4. Is this person hired?\n5. Previous Menu\n");

        printf("\nOption Selected(Press enter):");
        scanf("%d", &option);



        if (option == 1) {
            int fperson;

            printf("\nPlease enter an employee number to hire: \n");
            scanf("%d", &fperson);
            push(s, fperson);
            
            printf("\n%d has been hired!\n\n", fperson);
            sleep(2);
            goto HPLABEL;
            
        } else if (option == 2) {

            printf("\n%d has been fired!\n\n", pop(s));
            sleep(2);
            goto HPLABEL;

        } else if (option == 3) {

            int curSigOut = peek(s);

            if (curSigOut == -1) {
                printf("\nStack Empty: No employees added yet!\n");
                sleep(2);
            } else {
                printf("\n%d is next to be let go!\n", peek(s));
                sleep(2);
            }
            goto HPLABEL;

        } else if (option == 4) {
            int sn, key, result = 0;
            Stack* tempStack = initStack();



            printf("\nEnter the employee number: \n");
            scanf("%d", &key);

            //Find the key 
            while (!empty(s)) {
                result = pop(s);
                push(tempStack, result);

                if (result == key) {
                    printf("\n%d is currently employed!\n\n", result);
                    sleep(3);
                    break;
                    
                }
            }

            //print a message if the key is not found in the stack.
            if (result != key) {
                printf("\nEmployee %d is not currently employed!\n", key);
                sleep(2);
            }

            //Re-stack in the proper order
            while (!empty(tempStack)) {
                push(s, pop(tempStack));
            }
            goto HPLABEL;


        } else if (option == 5) {
            system("cls");
            displayMenu();
        } else {
            system("cls");
            printf("\n\n\n\nYou have selected an invalid option. Please try again... ");
            sleep(2);
            system("cls");
            goto HPLABEL;
        }

    } else if (option == 2) {
        option = 0;
        
        CRLABEL:
        printf("\tClass Roster\t\n\n");
        printf("\nPlease select what you would like to do:\n");
        printf("\n1. Add Student\n2. Remove Student\n3. View Roster\n4. Previous Menu\n");

        printf("\nOption Selected(Press enter):");
        scanf("%d", &option);

        if (option == 1) {
            
            insertStart();
            sleep(2);
            goto CRLABEL;
            
        } else if (option == 2) {
            
            deleteStart(); 
            sleep(2);
            goto CRLABEL;
            
        } else if (option == 3) {        
            displayRoster();
            sleep(5);
            goto CRLABEL;
            
        } else if (option == 4) {
            
            sleep(2);
            goto CRLABEL;
            
        } else {
            system("cls");
            printf("You have selected an invalid option. Please try again... ");
            sleep(2);
            system("cls");
            displayMenu();
        }
    } else if (option == 3) {

        option = 0;
        Queue* q = initQueue();
QLABEL:

        printf("\nAttendence\t\n\n");
        printf("\nPlease select what you would like to do:\n");
        printf("\n1. Admit Student\n2. Student Dismissed\n3. View Attendence\n4. Previous Menu\n");

        printf("\nOption Selected(Press enter):");
        scanf("%d", &option);


        if (option == 1) {
            
            int present;
            printf("\nEnter the student # that is present(Press enter after each student): ");
            scanf("%d", &present);

            
            printf("\nStudent %d has been admitted\n\n", enqueue(q, present));
            sleep(2);
            goto QLABEL;

        } else if (option == 2) {
            
            int dqItem = dequeue(q);

            printf("\nStudent: %d dismissed\n\n", dqItem);
            sleep(2);
            goto QLABEL;


        } else if (option == 3) {
            printf("\n\n\View Attendence\t\n");
            viewAttend(q);
            goto QLABEL;
        } else if (option == 4) {
            
            displayMenu();
        } else {

            printf("\n\nYou have selected an invalid option. Please try again... \n\n\n");
            sleep(2);
            goto QLABEL;
        }
    } else if (option == 4) {
        option = 0;
        system("cls");
        printf("\tWho Can I Speak To?\t\n\n");
        printf("\nPlease select what you would like to do:\n");
        printf("\n1. Add Employee\n2. Remove Employee\n3. View Employees\n4. Find Employee\n5. Previous Menu\n");

        printf("\nOption Selected(Press enter):");
        scanf("%d", &option);

        if (option == 1) {
            printf("Add Employee");
            /*INSERT whoAddEmp() METHOD HERE*/
        } else if (option == 2) {
            printf("Remove Employees");
            /*INSERT whoRemEmp() METHOD HERE*/
        } else if (option == 3) {
            printf("View Employees");
            /*INSERT whoViewEmp() METHOD HERE*/
        } else if (option == 4) {
            printf("Find Employee");
        } else if (option == 5) {

            displayMenu();
        } else {

            printf("You have selected an invalid option. Please try again... ");
            sleep(2);

            displayMenu();
        }
    } else if (option == 5) {
        int i;
        for (i = 0; i < 3; i++) {
            printf("\n\n\nNow closing program\n\n");
            if (i == 0) {
                
                printf("Now closing program.\n\n");
                sleep(1);

            } else if (i == 1) {
                
                printf("Now closing program..\n\n");
                sleep(1);
            } else {
                
                printf("Now closing program...\n");
                sleep(1);
            }

        }
        exit(1);
    } else {
        system("cls");
        printf("You have selected an invalid option. Please try again... ");
        sleep(2);
        system("cls");
        displayMenu();
    }

}
