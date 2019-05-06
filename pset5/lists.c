 single linked list
 key thing to note is the self referencial nature of the list
 keep track of pointer to list in a global variable to avoid losing it


 typedef struct sllist
 {
     value val;
     struct sllist* next;
 }sllnode;

 create a linked list

 sllnode* create(VALUE val);
    dynamically allocate space for a new sllnode with malloc
    check to make sure we didn't run out of memory
        check if it was null
    initialize the nodes val field

    intiialize the nodes next field
        null pointer
    return a pointer to the newly created sllnode


search through a linked list to find an element
    bool find(sllnode* head, VALUE val);

        create a traversal pointer pointing to the list's head
        if the current nodes val field is what we're looking for report success
        if not set the traversal pointer to the next pointer in the list and go back to step b

        this is linear search implemented with a singly linked list rather than an array

        no random access to a linked list because location is not known the way it is with an array where consitutents are findable by index









