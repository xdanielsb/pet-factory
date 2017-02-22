#define NUM_DOGS 1000  //Number of dogs that is going to be used in the project
#define NRPC 20000     //Number of registers per column



inline  void load_data(){
    srand (time(NULL));  //Necesary when I am going to generate random numbers
    int len = 7;         //Len of the names 
    
    for (ll i = 0; i<= NUM_DOGS; i++){
        
        char *s = new char[len];
        //Get random name
        animal aux =  gen_random(s, len);
        ll hash = get_hash(aux.name);
        
        ll code = persist_register(aux);
        //Save random name in hash table
        
        //Save in disk the name
        data[hash].push_back(code);
       
        //Show the generated register
      //  cout << i << " " << name << " " << hash <<endl;

        delete s;
    }

 
    show_hash_table();
}

inline void insert(){

    
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
    ll location_disk = persist_register(a1);

    //Save location in hash table
    data[hash].push_back(location_disk);
    cout << "The register has been inserted succesfully" << endl;
}



inline void show(){
    ll total = 0;
    int n;
    cout << "\n SHOW REGISTER \n";
    for(int i=0; i< size_hash_table; i++){
        total += data[i].size();
    }
    cout << " Total number of registers is: " << total;
    cout << " User write the number of the register to see, please" << endl;
    cout << "user-clinica$ " << endl;
    cout << "Number of the register = " ;
    cin >> n;

    read_animal(n);
}

inline void delete_r(){


}

inline void search(){


}




inline void menu(){
    int opcion = 2;
    char c; 
    while(opcion != 5 ) {
        cout << "\n\tHello User, Welcome to Pet Factory" << endl;
        cout << "\n This are the options that we offer" << endl;
        cout << "1. Insert a register " <<endl;
        cout << "2. Show a register " <<endl;
        cout << "3. Delete  a register " <<endl;
        cout << "4. Search for a register " <<endl;
        cout << "5. Salir " <<endl;
        cout << "user-clinica$ ";
        cin >> opcion;
        system("clear");

        if(opcion == 1){
            insert();
        }
        else if(opcion == 2){
            show();
        }
        else if(opcion == 3){
            delete_r();
        }
        else if(opcion == 4){
            search();
        }

        cout << "Press any letter sto continue with the menu ";
        cin >> c;
        system("clear");
        
    }


}


