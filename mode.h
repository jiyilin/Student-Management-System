#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// main.cpp---over
int main();

// menu.cpp---over
void menu();
void student_menu();
void teacher_menu();
void administrator_menu();

// menu_mode.cpp---over
void menu_mode();
void student();
void teacher();
void administrator();

// function_student.cpp---over
void register_student();
void search_student();

//! function_teacher.cpp
void revise_student();
void read_student(); // over

//! function_administrator.cpp
void register_teacher(); // over
void search_teacher();   // over
void revise_teacher();
void read_teacher(); // over
void format_mode();  // over

class student1 //---over
{
private:
    string name;
    string id;
    string address;
    string telephone;
    string sex;

public:
    student1();
};

class teacher1 //---over
{
private:
    string name;
    string id;
    string address;
    string telephone;
    string sex;

public:
    teacher1();
};

struct administrator //---over
{
    string id;
    string password;
};

int read_counter();            // over
void writer_counter(int key);  // over
int read_counter1();           // over
void writer_counter1(int key); // over
void load();
void load1();