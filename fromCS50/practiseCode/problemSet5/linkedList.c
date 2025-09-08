#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            free(n); //free any memory already malloc'd
            return 1;
        }
        int num = 0;
        printf("Number: ");
        scanf("%d", &num);
        n->number = num;
        //n->next = list;
        //list = n;
        n->next = NULL;
        if(list == NULL)
        {
            list = n;
        }
        else{
            for(node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                //if at end of list
                if(ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    /*
    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }
    */
   for(node *ptr = list; ptr != NULL; ptr = ptr->next)
   {
    printf("%d\n", ptr->number);
   }
   node *ptr = list;
   while(ptr != NULL)
   {
    node *next = ptr->next;
    free(ptr);
    ptr = next;
   }

   return 0;
}