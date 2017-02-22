#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;
/* Good reference for input output
 * https://www.codingunit.com/c-tutorial-binary-file-io
 */

/* Good  reference for create hash table
 * http://users.dsic.upv.es/~nprieto/clases/EDA0506/T9/Traspas9.pdf
 */




/*This order must be followed*/

//-----No dependencies 
#include "src/animal.cpp"
#include "src/hash.cpp"
#include "src/hash_table.cpp"


//-----Dependencies
#include "src/file.cpp" 
#include "src/animal_controller.cpp" //Depend on file
#include "src/controller.cpp"




int main(){

    init_application();
 // example_loading_hash_table();
 //  example_creating_hash_table();
 // example_write_show_animal();
    return 0;
}
