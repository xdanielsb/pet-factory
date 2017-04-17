#include <sstream>
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
/*
 *  This menu is called in architecture client-server
 */
inline void options_main_menu(int opcion, int socketfd){
   // system("'Se realizo una operacion \n' >> serverDogs.log ");
    int r;
    vector < char > buffer;
    if (opcion == 1){ //INSERT AN ANIMAL
        animal a1;
        bool res ;
        r = recv(socketfd, &a1, sizeof(a1), 0);
        cout << "\t\tServer: Data of the animal inserted \n";
        show_animal(a1);

        //Need to receive an animal
        res = insert_animal(a1);
        if (res){
            //Buffer that storage the request
            
            string msj = "The animal has inserted succesffuly.";
            for (int i= 0; i<msj.size(); i++)
                buffer.push_back(msj[i]);
            //Send answer to the client
            r = send(socketfd, buffer.data(), buffer.size(), 0);
        }
    }
    else if(opcion == 2){ //DISPLAY AN ANIMAL
        int number_animals = total_number_animals();
        int number_register;
        string msj = SSTR( number_animals );
        for (int i= 0; i<msj.size(); i++)
            buffer.push_back(msj[i]);
        //Send  the number of animals to the client
        r = send(socketfd, buffer.data(), buffer.size(), 0);
        
        //receive the number of register that the user want to display
        r = recv(socketfd, &number_register, sizeof(number_register), 0);
        
        animal a1  = show_animal(number_register, 0);
        r = send(socketfd, &a1, sizeof(a1), 0);
        if (r != sizeof(a1)){
            //Re send;
            cout << "\t\tServer: The message have not been sent completely. \n";
        }else{
            cout << "\t\tServer: The animal has been sent. \n";
        }

    }
    else if(opcion == 3){
        int number_register;
        //receive the number of register that the user want to delete
        r = recv(socketfd, &number_register, sizeof(number_register), 0);
        string msj;
        bool res = delete_animal(number_register);

        if (res){
            msj = "The animal has been deleted succesffuly.";
        }else{
            msj = "The animal has not been deleted succesffuly.";
        }
        
        for (int i= 0; i<msj.size(); i++)
            buffer.push_back(msj[i]);

        //Send answer to the client
        r = send(socketfd, buffer.data(), buffer.size(), 0);
    }
    else if(opcion == 4){
        //Receive the name of the animal
        string name;

        show_animal_r(name);
    }else if(opcion == 5){
        cout << "\t\tServer: The hash table is being written in disk.\n";
        write_hash_table();
    }
}
