/*
 *  This menu is called in architecture client-server
 */
inline void options_main_menu(int opcion, animal a1, int socketfd){
    system("'Se realizo una operacion \n' >> serverDogs.log ");
    int r;
    if (opcion == 1){
        bool res ;
        //Need to receive an animal
        res = insert_animal(a1);
        if (res){
            //Buffer that storage the request
            vector < char > buffer;
            string msj = "The animal has inserted succesffuly.";
            for (int i= 0; i<msj.size(); i++)
                buffer.push_back(msj[i]);
            //Send answer to the client
            r = send(socketfd, buffer.data(), buffer.size(), 0);
        }
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
