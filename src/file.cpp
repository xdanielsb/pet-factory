#include <stdio.h>
#define NUM_DATA 1
FILE *data;


//
// THIS IS FOR THE DATA
//


inline void write_file(animal &a,int pos){
    data = fopen("var/data.bin", "wb");
    if (data != NULL) { //SUCCESS OPERATION?
        cout << "write pos:  " << pos << " * sizeof(animal)" <<  endl;
        fseek(data,sizeof(animal)*pos,SEEK_SET);
        fwrite(&a, sizeof(animal), NUM_DATA, data);
        fclose(data);
    }else{
        cout << "Error opening the data." << endl;
    }
}

inline void read_file(string name, int pos){
    data = fopen("var/data.bin", "rb");
    animal a;
    if (data != NULL) { //SUCCESS OPERATION?
        cout << "read pos:  " << pos <<  " * sizeof(animal)" << endl;
        fseek(data,sizeof(animal)*pos,SEEK_SET);
        fread(&a,sizeof(animal),NUM_DATA,data);
        cout << "Name: "<< a.name << endl;
        fclose(data);
    }else{ 
        cout << "Error opening the data" << endl;
    }

}


//
// THIS IS FOR HASH TABLES
//

/*
 * Write hash table in disk
 */
inline void write_hash_table(hash_table a){
    data = fopen("var/hash.txt", "w");
    if (data != NULL) { //SUCCESS OPERATION?
        fwrite(&a, sizeof(hash_table), NUM_DATA, data);
        fclose(data);
    }else{
        cout << "Error opening the hash table." << endl;
    }
}

/*
 * Read Hash table and load into memory
 */
inline hash_table read_hash_table(){
    data = fopen("var/hash.txt", "r");
    hash_table a;
    if (data != NULL) { //SUCCESS OPERATION?
        cout << "Loading hash table \n "<<  endl;
        fread(&a,sizeof(hash_table),NUM_DATA,data);
        
        //show_linked_list(a[0])
        //show_hash_table(a);
        fclose(data);
        return a;
    }else{ 
        cout << "Error opening the data" << endl;
        return nullptr;
    }

}


