Use a trie

every node for a trie contains an array of node pointers

if the next node is null then the

node indicates whether it is the last letter

typedef struct node
{
    bool is_word;
    stuct node *children[27];

}
node;

node *root;

for every dictionary word iterate through the trie

each element in children corresponds to a different letter
check the value at children[i]
    if null, malloc a new node, have children[i] point to it
    if not NULL, move to a new node and continue
if at the end of word, set is_word to true

"fox"

f: root -> children[5]
o: root-> children{5] -> children[14]
x: root->children[5] ->children[14]->children[23]





