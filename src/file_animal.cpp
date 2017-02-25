#include <stdio.h>
#include <string.h>
#include <fstream>  //ifstream
#include <stdlib.h> //strtok
#include <sstream>
#include <vector>

#define NUM_DATA 1

FILE *myfile;

int indicator;

inline void write_file(animal a,int pos){
    myfile = fopen("var/data.bin", "rb+");
    if (myfile != NULL) { //SUCCESS OPERATION?
        cout << "write pos:  " << pos << " * sizeof(animal)" <<  endl;
        fseek(myfile,sizeof(animal)*pos,SEEK_SET);

        indicator = ftell (myfile);
        cout <<  "\tposition indicator : " << (indicator/sizeof(animal)) << endl;

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

        indicator = ftell (myfile);
        cout <<  "\tposition indicator : " << (indicator/sizeof(animal)) << endl;

        fread(&a,sizeof(animal),NUM_DATA,myfile);
        fclose(myfile);
        return a;
    }else{ 
        cout << "Error opening the data" << endl;
    }

}


/*
inline void write_file2(animal a,int pos){
    myfile = fopen("var/data2.bin", "w+");
    if (myfile != NULL) { //SUCCESS OPERATION?
        cout << "write pos:  " << pos << " * sizeof(animal)" <<  endl;
        fseek(myfile,sizeof(animal)*pos,SEEK_SET);

        fwrite(&a, sizeof(animal), NUM_DATA, myfile);
        fclose(myfile);
    }else{
        cout << "Error opening the data." << endl;
    }
}

inline void rewrite_data_table(vvi data){
    int pos;
    animal a; 
    for(int i=0; i< size_hash_table; i++){
        ll num_columns = data[i].size();
        for(int j=0; j< num_columns; j++){
            pos =data[i][j] ;
            a = read_file(pos);
            write_file2(a,pos);
        }
    }
}*/



