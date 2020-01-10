#include<stdio.h>
#include "fundeclar.h"

void view_Fun()
{
    book *temp=head;
    printf("\nId      Book_name      Author_Name    Status\n");
    printf("---------------------------------------------");
    while(temp!=NULL)
    {
        printf("\n");
        printf("%d",temp->bookId);
        printf("       %-15s",temp->bookName);
        printf("%-15s",temp->authorName);
        printf("%s",temp->status);
        temp=temp->next;
    }
    printf("\n---------------------------------------------\n");
}
