#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>

using namespace std;


/*This order must be followed*/

//-----No dependencies 
#include "src/animal.cpp"
#include "src/hash.cpp"
#include "src/hash_table.cpp"

//-----Dependencies
#include "src/file.cpp" 
#include "src/animal_controller.cpp" //Depend on file


/* Good reference for input output
 * https://www.codingunit.com/c-tutorial-binary-file-io
 */

/* Good  reference for create hash table
 * http://users.dsic.upv.es/~nprieto/clases/EDA0506/T9/Traspas9.pdf
 */


int main(){
    
    animal a1("Tris", "perro", 1, "Criollo", 30, 35, 'F');  
    
    /* cout << "string: " << sizeof (string) << endl;
    cout << "Animal size: " << sizeof(animal) << endl;*/
    
    write_animal(a1);
    read_animal(a1);
    

  //  show(a1);
    return 0;
}
