#define size_hash_table 1024

static linked_list hash_table_data [size_hash_table];

struct linked_list{
    int pos=NULL;
    linked_list * next;
}

inline void show(linked_list *head){
    while (head != NULL){
        cout << head->pos << " ";
    }
    cout << endl;
}


