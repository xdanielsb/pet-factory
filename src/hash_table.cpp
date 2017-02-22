#define size_hash_table 1024


static ll LOC = 0;
static vvi data(size_hash_table);

/*
 * This function creates a location in disk and assign 
 * writes the animal to the new location
 */
inline  int persist_register(animal a ){
    ll code =LOC;
    write_animal(a,code);
    LOC++;
    return code;
}


/*
 * Show the hash table, each row represents a new hash
 */
inline  void show_hash_table(){
    for(int i=0; i< size_hash_table; i++){
        ll num_columns = data[i].size();
        for(int j=0; j< num_columns; j++){
            cout << data[i][j]  << " ";
        }
        cout << i << " "<< num_columns << endl;
    }
}

