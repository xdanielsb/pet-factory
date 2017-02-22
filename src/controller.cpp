#define NUM_DOGS 3
#define NRPC 20000 //Number of registers per column

static ll LOC = 1;
static vvi data(size_hash_table);

//Funciones para generar numeros aleatorios
int randInt(int max, int min){

    int aleat_int = 0;
    aleat_int= rand()%(max - min)+min;
    return aleat_int; }

double randDouble(double max, double min){

    double aleat_doub=0.0;
    aleat_doub= drand48()*(max-min)+min;
    return aleat_doub;}




/*
 *
 */
inline  void show_registers(){
    //for(int i=0; i< NUM_DOGS; i++){
    for(int i=0; i< size_hash_table; i++){
        ll num_columns = data[i].size();
        /*for(int j=0; j< kdnum_columns; j++){
            cout << registers[i][j]  << " ";
        }*/
        cout << i << " "<< num_columns << endl;
    }
}

inline  int persist_register(animal a ){
    /*ll start = hash * NRPC;
    int num_columns = data[hash].size();
    ll code = num_columns+ start;*/
    ll code =LOC++;
    write_animal(a,code);
    return code;
}


/*
 * Function for creating random strings
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


inline  void load_data(){
    srand (time(NULL));  //Necesary when I am going to generate random numbers
    int len = 7;
    
    
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

 
    show_registers();
}

inline void insert(){
    cout << "\n INSERT REGISTER \n";
    cout << " User we are going to ask you for some data, please ingress the data"<< endl;

    
    char name[32];   //8 bytes
    char type[32];   //8 bytes
    char breed[16];  //8 bytes
    char genre;    //1 bytes 
    int32_t age;       //4 bytes
    int32_t height;    //4 bytes
    int32_t weight;    //4 bytes

    cout << "Name="; cin >> name;
    cout << "type="; cin >> type;
    cout << "breed="; cin >> breed;
    cout << "genre="; cin >> genre;
    cout << "age="; cin >> age;
    cout << "height="; cin >> height;
    cout << "weight="; cin >> weight;

    animal a1(name, type, age, breed,height, weight, genre);   
    ll hash = get_hash(a1.name);
        
    ll code = persist_register(a1);
    //Save random name in hash table
    data[hash].push_back(code);
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
    cout << "user-clinica$" << endl;
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
    while(opcion != 5 ) {
        cout << "\n\tHello User, Welcome to Pet Factory" << endl;
        cout << "\n This are the options that we offer" << endl;
        cout << "1. Insert a register " <<endl;
        cout << "2. Show a register " <<endl;
        cout << "3. Delete  a register " <<endl;
        cout << "4. Search for a register " <<endl;
        cout << "5. Salir " <<endl;

        cout << "user-clinica$";
        cin >> opcion;

        if(opcion==1){
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
        
    }


}


