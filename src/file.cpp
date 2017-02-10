#include <stdio.h>

FILE *data;

inline void write(animal a){
    data = fopen("var/data.bin", "wb");
    if (data != NULL) { //SUCCESS OPERATION
        
        fclose(data);
    }
}

inline void read(){
    data = fopen("var/data.bin", "rb");

}
