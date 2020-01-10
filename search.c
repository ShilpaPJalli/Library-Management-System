#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "fundeclar.h"

typedef enum
{
    BookSearch=1,
    AuthorSearch,
    StatusSearch
}stateType;

stateType state;

void search_Fun()
{
    char B_Name[20],A_Name[20],Status[20];

    printf("Search book by \n");
    printf("  1: Book Name \n");
    printf("  2: Author Name\n");
    printf("  3: Status\n");
    int ch;
    printf("  Enter ur search choice: ");

    int val=scanf("%d",&state);

    if(val==0)
    {
        printf(" *please enter valid input\n");
        fflush(stdin);
        return;
    }

    //fflush(stdin);
    //state=ch;

    switch(state)
    {
        case BookSearch: printf("    Enter Book Name to search: ");
                         scanf(" %20[^\n]",B_Name);
                         break;
        case AuthorSearch: printf("    Enter Author Name to search: ");
                           scanf(" %20[^\n]",A_Name);
                           break;
        case StatusSearch: printf("    Enter status of book: ");
                           scanf(" %20[^\n]",Status);
                           break;
                default:   printf("  *Warning: Your choice is out of bound\n");
                            fflush(stdin);
                           return;
    }

    //scanf(" %20[^\n]",SearchName);

    book *temp=head;
    //printf("\n   Matched book list\n");
    //printf("-------------------------\n");
    printf("\nBook_Name      Author_Name     Status\n");
    printf("--------------------------------\n");
    while(temp!=NULL)
    {
        if((strncasecmp(temp->bookName,B_Name,2)==0) || (strncasecmp(temp->authorName,A_Name,2)==0) || (strncasecmp(temp->status,Status,3)==0))
        {
            printf("%-15s",temp->bookName);
            printf("%-15s",temp->authorName);
            printf("%s",temp->status);
            printf("\n");
        }
        temp=temp->next;
    }
    printf("-------------------------------\n");

}
