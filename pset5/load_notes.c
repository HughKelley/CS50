
    create alphabetical index + '

    declare a new trie, using definition from dictionary.h

    open dictionary file

    for words in dictionary

        read one letter at a time?

        if null
            it's the end of a word go to next one
        else
            find first letters alphabetical index value

            look for that value in trie
                if not there malloc space for it and define it
                else, get pointer value
                next



    node in trie, contains 27 pointers, each letter in alphabet and ' character as '\''
    also contains boolean for word ending or not



    //speller passes dictionary path dictionary/large

    for every dictionary word, iterate through the trie
    each element in children corresponds to a different letter
    check the value at children[i]
        if null, malloc a new node, have children[i] point to it
        if not null, move to new node and continue
    if at end of word, set is-word to true

    dog

    d

    for loop to find d index number

    root-> children[index number]





    count words in dict as shortcut for size

    open dictionary file

    define a variable for characters

    define trie structure

    grab first character of first word

    get index number for that character

    check if that index number has a pointer
        if it does follow it
        if it does not



    fopen



    fread
    globally declare root as a trie node

    then set trav equal to the global root node

    typedef struct node
    {
        bool is_word;
        struct node *children[27];
    }
    node;

    node *root;

    use word as its own key

    malloc
    free

    how to turn characters into array indices



