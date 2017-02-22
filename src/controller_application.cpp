
inline void insert(){
    insert_animal();
}

inline void show(){
    show_animal();
}

inline void delete_r(){
    delete_animal();
}

inline void search(){


}




inline void menu(){
    int opcion = 2;
    char c; 
    while(opcion != 5 ) {
        cout << "\n\tHello User, Welcome to Pet Factory" << endl;
        cout << "\n This are the options that we offer" << endl;
        cout << "1. Insert a register " <<endl;
        cout << "2. Show a register " <<endl;
        cout << "3. Delete  a register " <<endl;
        cout << "4. Search for a register " <<endl;
        cout << "5. Salir " <<endl;
        cout << "user-clinica$ ";
        cin >> opcion;
        system("clear");

        if(opcion == 1){
            insert();
        }
        else if(opcion == 2){
            show();
        }
        else if(opcion == 3){
            delete_r();
        }
        else if(opcion == 4){
            search();
        }

        cout << "Press any letter to continue with the menu ";
        cin >> c;
        system("clear");
        
    }


}


