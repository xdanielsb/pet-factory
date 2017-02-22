#include <stdio.h>
#include <string.h>
#include <fstream>  //ifstream
#include <stdlib.h> //strtok
#include <sstream>
#include <vector>

#define NUM_DATA 1
FILE *data;


//
// THIS IS FOR THE DATA
//


inline void write_file(animal &a,int pos){
    data = fopen("var/data.bin", "wb");
    if (data != NULL) { //SUCCESS OPERATION?
    //    cout << "write pos:  " << pos << " * sizeof(animal)" <<  endl;
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
   //     cout << "read pos:  " << pos <<  " * sizeof(animal)" << endl;
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

            fwrite(d, sizeof(d), NUM_DATA, data);
            //val += "\r";
            
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


