#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>

using namespace std;

#include "src/animal.cpp"
#include "src/file.cpp"
#include "src/hash.cpp"

/* Good reference for input output
 * https://www.codingunit.com/c-tutorial-binary-file-io
 */

/* Good  reference for create hash table
 * http://users.dsic.upv.es/~nprieto/clases/EDA0506/T9/Traspas9.pdf
 */


int main(){
    
    animal a1("Tris", "perro", 1, "Criollo", 30, 35, 'F');  
    /*cout << "string: " << sizeof (string) << endl;
    cout << "Animal size: " << sizeof(animal) << endl;  */

    write(a1);
    read();

  //  show(a1);
    return 0;
}
