/*
 * Variables and libraries for critical sections
 */

 //MUTEX
#include <mutex>
mutex mtx;
mutex mtx2;

 //SEMAPHORES
#include <fcntl.h>
#include <semaphore.h>
#define SNAME "/mysem"
#define NUM_CLIENTS_SAME_TIME 1
sem_t *sem =  sem_open(SNAME, O_CREAT, 0644, NUM_CLIENTS_SAME_TIME );

  //PIPE
#define WRITE 1
#define READ 0
int pipefd[2];

char mensaje [50];
int r = pipe(pipefd);

static bool LOCK_INSERTION = false;
static bool LOCK_DELETION = false;
static bool LOCK_CLINICAL = false;

/*
 *  This menu is called in architecture client-server
 */
inline string options_main_menu(int opcion, int socketfd){
   // system("'Se realizo una operacion \n' >> serverDogs.log ");
    int r;
    vector < char > buffer;
    char  answer[100];
    if (opcion == 1){ //INSERT AN ANIMAL
        animal a1;
        bool res ;
        r = recv(socketfd, &a1, sizeof(a1), 0);
        printf("\tServer: Data of the animal inserted \n");
        //show_animal(a1);


        if(LOCK_INSERTION){
            cout << "The insertion is lock this gonna take some seconds ..." << endl;
        }
        mtx.lock();
        LOCK_INSERTION = true;
        //Need to receive an animal
        res = insert_animal(a1);
        mtx.unlock();
        LOCK_INSERTION = false;

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

        //Send  the number of animals to the client
        r = send(socketfd, &number_animals, sizeof(number_animals), 0);

        //receive the number of register that the user want to display
        r = recv(socketfd, &number_register, sizeof(number_register), 0);

        animal a1  = show_animal(number_register, 0);
        r = send(socketfd, &a1, sizeof(a1), 0);
        //cout << "Animal to send \n" << to_string(a1) <<"\n";
        if (r != sizeof(a1)){
            //Re send;
            cout << "\t\tServer: The message have not been sent completely. \n";
        }else{
            cout << "\t\tServer: The register has been sent. \n";
        }

    }
    else if(opcion == 3){
        int number_register;
        //receive the number of register that the user want to delete
        r = recv(socketfd, &number_register, sizeof(number_register), 0);
        string msj;

        if(LOCK_DELETION){
            cout << "Hey user delete a register is blocked, this is gonna take some minutes." << endl;
        }
        sem_wait(sem);
        LOCK_DELETION = true;
        bool res = delete_animal(number_register);
        LOCK_DELETION = false;
        sem_post(sem);

        msj =  (res) ? "The animal has been deleted succesffuly." : "The animal has not been deleted succesffuly.";

        for (int i= 0; i<msj.size(); i++)
            buffer.push_back(msj[i]);
        //Send answer to the client
        r = send(socketfd, buffer.data(), buffer.size(), 0);
    }
    else if(opcion == 4){
        //Receive the name of the animal

        r = recv(socketfd, answer, 100, 0);
        cout << endl << endl;
        cout << "Server response: " << answer << endl;

        string name(answer);
        cout << "Server: The name that the user wrote is: "<< name << endl;
        animal a1  = show_animal_r(name);

        r = send(socketfd, &a1, sizeof(a1), 0);
        if (r != sizeof(a1)){
            //Re send;
            cout << "\t\tServer: The message have not been sent completely. \n";
        }else{
            cout << "\t\tServer: The animal has been sent. \n";
        }
        return name;

    }else if(opcion == 5){
        int number_register;
        //receive the number of register that the user want to display
        r = recv(socketfd, &number_register, sizeof(number_register), 0);
        mtx2.lock();

        // if(LOCK_CLINICAL){
        //     cout << "The clinical history is currently blocked."<<endl;
        // }
        // write(pipefd[WRITE], "block\0", 5);
        // LOCK_CLINICAL =true;

        animal a1  = show_animal(number_register, 0);
        r = send(socketfd, &a1, sizeof(a1), 0);
        //cout << "Animal to send \n" << to_string(a1) <<"\n";
        if (r != sizeof(a1)){
            //Re send;
            cout << "\t\tServer: The message have not been sent completely. \n";
        }else{
            cout << "\t\tServer: The animal has been sent. \n";
        }

        //Now overwrite the register
        r = recv(socketfd, &a1, sizeof(a1), 0);
        if (r != sizeof(a1)){
            //Re send
            cout << "\t\tServer: The message have not been receive completely. \n";
        }else{
            cout << "\t\tServer: The animal has been receive. \n";
        }

        int pos  = write_animal(a1, number_register);
    //    read(pipefd[READ], mensaje, 5);
    //    LOCK_CLINICAL = false;
        mtx2.unlock();
        printf("Animal written in the pos %d \n", pos);

    }
    return "";
}
