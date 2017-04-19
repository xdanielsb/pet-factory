#include <vector>
#include <stdio.h>
#include <string.h>

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

/*it's happening a weird thing*/
struct animal{

    char name[32];   //8 bytes
    char type[32];   //8 bytes
    char breed[16];  //8 bytes
    char genre;    //1 bytes 
    int32_t age;       //4 bytes
    int32_t height;    //4 bytes
    int32_t weight;    //4 bytes
    

    animal(){}

    animal(string _name, string _type, int32_t _age, \
        string _breed, int32_t _height, int32_t _weight, char _genre){

        strcpy(name,_name.c_str());
        strcpy(type,_type.c_str());
        strcpy(breed,_breed.c_str());
        height = _height;
        weight = _weight;
        genre = _genre;
        age = _age;

    }

    bool operator == (animal a) const {
        return genre == a.genre;
    }
};

inline string to_string(animal a){
    string data= "";
    string _name(a.name);
    string _type(a.type);
    string _breed(a.breed);
    

    data +=  _name +"\n";
    data +=  _type +"\n";    
    data +=  _breed +"\n";
    data +=   a.genre +"\n";
    data +=  to_string(a.age) +"\n";
    data +=  to_string(a.height) +"\n";
    data +=  to_string(a.weight) +"\n";
    return data;
}


inline void show_animal(animal &a){
    cout << endl;
    cout << "\t\tName: " << a.name << endl;
    cout << "\t\tType: " << a.type << endl;
    cout << "\t\tAge: " << a.age << endl;
    cout << "\t\tBreed: " << a.breed << endl;
    cout << "\t\tHeight: " << a.height << endl;
    cout << "\t\tWeight: " << a.weight << endl;
    cout << "\t\tGenre: " << a.genre << endl;
}



