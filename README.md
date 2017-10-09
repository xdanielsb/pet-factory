### Pet Factory
---

### Abstract

In this project 100 million of registers belongs to animals are created in such a way that it is inefficient load them in memory, This project propose a system to create, update, delete read registers in disk  without load the registers in memory. Besides the architecture is client-server so many clients can connect and update registers it's important remark that the system makes control of critical sections using different techniques mention below.

---

### Features

- The architecture is client-server
- The program was created using POXIS functions
- Control of critical sections using
  - Mutex
  - Semaphores
  - Named pipes
- Parallel tasks  using
  - pthread
  - fork - join
- Shared memory 

---

### How to run the application?
Follow the next steps

```sh
$ git clone name_repository
$ cd name_repository/server
$ make

Open another terminal

$ cd  name_repository/client
$ make

```
---

## Screenshot 3 clients 1 Server

![Alt Pet Factory](docs/screenshot_3_clients.png?raw=true "Title")


### About the author

* Name : DANIEL FERNANDO SANTOS BUSTOS
* Email : dfsantosbu@unal.edu.co
* Description: Just a person that likes turning  magic  things in something  real .

---

### License

MIT

**Free Software, It's the right way  to do things!**
