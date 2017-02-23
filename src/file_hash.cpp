#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> //exit();

//Good reference http://courses.cs.vt.edu/~cs2604/fall00/binio.html#seekg

inline void write_file_hash(vvi data){
    ofstream outFile;
    outFile.open("var/new_hash_table.txt");
    //Check for error
    if(outFile.fail()){
        cerr << "Error opening file" << endl;
        exit(1);
    }
    for(int i=0; i< size_hash_table; i++){
        ll num_columns = data[i].size();
        outFile << num_columns << " ";
        for(int j=0; j< num_columns; j++){
            outFile << data[i][j]  << " ";
        }
        outFile << endl;
    }
    outFile.close();
}


inline vvi read_file_hash(){
    ifstream  inFile;
    inFile.open("var/new_hash_table.txt");
    vvi re;
    //Check for error
    if(inFile.fail()){
        cerr << "Error opening file" << endl;
        exit(1);
    }

    int size, data;
    int counter = 0;
    //Read the file until you have reached the end
    while (!inFile.eof()){
        inFile >> size;
        vi row_h(size);
        for (int j = 0; j<size; j++){
            inFile >> data;
            row_h[j]=data;
        }
        re.push_back(row_h);
        counter++;
   }
   return re;
}

/*
int main(){
    write_file_hash();
    //read_file_hash();
}*/

