#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct linked_list
{
   int data;
   struct linked_list *next;
}   element;

typedef element * elementptr;

void trav_and_print(elementptr);
int count_elems(elementptr);
void just_checkin(elementptr, elementptr);
elementptr position_current(elementptr, int);

int main()
{
   elementptr first = NULL,
	         last = NULL,
            current,
            current_p,
            temp;
   int i;

   /* Create a linked list with one element            */
   /* NOTE: the first element is always a special case */

   first = (elementptr) malloc(sizeof(element));
   last = first;
   last -> data = 5;
   last -> next = NULL;

   
   /* Add other elements to the list by looping */

   for (i = 6; i <= 9; i++)
   {
      last -> next = (elementptr) malloc(sizeof(element));
      last = last -> next;
      last -> data = i;
      last -> next = NULL;
   }

   /* print linked list data values before insertion */

   printf("Before Insertion:\n"); 
   trav_and_print(first);
   printf("\n");

   /* Set up general code for random element deletion */

   current_p = position_current(first, count_elems(first)); // random pointer 
   printf("The random current -> data is %d\n", current_p -> data); // print random pointer for reference purposes
   printf("\n");
   current = first; // pre-allocate traversing pointer

   if (current_p == NULL) // error-check for linked list
      printf("There's no linked list.\n");
   else
   {
       if (current_p == first) // if the random pointer points to first element (or LL has 1 element only)
         {
            first = (elementptr) malloc(sizeof(element)); // re-assign first to point to another element  
            first -> data = 1000000; // assign value to data for this element
            first -> next = current_p; // link the new first element to the previous first element

         }
         else
         {
            while (current != NULL) // traverse linked list to find element before the random pointer and store it in temp
         {
            if (current -> next == current_p) 
               temp = current;
            current = current -> next;
         }
            temp -> next = (elementptr) malloc(sizeof(element)); // re-assign next-to-last to point to another element
            temp -> next -> data = 1000000; // assign value to new next-to-last element
            temp -> next -> next = current_p; // link new next-to-last element to last element

         }
   }

   /* print linked list data values after insertion */

   printf("After Insertion:\n"); 
   trav_and_print(first);
   printf("\n");

   free(first);
   free(last);

   return 0;
}

void trav_and_print(elementptr first) /* Function header and body for traversing linked list and printing data values */
{
   elementptr current = first; /* assign current pointer to first pointer to point to first element */

   if (current == NULL) /* error-check for linked list */
      printf("There's no linked list!\n");
   else
      while (current != NULL) /* loop through entire linked list and print data values */
      {
         printf("The data value is %d.\n", current -> data);
         current = current -> next; 
      }
}

int count_elems(elementptr first) /* Function header and body for counting number of elements in linked list */
{
   elementptr current = first;
   int count = 0; /* initialize count */
   while (current != NULL)
   {
      count++; /* increment count as linked list is traversed */
      current = current -> next;
   }
   return count;
}

void just_checkin(elementptr first, elementptr last)
{
   trav_and_print(first);
   printf("Number of elements: %d\n", count_elems(first));
   printf("first -> data is %d\n", first -> data);
   printf("last -> data is %d\n", last -> data);
}

elementptr position_current(elementptr first, int N)
{
   elementptr current = first,
              randomptr;
   int index, // random element index from 1 to N (total # of elements)
       count = 0; // initialize count as 0

   srand((unsigned int) time(NULL));
   index = rand()%N +1;

   if (current == NULL) // error-check for linked list 
      printf("There's no linked list!\n");
   else
       while (current != NULL) 
      {
         count++;
         if (index == count)
            randomptr = current;
         current = current -> next; 
      }
   return randomptr;
}







