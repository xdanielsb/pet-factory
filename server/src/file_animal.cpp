#include <stdio.h>
#include <string.h>
#include <fstream>  //ifstream
#include <stdlib.h> //strtok
#include <sstream>
#include <vector>
#include <unistd.h>
#include <sys/types.h>


#define NUM_DATA 1

FILE *myfile;

int indicator;

inline void write_file(animal a,int pos){
    //The file must exist
    myfile = fopen("var/structures.bin", "rb+");
    if (myfile != NULL) { //SUCCESS OPERATION?
        //cout << "write pos:  " << pos << " * sizeof(animal)" <<  endl;
        fseek(myfile,sizeof(animal)*pos,SEEK_SET);

        indicator = ftell (myfile);
        //cout <<  "\tposition indicator : " << (indicator/sizeof(animal)) << endl;

        fwrite(&a, sizeof(animal), NUM_DATA, myfile);
        fclose(myfile);
    }else{
        cout << "Error opening the data." << endl;
    }
}

inline animal read_file(int pos){
    myfile = fopen("var/structures.bin", "rb");
    animal a ;//= malloc(sizeof(animal));
    if (myfile != NULL) { //SUCCESS OPERATION?
    //    cout << "read pos:  " << pos <<  " * sizeof(animal)" << endl;
        fseek(myfile,sizeof(animal)*pos,SEEK_SET);

        indicator = ftell (myfile);
   //      cout <<  "\tposition indicator : " << (indicator/sizeof(animal)) << endl;

        fread(&a,sizeof(animal),NUM_DATA,myfile);
        fclose(myfile);
        return a;
    }else{
        cout << "Error opening the data" << endl;
    }

}

inline void delete_file(animal a,int pos){
    //The file must exist
    myfile = fopen("var/structures.bin", "rb+");
    if (myfile != NULL) { //SUCCESS OPERATION?
        cout << "write pos:  " << pos << " * sizeof(animal)" <<  endl;
        fseek(myfile,sizeof(animal)*pos,SEEK_SET);

        indicator = ftell (myfile);
        cout <<  "\tServer: position indicator : " << (indicator/sizeof(animal)) << endl;
        fwrite(&a, sizeof(animal), NUM_DATA, myfile);

        //Truncating the file
        cout << "\tServer: truncate the file " << endl;
        fseek(myfile,0,SEEK_END);
        indicator = ftell(myfile);
        cout << "\tServer:The size of the file is " << indicator << endl;
        int r = ftruncate(fileno(myfile), indicator-sizeof(animal));

        fseek(myfile,0,SEEK_END);
        indicator = ftell(myfile);
        cout << "\tServer:The new size of the file is " << indicator << endl;

        fclose(myfile);

    }else{
        cout << "Error opening the data." << endl;
    }
}
