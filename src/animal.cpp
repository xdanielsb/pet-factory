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
        string _breed, int _height, int32_t _weight, char _genre){

        strcpy(name,_name.c_str());
        strcpy(type,_type.c_str());
        strcpy(breed,_breed.c_str());
        height = _height;
        weight = _weight;
        genre = _genre;

    }
};

