#include <fstream>
#include <sstream>
#include <string>



void insert_animal(int clientfd){
    int r; //Response -Success operation -- Error
    //Define the necesary fields for inserting an animal
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
    animal a1(name, type, age, breed,height, weight, genre);

    //animal a1("Zeus", "Lion", 23, "Warrior", 12, 34, 'M');

    r = send(clientfd, &a1, sizeof(a1), 0);
    if (r != sizeof(a1)){
        //Re send;
        cout << "The message have not been sent completely. \n";
    }else{
        cout << "The animal has been sent. \n";
    }
    char  answer[100];
    //Now receive the answer of the server about the operation
    r = recv(clientfd, answer, 100, 0);
    cout << endl << endl;
    cout << "Server response: " << answer << endl;
}


void show_animal(int clientfd){
    int r; //Response -Success operation -- Error
    char  answer[100];
    int number_register;
    animal a1;
    cout << "\n SHOW REGISTER \n";
    //Receive the number of clients

    r = recv(clientfd, answer, 100, 0);

    cout << " Total number of registers is: " << answer;
    cout << " User write the number of the register to see, please" << endl;
    cout << " Number of the register = " ;
    cin >> number_register;

    r = send(clientfd, &number_register, sizeof(number_register), 0);
    //Receive the answer of the user  'animal'
    r = recv(clientfd, &a1, sizeof(a1), 0);
    cout << endl << "This is the animal" << endl;
    cout << to_string(a1) << endl;

    string cadena = "echo  \""+to_string(a1)+ "\" > hist.clinic ";
    system(cadena.c_str());
    system("gedit hist.clinic");

    cout << "Do you wish to save the changes in the file (Y)es (N)ot\n";
    char opt;
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
    int r; //Response -Success operation -- Error
    //show_hash_table();
    char  answer[100];
    int number_register;
    cout << "\n DELETE REGISTER \n";
    cout << " Number of the register = " ;

    cin >> number_register;
    r = send(clientfd, &number_register, sizeof(number_register), 0);

    //Now receive the answer of the server about the operation
    r = recv(clientfd, answer, 100, 0);
    cout << endl << endl;
    cout << "Server response: " << answer << endl;
}


void show_by_name(int clientfd){
    int r; //Response -Success operation -- Error
    vector < char > buffer;
    string name;
    animal a1;
    cout << "\n SHOW ANIMALS BY NAME\n";

    cout << " Name of the register = " ; cin >> name;

    for (int i= 0; i<name.size(); i++)
        buffer.push_back(name[i]);
    //Send answer to the client
    r = send(clientfd, buffer.data(), buffer.size(), 0);

    //Receive the answer of the user  'animal'
    r = recv(clientfd, &a1, sizeof(a1), 0);
    //Show the animal
    show_animal(a1);
}
