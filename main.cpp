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
    create_random_data();

    //Finish timer
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;

    //Display timer
    cout << "\ninitializing the application took: " << diff.count() << endl ;

    
    //Display the menu
  //  menu();

    write_hash_table();
    vvi ne = read_file_hash();
    for (int i = 0; i<ne.size(); i++){
        int s = ne[i].size();
        cout << i << " : ";
        for (int j = 0; j  < s; j++){
            cout << ne[i][j] << " ";
        }
        cout << endl;
    }
        

    // example_write_show_animal();
    // example_loading_hash_table();
    // example_creating_hash_table();

}

int main(){

    launch_application();
    return 0;
}
