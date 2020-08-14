### Pet Factory
---

### Abstract

In this project 100 million of registers belongs to animals are created in such a way that it is inefficient to load them in memory, This project proposes a system to create, update, delete read registers in disk without load the registers in memory. Besides the architecture is client-server so many clients can connect and update registers it's an important remark that the system takes control of critical sections using different techniques mentioned below.

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


---

### License

MIT
