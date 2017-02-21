#include <stdio.h>
#define NUM_DATA 1
FILE *data;

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
inline void read_hash_table(){
    data = fopen("var/hash.txt", "r");
    hash_table a;
    if (data != NULL) { //SUCCESS OPERATION?
        fread(&a,sizeof(animal),NUM_DATA,data);
        show_hash_table(a);
        fclose(data);
    }else{ 
        cout << "Error opening the data" << endl;
    }

}


