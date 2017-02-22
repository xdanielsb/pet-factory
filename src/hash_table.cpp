#define size_hash_table 1024

struct node{
    int pos ;
    node * next;
};

typedef node ** hash_table;


/*
 * Get hash table
 */
inline hash_table get_hash_table(){
    hash_table positions;
    positions = new node* [size_hash_table];
    return positions;
}

