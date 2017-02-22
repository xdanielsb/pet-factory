#define size_hash_table 1024

static ll LOC = 0;
static vvi data(size_hash_table);
/*
 * This function creates a location in disk and assign 
 * writes the animal to the new location
 */
inline int get_code (){
    ll code =LOC;
    LOC++;
    return code;
}


/*
 * Show the hash table, each row represents a new hash
 */
inline  void show_hash_table(){
    for(int i=0; i< size_hash_table; i++){
        ll num_columns = data[i].size();
        cout << i << " : " ;
        for(int j=0; j< num_columns; j++){
            cout << data[i][j]  << " ";
        }
        cout << endl;
    }
}

/*
 * Delete item in the hash table by number
 */
inline void delete_item(int number){
    for (int i=0; i< size_hash_table; i++){
        ll num_columns = data[i].size();
        for(int j=0; j< num_columns; j++){
            if(data[i][j] == number){
                data[i].erase (data[i].begin()+j); //remove the j+1 elment
            }
        }
    }
}


/*
 * Check wether a number exist in the hash table
 */
inline bool exist(int number){
    for (int i=0; i< size_hash_table; i++){
        ll num_columns = data[i].size();
        for(int j=0; j< num_columns; j++){
            if(data[i][j] == number){
                return true;
            }
        }
    }
    return false;
}
