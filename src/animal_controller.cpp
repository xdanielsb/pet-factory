#include "file_animal.cpp"

/*
 * Refers to read animal from disk
 */
inline void read_animal(int pos){
    animal a = read_file(pos);

    //Open the file
    //string cadena = "echo  \"The animal that was readen from disk was: \n Name: "+to_string(a)+ " \" > hist.clinic "; 

    //system(cadena.c_str());
    //system("gedit hist.clinic");
    show_animal(a);
}
/*
 * Write animla in disk
 */
inline int write_animal(animal a){
    int pos = get_code();//Get the position in disk to storage the animal
    write_file(a, pos);   
  // read_animal(pos);
  return pos;
}


/*
 * Operation for the user for create an animal from memory to disk
 */
inline void insert_animal(){

    
    //Define the necesary fields for inserting an animal
    char name[32];   
    char type[32];   
    char breed[16];  
    char genre;    
    int32_t age;   
    int32_t height;
    int32_t weight;


    cout << "\n INSERT REGISTER \n";
    cout << " User we are going to ask you for some data, please ingress the data : "<<endl;


    cout << "\n\tName   = "; cin >> name;
    cout << "\n\ttype   = "; cin >> type;
    cout << "\n\tbreed  = "; cin >> breed;
    cout << "\n Genre if it is Female write a {F} but if it is Male  write  a {M}\n"; 
    cout << "\n\tgenre  = "; cin >> genre;
    cout << "\n\tage    = "; cin >> age;
    cout << "\n\theight = "; cin >> height;
    cout << "\n\tweight = "; cin >> weight;

    //Instance the animal
    animal a1(name, type, age, breed,height, weight, genre);   

    //Getting the hash number of the animal
    ll hash = get_hash(a1.name);
        
    //Persisting the animal and getting the location in disk
    ll location_disk = write_animal(a1);

    //Save location in hash table
    data[hash].push_back(location_disk);
    cout << "The register has been inserted succesfully" << endl;

}

/*
 * User operation for show the animal
 */

inline void show_animal(){
    ll total = 0;
    int number_register;
    cout << "\n SHOW REGISTER \n";
    for(int i=0; i< size_hash_table; i++){
        total += data[i].size();
    }
    cout << " Total number of registers is: " << total;
    cout << " User write the number of the register to see, please" << endl;
    cout << " Number of the register = " ;
    cin >> number_register;

    read_animal(number_register);
}
    

