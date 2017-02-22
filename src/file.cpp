#include <stdio.h>
#include <string.h>
#include <fstream>  //ifstream
#include <stdlib.h> //strtok
#include <sstream>
#include <vector>

#define NUM_DATA 1
FILE *myfile;


//
// THIS IS FOR THE DATA
//


inline void write_file(animal a,int pos){
    myfile = fopen("var/data.bin", "ab+");
    if (myfile != NULL) { //SUCCESS OPERATION?
        cout << "write pos:  " << pos << " * sizeof(animal)" <<  endl;
        fseek(myfile,sizeof(animal)*pos,SEEK_SET);
        fwrite(&a, sizeof(animal), NUM_DATA, myfile);
        fclose(myfile);
    }else{
        cout << "Error opening the data." << endl;
    }
}

inline animal read_file(int pos){
    myfile = fopen("var/data.bin", "rb");
    animal a ;//= malloc(sizeof(animal));
    if (myfile != NULL) { //SUCCESS OPERATION?
        cout << "read pos:  " << pos <<  " * sizeof(animal)" << endl;
        fseek(myfile,sizeof(animal)*pos,SEEK_SET);
        fread(&a,sizeof(animal),NUM_DATA,myfile);
        fclose(myfile);
        return a;
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
    myfile = fopen("var/hash.txt", "w");
    if (myfile != NULL) { //SUCCESS OPERATION?
        for (int i =0; i< size_hash_table; i++){
            node *aux = a[i];
            string name = to_string(i)+",";
            string val = name;
            while (aux != nullptr){
                if(aux->pos !=0){
                    val += to_string(aux->pos)+ ","; 
                }
                aux = aux->next;
            }
            cout << val << endl;
            const char * d = val.c_str();

            fwrite(d, sizeof(d), NUM_DATA, myfile);
            //val += "\r";
            
        }
        fclose(myfile);
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

    
    int counter = 0; //hash line
    hash_table  a = get_hash_table();
    
    const char *p;
	char *q;  
    if (myfile.is_open()) { //SUCCESS OPERATION?
        while(getline(myfile,line)){
            node * linked  = a[counter];     
        }
        return a;
    }else{ 
        cout << "Error opening the data" << endl;
        return nullptr;
    }

}


