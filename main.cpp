#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>

using namespace std;

#include "src/animal.cpp"
#include "src/file.cpp"
#include "src/hash.cpp"

/* Good reference
 * https://www.codingunit.com/c-tutorial-binary-file-io
 */



int main(){
    /*
    animal a1("Tris", "perro", 1, "Criollo", 30, 35, 'F');  
    cout << "string: " << sizeof (string) << endl;
    cout << "Animal size: " << sizeof(animal) << endl;  */

    cout << get_hash("DaniEl") <<endl;
    cout << get_hash("daniEl") <<endl;
    cout << get_hash("daniel") <<endl;

  //  show(a1);
    return 0;
}
