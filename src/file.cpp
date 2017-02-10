#include <stdio.h>

FILE *data;

inline void write(animal &a){
    data = fopen("var/data.bin", "wb");
    if (data != NULL) { //SUCCESS OPERATION?
        fwrite(&a, sizeof(animal), 1, data);
        fclose(data);
    }else{
        cout << "Error opening the data." << endl;
    }
}

inline void read(){
    data = fopen("var/data.bin", "rb");
    animal a;
    if (data != NULL) { //SUCCESS OPERATION?
        fread(&a,sizeof(animal),1,data);
        cout << "Name: "<< a.name << endl;
        fclose(data);
    }else{ 
        cout << "Error opening the data" << endl;
    }

}
