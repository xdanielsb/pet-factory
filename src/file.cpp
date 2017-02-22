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




