#include <algorithm>


inline int get_hash (string name){
    //This line transform to lower case the name
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    hash<string> hash_fn;
    cout << name << endl;
    size_t h1 = hash_fn(name);
    return (int) h1;
}
