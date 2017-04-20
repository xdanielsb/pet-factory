void insert_animal(int clientfd){
    int res;
    char  answer[100];

    string _name, _type, _breed;
    int32_t _height, _weight,  _age;
    char _genre;

    printf("\n INSERT REGISTER \n");
    scanf("\n\t    Name   = %s", &_name[0]);
    scanf("\n\t    type   = %s", &_type[0]);
    scanf("\n\t    breed  = %s", &_breed[0]);
    printf("\n\t (F)emale   (M)ale\n");
    scanf("\n\t    genre  = %c", &_genre);
    scanf("\n\t    age    = %d", &_age);
    scanf("\n\t    height = %d", &_height);
    scanf("\n\t    weight = %d", &_weight);

    animal a(_name, _type,_age, _breed, _height , _weight, _genre);
    //animal a1("Zeus", "Lion", 23, "Warrior", 12, 34, 'M');

    //Send the animal
    res = send(clientfd, &a, sizeof(a), 0);
    if (res != sizeof(a)){
        printf("The message have not been sent completely. \n");
    }else{
        printf("The animal has been sent. \n");
    }

    //Now receive the answer of the server about the operation
    res = recv(clientfd, answer, 100, 0);
    printf("Server response %s\n", answer);

}


void show_animal(int clientfd){
    int res;
    char  answer[100];
    int number_register;
    animal a1;
    char opt;
    int number;

    printf("\n SHOW REGISTER \n");
    /* Receive the number of registers avaliable in the database */
    res = recv(clientfd, &number, sizeof(number), 0);

    /* Capturing the number of register to query*/
    printf(" Total number of registers is: %d", number);
    scanf(" Number of the register  to query = %d", &number_register);

    /* Send the register to query */
    res = send(clientfd, &number_register, sizeof(number_register), 0);

    /* Receive the  'animal' */
    res = recv(clientfd, &a1, sizeof(a1), 0);
    printf("\nAnimal received:\n");
    cout << to_string(a1) << endl;

    /* Creating the file */
    string cadena = "echo  \""+to_string(a1)+ "\" > hist.clinic ";
    system(cadena.c_str());
    system("gedit hist.clinic");

    cout << "Do you wish to save the changes in the file (Y)es (N)ot\n";

    //Now we are going to do the update function
    cin >> opt;
    if(opt == 'Y' || opt == 'y'){
        //Update data
        ifstream infile("hist.clinic");
        string line;
        cout << "This is the animal that you want to save" << endl;
        while (getline(infile, line)){
            cout << line << endl;
        }
    }if(opt == 'N' || opt == 'n'){
        //Do nothing
    }
}


void delete_animal(int clientfd){
    int res;
    char  answer[100];
    int number_register;
    printf("\n DELETE REGISTER \n");
    /* Capturing the register to delete */
    scanf(" Number of the register  to delete = %d", &number_register);
    /* Send the number of the register */
    res = send(clientfd, &number_register, sizeof(number_register), 0);

    /*  Receive the answer of the server about the operation */
    res = recv(clientfd, answer, 100, 0);
    printf("\nServer response: %s",answer);
}


void show_by_name( int clientfd){
    int res;
    vector < char > buffer;
    string name;
    animal a1;

    printf("\n SHOW ANIMALS BY NAME\n");
    scanf(" Name of the register = %s", &name[0]);

    /* Transform string to vector*/
    for (int i= 0; i<name.size(); i++)
        buffer.push_back(name[i]);

    /* Send answer to the client */
    res = send(clientfd, buffer.data(), buffer.size(), 0);

    /* Receive the answer of the user  'animal' */
    res = recv(clientfd, &a1, sizeof(a1), 0);
    /* Show the animal */
    show_animal(a1);
}
