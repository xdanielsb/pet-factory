#include <iostream>
#include <stdio.h>
#include <string>
#include "src/animal.cpp"
#include "src/file.cpp"

/* Good reference
 * https://www.codingunit.com/c-tutorial-binary-file-io
 */

int main(){
   // animal a1("Tris", "perro", 1, "Criollo", 30, 35, 'F'); 
    
    cout << "string: " << sizeof (string) << endl;
    cout << "Animal size: " << sizeof(animal) << endl;   
    
  //  show(a1);
    return 0;
}
