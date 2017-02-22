
/*
 * In this example I show how to create  a hash_table, 
 * insert some items and after that show that linked list. 
 * Finally this is write in disk and read from disk, like a
 * RAM memory.
 */

void example_creating_hash_table(){
    hash_table  a = get_hash_table();  //This create the hash table from scratch
                                       //In another situation we need to load first
                                       //Just a example
    int hash = 15; 
    node * linked  = a[hash];    
    insert_linked_list(linked, 231);
    insert_linked_list(linked, 543);
    insert_linked_list(linked, 429);

    a[hash] = linked; //This is the tricky part, bullshit 

   // show_linked_list (a[hash]);

   // write_hash_table(a);
   // read_hash_table();

}

void example_loading_hash_table(){
    hash_table a = read_hash_table();
    
}




/*
 * This example, I show how to create an animal, writing in disk and 
 * Finally read that Animal in disk. 
 */
void example_write_show_animal(){
    //animal a1;
    
    animal a1("Tris", "perro", 1, "Criollo", 30, 35, 'F');  
    
    /* cout << "string: " << sizeof (string) << endl;
    cout << "Animal size: " << sizeof(animal) << endl;*/
    
    write_animal(a1,1);
    read_animal("Perro");
    read_animal("Tris");
  //  show(a1);
}


