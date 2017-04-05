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



inline void launch_application(bool initilize_from_scratch = false){

    
    auto start = chrono::high_resolution_clock::now();
    cin.tie(NULL); 
   
    //Create random data
    if (initilize_from_scratch){
        cout << "Number of registers to create randomly : "<< NUM_DOGS << endl;
        cout << "The Data is being created, please wait a moment ..." << endl;
        create_random_data();  //Random class
    }else{
        cout << "The data has  been read from disk" <<endl;
        data = read_file_hash(); //hash_table
        ll total = 0;
        for(int i=0; i< size_hash_table; i++){
            total += data[i].size();
        }
        LOC = total; //re pos end of the file for insertion
        cout << "The number or registers that were readen from disk were: " << (total -1)<< endl;
    }

    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end-start;
    cout << "\ninitializing the application took: " << diff.count() << endl ;

    menu();


    // example_write_show_animal();
    // example_loading_hash_table();
    // example_creating_hash_table();

}

int main(int argc, char* argv[]){
    
    if(argc  == 1){
        printf("Hey user, you need te enter args\n");
        printf("Enter \"load\" if your desire is create 10 million of registers \n");
        printf("Enter \"not-load\" if you don't want to creat the files from scratch \n");
        printf("\t\tExample ./a.out load");
        printf("\t\tExample ./a.out not-load");
        
    }else{
        string opt1 = argv[1];
        
        launch_application(opt1 == "load");
    }
    return 0;
}
