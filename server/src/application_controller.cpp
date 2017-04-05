/*
 * Menu call animal controller because this one has 
 * the funcitionalites of animal'structure
 */
inline void menu(){
    int opcion = 2;
    char c; 
    while(opcion != 5 ) {
        cout << "\n\tHello User, Welcome to Pet Factory" << endl;
        cout << "\n\t\t This are the options that we offer" << endl;
        cout << "\t1. Insert a register " <<endl;
        cout << "\t2. Show a register " <<endl;
        cout << "\t3. Delete  a register " <<endl;
        cout << "\t4. Search for a register " <<endl;
        cout << "\t5. Salir " <<endl;
        cout << "user-clinica> ";
        cin >> opcion;
     //   system("clear");

        if(opcion == 1){
            insert_animal();
        }
        else if(opcion == 2){
            show_animal();
        }
        else if(opcion == 3){
            delete_animal();
        }
        else if(opcion == 4){
            show_animal_r();
        }

     /*   cout << "Press any letter to continue with the menu ";
        cin >> c;
        system("clear");*/
        
    }

    //Here we write the hash table in disk //Because the execution ends
    write_hash_table();
}


