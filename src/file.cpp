#include <stdio.h>
#define NUM_DATA 1
FILE *data;

inline void write(animal &a,int pos){
    data = fopen("var/data.bin", "wb");
    if (data != NULL) { //SUCCESS OPERATION?
        cout << "write pos:  " << sizeof(animal)*pos<< endl;
        fseek(data,sizeof(animal)*pos,SEEK_SET);
        fwrite(&a, sizeof(animal), NUM_DATA, data);
        fclose(data);
    }else{
        cout << "Error opening the data." << endl;
    }
}

inline void read(string name, int pos){
    data = fopen("var/data.bin", "rb");
    animal a;
    if (data != NULL) { //SUCCESS OPERATION?
        cout << "read pos:  " << sizeof(animal)*pos << endl;
        fseek(data,sizeof(animal)*pos,SEEK_SET);
        fread(&a,sizeof(animal),NUM_DATA,data);
        cout << "Name: "<< a.name << endl;
        fclose(data);
    }else{ 
        cout << "Error opening the data" << endl;
    }

}
