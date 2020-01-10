#include<stdio.h>
#include<string.h>
#include "fundeclar.h"

void return_Fun()
{
    char book_name[20];
    int found=0;


    printf("Enter name of the book which u want to return: ");
    scanf(" %20[^\n]",book_name);

    book *temp=head;

    while(temp!=NULL)
    {
         if((strcmp(temp->bookName,book_name)==0) && (strcmp(temp->status,"Issued")==0))
         {
             strcpy(temp->status,"Available");
             printf("Book returned successfully\n");
             found=1;
             break;
         }
         temp=temp->next;
    }
    if(found==0)
    {
        printf("Return book is Unsuccessfull :\n");
        printf("       - Book is not issued to return or Book is not from this library\n");
    }
}
