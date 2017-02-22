

/*it's happening a weird thing*/
struct animal{

    string name;   //8 bytes
    string type;   //8 bytes
    string breed;  //8 bytes
    char genre;    //1 bytes 
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

