

inline void read_animal(int pos){
    read_file(pos);
}

inline void write_animal(animal a, ll pos ){
    write_file(a, pos);   
   read_animal(pos);
}
    

inline void show_animal(animal a){
    cout << endl;
    cout << "Name: " << a.name << endl;
    cout << "Type: " << a.type << endl;
    cout << "Age: " << a.age << endl;
    cout << "Breed: " << a.breed << endl;
    cout << "Height: " << a.height << endl;
    cout << "Weight: " << a.weight << endl;
    cout << "Genre: " << a.genre << endl;

}

