/*
 * This example, I show how to create an animal, writing in disk and 
 * Finally read that Animal in disk. 
 */
inline  void example_write_show_animal(){
    //animal a1;
    string name = "Tris"; 
    string type  = "Perro"; 
    string breed = "Criollo";
    char genre = 'F';    
    int32_t age = 30;       
    int32_t height = 7;    
    int32_t weight = 10;    
    
    animal a1(name, type, age, breed, height, weight, genre);  
    
    /* cout << "string: " << sizeof (string) << endl;
    cout << "Animal size: " << sizeof(animal) << endl;*/
    
    int code1 =  write_animal(a1);

    name = "Motas"; 
    type  = "Canario"; 
    breed = "Pura";
    genre = 'M';    
    age = 2;       
    height = 15;    
    weight = 20;    
    
    animal a2(name, type, age, breed, height, weight, genre);  
    

    int code2 =  write_animal(a2);

   // write_animal(a1,pos);
    read_animal(code1);
    read_animal(code2);
  //  show(a1);
}


