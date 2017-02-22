#define NUM_DOGS 10000000

typedef long long ll;
typedef vector <string> vll;
typedef vector <vll> vvll;
/*
 *
 */
void show_registers(vvll registers){
    for(int i=0; i< size_hash_table; i++){
        ll num_columns = registers[i].size();
        for(int j=0; j< num_columns; j++){
            cout << registers[i][j]  << " ";
        }
        cout << endl;
    }
}


/*
 * Function for creating random strings
 */
string gen_random(char *s, const int len) {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = 0;
    string r(s);
    return s;
}


void init_application(){
    srand (time(NULL));  //Necesary when I am going to generate random numbers
    int len = 7;
    vvll data(size_hash_table);
    for (int i = 0; i<= NUM_DOGS; i++){
        char *s = new char[len];
        //Get random name
        string name =  gen_random(s, len);
        ll hash = get_hash(name);

        //Save random name in hash table
        
        //Save in disk the name
        data[hash].push_back(name);
       
        //Show the generated register
        //cout <<  name << " " << hash;
    }
    show_registers(data);
}
