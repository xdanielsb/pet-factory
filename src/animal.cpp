
/*it's happening a weird thing*/
struct animal{

    string name;   //8 bytes
    string type;   //8 bytes
    string breed;  //8 bytes
    char genre;    //1 byte  
    int age;       //4 bytes
    int height;    //4 bytes
    int weight;    //4 bytes
    

    animal(){}

    animal(string _name, string _type, int _age, \
        string _breed, int _height, int _weight, char _genre){
        
        name = _name;
        type = _type;
        age = _age;
        breed = _breed;
        height = _height;
        weight = _weight;
        genre = _genre;

    }
};


inline void write_animal(animal a ){
    int hash_name = get_hash(a.name);
    
}

inline void read_animal(animal a){

}

inline void show(animal a){

    cout << "Name: " << a.name << endl;
    cout << "Type: " << a.type << endl;
    cout << "Age: " << a.age << endl;
    cout << "Breed: " << a.breed << endl;
    cout << "Height: " << a.height << endl;
    cout << "Weight: " << a.weight << endl;
    cout << "Genre: " << a.genre << endl;

}

