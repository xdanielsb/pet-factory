#define size_hash_table 1024



struct node{
    int pos ;
    node * next;
};

typedef node ** hash_table;


inline void show_linked_list(node *head){
    while (head != nullptr){
        cout << head->pos << " ";
        head = head->next;
    }
    cout << endl;
}

inline void show_hash_table (hash_table a ){
    for (int i=0 ; i< size_hash_table; i++){
        if (a[i]){
            show_linked_list(a[i]); 
        }else{
            cout << "That location does not exist";
        }
    }
}

inline void insert_linked_list(node * &linked, int p){
    node *n = new node;
    n->pos = p;
    n->next = nullptr;
    if (linked == nullptr){ //Void list
      //  cout << "The list is void " << endl;
      //  cout << "New head " << n->pos << endl;
        linked = n;
    }else {  //Case of collitions
      //  cout << "The list is not void " << endl;
      //  cout << "Inserting in the list " << n->pos << endl;
        node * aux = linked;
        while (aux->next != nullptr){
            aux = aux->next;
        }
        aux->next = n;
    }
}

inline hash_table get_hash_table(){
    hash_table positions;
    positions = new node* [size_hash_table];
    return positions;
}

