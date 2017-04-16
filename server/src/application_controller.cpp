/*
 *  This menu is called in architecture client-server
 */
inline void options_main_menu(int opcion, animal a1){
    system("'Se realizo una operacion \n' >> serverDogs.log ");
    if (opcion == 1){
        //Need to receive an animal
        insert_animal(a1);
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
}
