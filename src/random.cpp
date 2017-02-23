#define NUM_DOGS 1000  //Number of dogs that is going to be used in the project

/*
 * Create random int numbers 
 */
int randInt(int max, int min){
    return rand()%(max - min) + min; 
}

/*
 * Create random double numbers
 */
double randDouble(double max, double min){
    return drand48() * ( max - min ) + min;
}


/*
 * Function for creating random animals
 */
inline  animal create_random_animal(char name[32], const int len) {
    
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

    //Random name 
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

inline  void create_random_data(){
    srand (time(NULL));  //Necesary when I am going to generate random numbers
    int len = 7;         //Len of the names 
    
    for (ll i = 0; i<= NUM_DOGS; i++){
        char *s = new char[len];
        //Get random name
        animal aux =  create_random_animal(s, len);
        ll hash = get_hash(aux.name);
        ll code = write_animal(aux);
        data[hash].push_back(code);
        delete s;
    }

 
    show_hash_table();
}

