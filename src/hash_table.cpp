#define size_hash_table 1024

struct linked_list{
    int pos ;
    linked_list * next;
};

inline void show_linked_list(linked_list *head){
    while (head != nullptr){
        cout << head->pos << " ";
    }
    cout << endl;
}


