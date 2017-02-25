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

inline void show_row_table(int row){
    ll num_columns = data[row].size();
    for(int j=0; j< num_columns; j++){
        cout << data[row][j]  << " ";
    }
    cout << endl;
}

/*
 * Show the hash table, each row represents a new hash
 */
inline  void show_hash_table(){
    for(int i=0; i< size_hash_table; i++){
        cout << i << " : " ;
        show_row_table(i);
    }
}

/*
 * Delete item in the hash table by number
 */
inline void delete_item(int number){
    /*
     * Logic for delete
     *  Find the position and interchange it with the las position
     *  Delete the item the item
     */
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

inline void write_hash_table(){
    write_file_hash(data);
}

/*
 * Show custom hash-generated table. 
 */
inline void show_custom_hash(vvi ne){

    for (int i = 0; i<ne.size(); i++){
        int s = ne[i].size();
        cout << i << " : ";
        for (int j = 0; j  < s; j++){
            cout << ne[i][j] << " ";
        }
        cout << endl;
    }
}

/*
 * Get locations in disk with the same hash
 * hash --> point out the hash
 */

inline vi get_locations(int hash){
    ll num_columns = data[hash].size();
    vi pos(num_columns);
    for(int j=0; j< num_columns; j++){
       pos[j] = data[hash][j];
    }
    return pos;
}


/*
 * Get the last position and interchange with the new location
 */

inline int change_greatest_location(int new_location){
    int aux =-1;
    int posx,posy;
    for (int i = 0; i<data.size(); i++){
        int cols = data[i].size();
        for (int j=0; j< cols; j++){
            if(data[i][j] > aux){
                aux = data[i][j];
                posx =i;
                posy =j;
            }
        }
    }
    cout << "The greatest location in disk is : " << aux << endl;
    cout << "Changing  location from " << aux << " to " << new_location << endl;
    data[posx][posy]=new_location;
    
}



