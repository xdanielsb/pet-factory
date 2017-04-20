void insert_animal(int clientfd){
    int res;
    char  answer[100];

    char name[32];
    char type[32];
    char breed[16];
    char genre;
    int32_t age;
    int32_t height;
    int32_t weight;

    cout << "\n INSERT REGISTER \n";
    cout << " User we are going to ask you for some data, please ingress the data : "<<endl;
    cout << "\n\tName   = "; cin >> name;
    cout << "\n\ttype   = "; cin >> type;
    cout << "\n\tbreed  = "; cin >> breed;
    cout << "\n\tGenre if it is Female write a {F} but if it is Male  write  a {M}\n";
    cout << "\n\tgenre  = "; cin >> genre;
    cout << "\n\tage    = "; cin >> age;
    cout << "\n\theight = "; cin >> height;
    cout << "\n\tweight = "; cin >> weight;

    //Instance the animal
    animal a(name, type, age, breed,height, weight, genre);

    //animal a("zeus", "lion", 23, "warrior", 12, 34, 'm');

    //send the animal
    res = send(clientfd, &a, sizeof(a), 0);
    if (res != sizeof(a)){
        printf("\nthe message have not been sent completely. \n");
    }else{
        printf("\nthe animal has been sent. \n");
    }

    //now receive the answer of the server about the operation
    res = recv(clientfd, answer, 100, 0);
    printf("\nServer response: %s\n", answer);

}


void show_animal(int clientfd){
    int res;
    char  answer[100];
    int number_register;
    animal a1;
    char opt;
    int number;

    printf("\n Show register \n");
    /* receive the number of registers avaliable in the database */
    res = recv(clientfd, &number, sizeof(number), 0);

    /* capturing the number of register to query*/
    printf("\n Total number of registers: %d\n", number);
    printf("# Register= ");scanf(" %d", &number_register);

    /* send the register to query */
    res = send(clientfd, &number_register, sizeof(number_register), 0);

    /* receive the  'animal' */
    res = recv(clientfd, &a1, sizeof(a1), 0);
    printf("\nanimal received:\n");
    cout << to_string(a1) << endl;

}


void delete_animal(int clientfd){
    int res;
    char  answer[100];
    int number_register;
    printf("\n Delete register \n");
    /* capturing the register to delete */
    printf("# register = ");scanf(" %d", &number_register);
    /* send the number of the register */
    res = send(clientfd, &number_register, sizeof(number_register), 0);

    /*  receive the answer of the server about the operation */
    res = recv(clientfd, answer, 100, 0);
    printf("\nserver response: %s",answer);
}


void show_by_name( int clientfd){
    int res;
    vector < char > buffer;
    string name;
    animal a1;

    printf("\n Show animals by name\n");
    scanf(" Name = %s", &name[0]);

    /* transform string to vector*/
    for (int i= 0; i<name.size(); i++)
        buffer.push_back(name[i]);

    /* send answer to the client */
    res = send(clientfd, buffer.data(), buffer.size(), 0);

    /* receive the answer of the user  'animal' */
    res = recv(clientfd, &a1, sizeof(a1), 0);
    /* show the animal */
    show_animal(a1);
}


void show_clinic_history(int clientfd){

    int res;
    int number_register;
    animal a1;
    char yn;
    printf("\n Show historic clinic register \n");
    /* capturing the register to delete */
    printf("# register = ");scanf(" %d", &number_register);
    /* send the number of the register */
    res = send(clientfd, &number_register, sizeof(number_register), 0);

    /* receive the  'animal' */
    res = recv(clientfd, &a1, sizeof(a1), 0);
    printf("\nanimal received:\n");
    cout<<to_string(a1)<<"\n";

    /* creating the file */
    string hist = string(a1.hist_clinic);
    string cadena = "echo  \""+ hist+ "\" > hist.clinic ";
    system(cadena.c_str());
    system("gedit hist.clinic");


   printf("Do you wish to save the changes in the file (y)es (n)ot\n");

    //now we are going to do the update function
    cin >> yn;
    if(yn == 'y' || yn == 'y'){
        //update data
        printf("\tUmm a bit tricky but I can do it.\n");
        ifstream infile("hist.clinic");
        string concat ="";
        string line;

        while (getline(infile, line)){
            concat += line;
        }
        //printf("\tThis is the hist_clinic that you want to save\n");
        //cout<<(concat);

        strcpy(a1.hist_clinic,concat.c_str());

        //cout << a1.hist_clinic;
        //Now update the register
    }else if(yn == 'n' || yn == 'n'){
        printf("\tYou save me a lot work, thanks =) \n");
    }else{
        printf("\tlol\n");
    }

    //send the animal
    res = send(clientfd, &a1, sizeof(a1), 0);
    if (res != sizeof(a1)){
        printf("\nthe animal have not been sent completely. \n");
    }else{
        printf("\nthe animal has been sent. \n");
    }

}
