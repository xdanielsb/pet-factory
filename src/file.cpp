#include <stdio.h>

FILE *data;

inline void write(animal &a){
    data = fopen("var/data.bin", "wb");
    if (data != NULL) { //SUCCESS OPERATION?
        cout << "write pos:  " << sizeof(animal)*get_hash(a.name) << endl;
        fseek(data,sizeof(animal)*get_hash(a.name),SEEK_SET);
        fwrite(&a, sizeof(animal), 1, data);
        fclose(data);

    }else{
        cout << "Error opening the data." << endl;
    }
}

inline void read(string name){
    data = fopen("var/data.bin", "rb");
    animal a;
    if (data != NULL) { //SUCCESS OPERATION?
        cout << "read pos:  " << sizeof(animal)*get_hash(name) << endl;
        fseek(data,sizeof(animal)*get_hash(name),SEEK_SET);
        fread(&a,sizeof(animal),1,data);
        cout << "Name: "<< a.name << endl;
        fclose(data);
    }else{ 
        cout << "Error opening the data" << endl;
    }

}
