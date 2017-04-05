#include <algorithm>
#define size_hash_table 1024

inline int get_hash (string name){
    //This line transform to lower case the name
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    hash<string> hash_fn;
    size_t h1 = hash_fn(name);
    //Check if it's create a negative hash
    h1 < 0 ? cout << "There was a negative hash \n" << endl: cout << "" ;
    return  h1 % size_hash_table;
}

inline void example_hash_values(){
    cout << get_hash("daniel") << endl;
    cout << get_hash("maria") << endl;
    cout << get_hash("camila") << endl;
    cout << get_hash("paula") << endl;
    cout << get_hash("mafe") << endl;
}
