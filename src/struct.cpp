using std::string;
using std::cout;
using std::cin;
using std::endl;

struct animal{
    string name;
    string type;
    int age;
    string breed;
    int height;
    int weight;
    char genre;

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

inline void show(animal a){

    cout << "Name: " << a.name << endl;
    cout << "Type: " << a.type << endl;
    cout << "Age: " << a.age << endl;
    cout << "Breed: " << a.breed << endl;
    cout << "Height: " << a.height << endl;
    cout << "Weight: " << a.weight << endl;
    cout << "Genre: " << a.genre << endl;

}

