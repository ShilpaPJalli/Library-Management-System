#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fundeclar.h"

void add_Fun()
{
    char Book_id[10];
    int check;
    char B_name[30],A_name[30];
    book *newBook=(book*)malloc(sizeof(book));//dynamically allocating memory to each new node

    printf("Enter book id:");
    scanf("%s",Book_id);

    float book_id=atof(Book_id);

    if(book_id==0)//checking whether input is string
    {
        printf(" *Warning: Please enter an integer value\n");
        return;
    }
    else
    {
        check=book_id;//used to check whether int
    }
    /*printf("id_val=%f\n",Id_val);
    printf("check=%d\n",check);*/

    if(check!=book_id)//condition for checking float or int
    {
        printf(" *Invalid input: please enter an integer value\n");
        return;
    }


    book *temp=head;
    while(temp!=NULL)//loop to check existing id
    {
        if(temp->bookId==book_id)//if book id is already exist then prompt warning
        {
            printf(" *Warning: Book_Id already exist\n");
            return;
        }
        temp=temp->next;
    }

    printf("Entr book name: ");
    int sf_val=scanf(" %30[a-zA-Z0-9 ]+[^\n]",B_name);


    if(sf_val==0)
    {
        printf(" Please enter valid book name\n");
        fflush(stdin);
        return;
    }

    //scanf(" %30[^\n]",newBook->bookName);

    printf("Enter Author name: ");
    int scf_val=scanf(" %20[.a-zA-Z0-9 ]+[a-z]+[^\n]",A_name);

    if(scf_val==0)
    {
        printf(" Please enter valid Author name\n");
        fflush(stdin);
        return;
    }

    book *temp1=head;
    while(temp1!=NULL)
    {
        //checking combination of book_name and author_name are same
        if(strcasecmp(temp1->bookName,B_name)==0 && (strcasecmp(temp1->authorName,A_name)==0))
        {
            printf(" *Warning: Combination of Book name & Author name already exist\n");
            return;
        }
        temp1=temp1->next;
    }

    newBook->bookId=book_id;
    strcpy(newBook->bookName,B_name);
    strcpy(newBook->authorName,A_name);
    strcpy(newBook->status,"Available");

    newBook->next=NULL;//inserting null to last node->next

    if(head==NULL)//if head is not pointing to any node
    {
        head=newBook;
        tail=newBook;
    }
    else
    {
        tail->next=newBook; //linking last node with newnode
        tail=newBook;
    }

}
