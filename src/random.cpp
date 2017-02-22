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


