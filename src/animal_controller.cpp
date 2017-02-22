#include <stdlib.h>

inline void read_animal(int pos){
    animal a = read_file(pos);

    //Open the file
    //string cadena = "echo  \"The animal that was readen from disk was: \n Name: "+to_string(a)+ " \" > hist.clinic "; 

    //system(cadena.c_str());
    //system("gedit hist.clinic");
    show_animal(a);
}

inline void write_animal(animal a, ll pos ){
    write_file(a, pos);   
  // read_animal(pos);
}
    

