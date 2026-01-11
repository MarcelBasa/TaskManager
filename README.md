# TaskManager (C++)

**TaskManager** is a simple console-based task management application written in **C++17**.
The project demonstrates basic object-oriented design, file handling, and unit testing.

---

## Features

* Add, edit, delete, and display tasks
* Each task has:

  * unique ID
  * title and description
  * status and priority
  * creation date
* Save tasks to a file and load them back
* Interactive console menu
* Unit tests using GoogleTest

---

## Technologies

* C++17
* CMake
* GoogleTest
* Git

---

## Project Structure

```
TaskManager/
├─ CMakeLists.txt
├─ include/
├─ src/
├─ tests/
├─ build/        (ignored)
└─ data.txt
```

---

## Build & Run

```bash
mkdir build
cd build
cmake ..
cmake --build .
./TaskManager
```

---

## Run Tests

```bash
ctest --verbose
```

or directly:

```bash
./tests/TaskManagerTests --gtest_color=yes
```

---

## Purpose

This is a small educational project created to practice:

* modern C++ development
* CMake project structure
* unit testing with GoogleTest

---

## Author

Marcelo
