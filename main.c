#include <stdio.h>
#include <stdlib.h>
#include "fundeclar.h"
//#define UserName "shilpa"
//#define PassWord "123"
#include<string.h>

extern char UserName[20];
extern char PassWord[20];

char UserName[20]="shilpa";
char PassWord[20]="123";

extern book *head;
extern book *tail;

void dummy_Fun()//this is just a pointertoFun 0th index fun, called when user enter choice as zero
{
    printf(" Please enter valid choice\n");
    return;
}

int main()
{

    char username[15],password[15],c;
    int i=0;

    printf("Enter username:");
    scanf("%s",username);

    printf("Enter password:");
    while((c=getch())!= '\r')//this loop is to read character from user
    {
        password[i]=c;
        printf("*");//just printing * in console to hide password
        i++;
    }
    password[i]='\0';
    //scanf("%s",password);

    if(strcmp(UserName,username)== 0 && strcmp(PassWord,password)== 0)//if username & password matches then enters into system
    {
        printf("\nWelcome to Library Management System\n\n");
    }
    else
    {
        printf("\nWrong username or password\n");
        exit(0);
    }

    char chois[10];
    //declaring & initializing array pointer to functions
    void (*funptr[])()={dummy_Fun,add_Fun,delet_Fun,edit_Fun,search_Fun,issue_Fun,view_Fun,return_Fun,changPassword};

    choic://goto label name
    while(1)
    {
        printf("\n    Menu   \n");
        printf("---------------\n");
        printf("1:  Add book\n");
        printf("2:  Delete book\n");
        printf("3:  Edit book\n");
        printf("4:  Search book\n");
        printf("5:  Issue book\n");
        printf("6:  View book\n");
        printf("7:  Return book\n");
        printf("8:  Change password\n");
        printf("9:  Exit\n");

        printf("\nEnter your choice: ");
        int sf_val=scanf(" %10[0-9]+",chois);

        if(sf_val==0)
        {
            printf(" Please enter valid choice\n");
            return;
        }

        int choice=atoi(chois);

        if(choice==9)
        {
            exit(0);
        }
        else if(choice>9 || choice<0)//checking choices other than menu
        {
            printf(" *Warning: Entered choice is out of bound\n");
            printf("           Please enter valid choice\n");
            goto choic;
            //return;
        }

        (*funptr[choice])();//calling function based on user choice using fun_ptr
    }

    return 0;
}
