#define NUM_DOGS 10000
#define NRPC 20000 //Number of registers per column

static ll LOC = 1;
/*
 *
 */
void show_registers(vvi registers){
    for(int i=0; i< size_hash_table; i++){
        ll num_columns = registers[i].size();
        /*for(int j=0; j< kdnum_columns; j++){
            cout << registers[i][j]  << " ";
        }*/
        cout << i << " "<< num_columns << endl;
    }
}

int persist_register(vvi data, animal a , int hash){
    /*ll start = hash * NRPC;
    int num_columns = data[hash].size();
    ll code = num_columns+ start;*/
    ll code =LOC;
    write_animal(a,LOC++);
    return code;
}


/*
 * Function for creating random strings
 */
animal gen_random(char *s, const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    static string types[] = {"perro", "gato", "tortuga", "mariposa", "ave", "leon"};  
    static string breeds[] = {"Criollo", "Pura", "Semental", "Super", "Saiyajin"};  
    static char genres[] = {'F', 'M'};    //1 bytes 

    int age = rand() % 100;
    int height = rand() % 168;    
    int weight = rand() % 200;
    char genre = genres[rand() % 2];
    string breed = breeds[rand() % 5]; 
    string type = types[rand() % 6]; 

    //Random string
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0; //Finish string
    string name(s); //turning into string
    
    animal a1(name, type, age, breed,height, weight, genre);  
    
    //Take care the order of importations that you do in your project
    //show_animal(a1);
    return a1;
}


void init_application(){
    srand (time(NULL));  //Necesary when I am going to generate random numbers
    int len = 7;
    
    vvi data(size_hash_table);
    for (ll i = 0; i<= NUM_DOGS; i++){
        
        char *s = new char[len];
        //Get random name
        animal aux =  gen_random(s, len);
        ll hash = get_hash(aux.name);
        
        ll code = persist_register(data, aux,  hash);
        //Save random name in hash table
        
        //Save in disk the name
        data[hash].push_back(code);
       
        //Show the generated register
      //  cout << i << " " << name << " " << hash <<endl;

        delete s;
    }

 
    show_registers(data);
}
