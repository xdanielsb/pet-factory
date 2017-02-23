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
#include "src/test.cpp"
#include "src/random.cpp"                    //Use hash_table for show



void launch_application(){

    //Init timer
    auto start = chrono::high_resolution_clock::now();

    //Faster input and output
    cin.tie(NULL); 
   
    //Create random data
    bool initilize_from_scratch = false;
    if (initilize_from_scratch){
        create_random_data();
    }else{
        data = read_file_hash(); 
    }

    //Finish timer
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;

    //Display timer
    cout << "\ninitializing the application took: " << diff.count() << endl ;

    
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
