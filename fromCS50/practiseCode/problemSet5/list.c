// showcases use of list and malloc
// when time passes and new more memory is needed how, we can allot more memory and 
// copy old memory to new memory

#include <stdio.h>
#include <stdlib.h>
    int main()
    {
        int *list = malloc(3 * sizeof(int)); // 3 memory location of size int
        if(list == NULL){ //if memory cannot be allocated == NULL
            return 1;
        }

        list[0] = 1;       //list is initialized
        list[1] = 2;
        list[2] = 3;

        //time passes, more memory is needed
        //int *temp = malloc(4 * sizeof(int)); //temp memory is allocated
        // realloc would try to find space and reallocate it with more memory
        // hence no new memory needs to be allocated

        int *temp = realloc(list, 4 * sizeof(int));
        if(temp == NULL){ //checks if memory allocation is successful
            free(list); //super subtle but free successfully allocated memory before exiting program
            return 1;
        }

        /* // this was only needed for malloc temp; byt memory is reallocated and not new memory is allocated
        for(int i = 0; i < 3; i++){     // copies old memory to new temp memory
            temp[i] = list[i];
        }
        */
       
        temp[3] = 4;        // initializes another value
        
        free(list);         // frees old memory block
        list = temp;        // renames temp to list

        for(int i = 0; i < 4; i++){ // prints new memory
            printf("%d\n", list[i]);
        }

        free(list);     // finally new memory is freed too
        return 0;
    }