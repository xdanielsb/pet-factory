#define NUM_DOGS 1000  //Number of dogs that is going to be used in the project
#define NRPC 20000     //Number of registers per column

static ll LOC = 1;
static vvi data(size_hash_table);

/*
 * Create random int numbers 
 */
int randInt(int max, int min){
    return rand()%(max - min)+min; 
}

/*
 * Create random double numbers
 */
double randDouble(double max, double min){
    return drand48()*(max-min)+min;
}


/*
 * Function for creating random animals
 */
inline  animal gen_random(char name[32], const int len) {
    
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    string types[] = {"perro", "gato", "tortuga", "mariposa", "ave", "leon"};  
    string breeds[] = {"Criollo", "Pura", "Semental", "Super", "Saiyajin"};  
    char genres[] = {'F', 'M'};    //1 bytes 

    int32_t age = (int32_t)randInt(20,0);
    int32_t height = (int32_t)randInt(100,10);    
    int32_t weight = (float)randDouble(40.0,5.0);
    char genre = genres[rand() % 2];
    
    string breed = breeds[rand() % 5]; 
    string type = types[rand() % 6]; 

    //Random string
    for (int i = 0; i < len; ++i) {
        name[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    name[len] = 0; //Finish string

    string aaa(name);
    
    
    animal a1(name, type, age, breed,height, weight, genre);  
    
    //Take care the order of importations that you do in your project
    //show_animal(a1);
    return a1;
}




/*
 * Show the hash table, each row represents a new hash
 */
inline  void show_hash_table(){
    for(int i=0; i< size_hash_table; i++){
        ll num_columns = data[i].size();
        for(int j=0; j< num_columns; j++){
            cout << data[i][j]  << " ";
        }
        cout << i << " "<< num_columns << endl;
    }
}

/*
 * This function creates a location in disk and assign 
 * writes the animal to the new location
 */
inline  int persist_register(animal a ){
    ll code =LOC++;
    write_animal(a,code);
    return code;
}



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


