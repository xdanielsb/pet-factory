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
#include "src/file_hash.cpp"  


//-----Dependencies
#include "src/hash_table.cpp"
#include "src/animal_controller.cpp" 
#include "src/application_controller.cpp"    //Declare animal
#include "src/test.cpp"                      //Test of application functionalities
#include "src/random.cpp"                    //Use hash_table for show



inline void launch_application(){

    
    auto start = chrono::high_resolution_clock::now();
    cin.tie(NULL); 
   
    //Create random data
    bool initilize_from_scratch = false;
    if (initilize_from_scratch){
        cout << "Number of registers to create randomly : "<< NUM_DOGS << endl;
        cout << "The Data is being created, please wait a moment ..." << endl;
        create_random_data();  //Random class
    }else{
        cout << "The data has  been read from disk" <<endl;
        data = read_file_hash(); //hash_table
    }

    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << "\ninitializing the application took: " << diff.count() << endl ;

    menu();


    // example_write_show_animal();
    // example_loading_hash_table();
    // example_creating_hash_table();

}

int main(){

    launch_application();
    return 0;
}
