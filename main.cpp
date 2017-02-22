#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>       /* count the time */
#include <sys/types.h> 

using namespace std;

/*This order must be followed*/

//-----No dependencies 
#include "src/animal.cpp"
#include "src/hash.cpp"
#include "src/hash_table.cpp"


//-----Dependencies
#include "src/file.cpp" 
#include "src/animal_controller.cpp" //Depend on file
#include "src/controller.cpp"
#include "src/test.cpp"

void launch_application(){

    //Init timer
    auto start = chrono::high_resolution_clock::now();

    //Faster input and output
    cin.tie(NULL); 
   

    //Load the data
    load_data();

    //Finish timer
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    //Display timer
    cout << "\nTime initializing the application: " << diff.count() << endl ;

    
    //Display the menu
    menu();
    

    // example_write_show_animal();
    // example_loading_hash_table();
    // example_creating_hash_table();

}

int main(){

    launch_application();
    
    return 0;
}
