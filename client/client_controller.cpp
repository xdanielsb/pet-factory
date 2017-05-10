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

    cout << BOLD(FWHT("\n INSERT REGISTER \n"));
    cout << FWHT(" User we are going to ask you for some data, please ingress the data : ")<<endl;
    cout << UNDL(BOLD(FCYN("\n\tName   = "))); cin >> name;
    cout << UNDL(BOLD(FCYN("\n\ttype   = "))); cin >> type;
    cout << UNDL(BOLD(FCYN("\n\tbreed  = "))); cin >> breed;
    cout << UNDL(BOLD(FWHT("\n\tGenre if it is Female write a {F} but if it is Male  write  a {M}\n")));
    cout << UNDL(BOLD(FCYN("\n\tgenre  = "))); cin >> genre;
    cout << UNDL(BOLD(FCYN("\n\tage    = "))); cin >> age;
    cout << UNDL(BOLD(FCYN("\n\theight = "))); cin >> height;
    cout << UNDL(BOLD(FCYN("\n\tweight = "))); cin >> weight;

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
    printf(FGRN("\nServer response: %s\n"), answer);

}


void show_animal(int clientfd){
    int res;
    char  answer[100];
    int number_register;
    animal a1;
    char opt;
    int number;

    printf(BOLD(FWHT("\n Show register \n")));
    /* receive the number of registers avaliable in the database */
    res = recv(clientfd, &number, sizeof(number), 0);

    /* capturing the number of register to query*/
    printf(FGRN("\n Total number of registers: %d\n"), number);
    printf(UNDL(BOLD(FCYN("# Register= "))));scanf(" %d", &number_register);

    /* send the register to query */
    res = send(clientfd, &number_register, sizeof(number_register), 0);

    /* receive the  'animal' */
    res = recv(clientfd, &a1, sizeof(a1), 0);
    printf("\n\tAnimal received:\n");
    //cout << to_string(a1) << endl;
    show_animal(a1);
}


void delete_animal(int clientfd){
    int res;
    char  answer[100];
    int number_register;
    printf(BOLD(FWHT("\n Delete register \n")));
    /* capturing the register to delete */
    printf(UNDL(BOLD(FCYN("# register = "))));scanf(" %d", &number_register);
    /* send the number of the register */
    res = send(clientfd, &number_register, sizeof(number_register), 0);

    /*  receive the answer of the server about the operation */
    res = recv(clientfd, answer, 100, 0);
    printf(FGRN("\nserver response: %s"),answer);
}


void show_by_name( int clientfd){
    int res;
    vector < char > buffer;
    string name;
    animal a1;

    printf(BOLD(FWHT("\n Show animals by name\n Name = ")));
    cin >> name;

    /* transform string to vector*/
    for (int i= 0; i<name.size(); i++)
        buffer.push_back(name[i]);

    /* send the name to the server */
    res = send(clientfd, buffer.data(), buffer.size(), 0);

    /* receive the answer of the user  'animal' */
    res = recv(clientfd, &a1, sizeof(a1), 0);
    /* show the animal */
    string aux_name(a1.name);
    if (aux_name.compare(name) == 0){
        show_animal(a1);
    }else {
        cout << FGRN("There was not matching with the name:  ") << name << ".\n";
    }

}


void show_clinic_history(int clientfd){

    int res;
    int number_register;
    animal a1;
    char yn;
    printf(BOLD(FWHT("\n Show historic clinic register \n")));
    /* capturing the register to delete */
    printf(UNDL(BOLD(FCYN("# register = "))));scanf(" %d", &number_register);
    /* send the number of the register */
    res = send(clientfd, &number_register, sizeof(number_register), 0);

    /* receive the  'animal' */
    res = recv(clientfd, &a1, sizeof(a1), 0);
    printf("\n\tAnimal received:\n");
    //cout<<to_string(a1)<<"\n";
    show_animal(a1);
    /* creating the file */
    string hist = string(a1.hist_clinic);
    string cadena = "echo  \""+ hist+ "\" > hist.clinic ";
    system(cadena.c_str());
    system("gedit hist.clinic");


   printf(UNDL(BOLD(FCYN("Do you wish to save the changes in the file (y)es (n)ot\n"))));

    //now we are going to do the update function
    cin >> yn;
    if(yn == 'y' || yn == 'y'){
        //update data
        printf("\tUmm a bit tricky but I can do it.\n");
        ifstream infile("hist.clinic");
        string concat ="";
        string line;

        while (getline(infile, line)){
            concat += line+"\n";
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
