#include <stdio.h>
#include <string>
#include <fstream>

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
        for (int i =0; i< size_hash_table; i++){
            node *aux = a[i];
            while (aux != nullptr){
                if(aux->pos !=0){
                    string val = to_string(aux->pos)+ ","; 
                    fwrite(val.c_str(), sizeof(val.c_str()), NUM_DATA, data);
                }
                aux = aux->next;
            }
            fwrite("\n", sizeof("\n"), NUM_DATA, data);
        }
        fclose(data);
    }else{
        cout << "Error opening the hash table." << endl;
    }
}

/*
 * Read Hash table and load into memory
 */
inline hash_table read_hash_table(){
    string line; 
    ifstream myfile ("var/hash.txt");
    const char *p;
    char *q;
    int counter = 0;
    
    hash_table a;
    if (myfile.is_open()) { //SUCCESS OPERATION?
        while(getline(myfile,line)){
            cout <<counter << " "<< line ;
            counter++;
            cout << endl;
        }
        
        return a;
    }else{ 
        cout << "Error opening the data" << endl;
        return nullptr;
    }

}


