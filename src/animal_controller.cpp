
inline void write_animal(animal a ){
    int hash_name = get_hash(a.name);
    //Here we need to use the hash table
    
    write_file(a, hash_name);   
}
    
inline void read_animal(string name){
    int hash_name = get_hash(name);
    read_file(name, hash_name);
}

inline void show_animal(animal a){

    cout << "Name: " << a.name << endl;
    cout << "Type: " << a.type << endl;
    cout << "Age: " << a.age << endl;
    cout << "Breed: " << a.breed << endl;
    cout << "Height: " << a.height << endl;
    cout << "Weight: " << a.weight << endl;
    cout << "Genre: " << a.genre << endl;

}

