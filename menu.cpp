#include <iostream>
#include <fstream>
#include <string>
#include "mode.h"
using namespace std;

void load()
{
    struct administrator A;
    string name, password;
    A.id = "212106015";
    A.password = "jiyilin";
a:
    cout << "请输入账号:";
    cin >> name;
    cout << endl;
    cout << "请输入密码";
    cin >> password;
    if (password != A.password || name != A.id)
    {
        cout << "账号密码错误,请重新输入" << endl;
        goto a;
    }
}

void load1()
{
    string name, id_teacher;
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入id:";
    cin >> id_teacher;
    ifstream teacher20;
    teacher20.open("./data_teacher.txt", ios::in);
    char clock[50] = {"\n"};
    int a = 0;
    while (teacher20 >> clock)
    {
        if (clock == name)
        {
            a = 1;
        }
        if (a == 1)
        {
            if (clock == id_teacher)
            {
                a = 2;
                break;
            };
        };
    }
    if (a != 2)
    {
        cout << "输入错误,请重新输入" << endl;
        teacher_menu();
    }
}

void student_menu()
{
    cout << "============================================" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "===-<         欢迎使用学生端系统        >-===" << endl;
    cout << "===-   1.注册                           -===" << endl;
    cout << "===-   2.查询                           -===" << endl;
    cout << "===-   3.退出                           -===" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "============================================" << endl;
    student();
}

void teacher_menu()
{
    cout << "============================================" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "===-<         欢迎使用教师端系统        >-===" << endl;
    cout << "===-   1.学生注册                       -===" << endl;
    cout << "===-   2.学生数据查询                   -===" << endl;
    cout << "===-   3.学生数据修改                   -===" << endl;
    cout << "===-   4.学生数据全览                   -===" << endl;
    cout << "===-   5.退出                          -===" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "============================================" << endl;
    teacher();
}

void administrator_menu()
{
    cout << "============================================" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "===-<       欢迎使用管理员端系统        >-===" << endl;
    cout << "===-   1.学生注册                       -===" << endl;
    cout << "===-   2.学生数据查询                   -===" << endl;
    cout << "===-   3.学生数据修改                   -===" << endl;
    cout << "===-   4.学生数据全览                   -===" << endl;
    cout << "===-   5.教师注册                       -===" << endl;
    cout << "===-   6.教师数据查询                   -===" << endl;
    cout << "===-   7.教师数据修改                   -===" << endl;
    cout << "===-   8.教师数据全览                  -===" << endl;
    cout << "===-   9.格式化系统                     -===" << endl;
    cout << "===-   10.退出                          -===" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "============================================" << endl;
    administrator();
}

void menu()
{
    cout << "============================================" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "===-<       欢迎使用学生管理系统        >-===" << endl;
    cout << "===-   1.我是学生                       -===" << endl;
    cout << "===-   2.我是教师                       -===" << endl;
    cout << "===-   3.我是管理员                     -===" << endl;
    cout << "===-   4.退出                           -===" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "============================================" << endl;
}

void register_student()
{
    student1 clock;
}

void register_teacher()
{
    teacher1 clock;
}

int read_counter1()
{
    int a;
    ifstream number;
    number.open("./counter_teacher.txt", ios::in);
    number >> a;
    return a;
}

void writer_counter1(int key)
{
    ofstream number;
    number.open("./counter_teacher.txt", ios::out);
    number << key + 1;
}

teacher1::teacher1()
{
    ofstream writer;
    writer.open("./data_teacher.txt", ios::app);
    cout << "请输入姓名" << endl;
    cin >> name;
    writer << name << " ";
    cout << "请输入学号" << endl;
    cin >> id;
    writer << id << " ";
    cout << "请输入宿舍地址" << endl;
    cin >> address;
    writer << address << " ";
    cout << "请输入电话号码" << endl;
    cin >> telephone;
    writer << telephone << " ";
    cout << "请输入性别" << endl;
    cin >> sex;
    writer << sex << endl;
    cout << "登记完成" << endl;
    writer.close();
    int n;
    n = read_counter1();
    writer_counter1(n);
}

void menu_mode()
{
    int button;
again:
    menu();
    cin >> button;
    switch (button)
    {
    case 1:
        student_menu();
        break;
    case 2:
        load1();
        teacher_menu();
        break;
    case 3:
        load();
        administrator_menu();
        break;
    case 4:
        break;
    default:
        cout << "输入错误,请重新输入" << endl;
        goto again;
        break;
    };
}

void format_mode()
{
    ofstream c_teacher, C_student, d_student, d_teacher;
    c_teacher.open("./counter_teacher.txt", ios::out);
    c_teacher << 0;
    c_teacher.close();
    C_student.open("./counter_student.txt", ios::out);
    C_student << 0;
    C_student.close();
    d_student.open("./data_student.txt", ios::out);
    d_teacher.open("./data_teacher.txt", ios::out);
    d_student.clear();
    d_teacher.clear();
    d_student.close();
    d_teacher.close();
}

void search_teacher()
{
    int n;
    ifstream text;
    text.open("./data_teacher.txt", ios::in);
    char clock[50] = {"\n"};
    int v = 0, m = 0;
    string eval;
    cout << "请输入要查询的人员姓名" << endl;
    cin >> eval;
    int b = 0;
    while (text >> clock)
    {
        if (clock == eval)
        {
            m = 1;
            v++;
        }
        if (v >= 1 && v <= 5)
        {
            b++;
            if (b > 5)
            {
                goto w_w_W_W_W;
            }
            cout << clock << "\t";
        }
    };
    if (m == 0)
    {
        cout << "查无此人" << endl;
    }
w_w_W_W_W:
    cout << endl;
}

void read_teacher()
{
    int n;
    ifstream text;
    text.open("./data_teacher.txt", ios::in);
    char clock[50] = {"\n"};
    int v = 0;
    while (text >> clock)
    {
        cout << clock << "\t";
        v++;
        if (v == 5)
        {
            cout << endl;
            v = 0;
        }
    }
}

void revise_teacher()
{
    system("data_teacher.txt");
}

void revise_student()
{
    system("data_student.txt");
}

student1::student1()
{
    ofstream writer;
    writer.open("./data_student.txt", ios::app);
    cout << "请输入姓名" << endl;
    cin >> name;
    writer << name << " ";
    cout << "请输入学号" << endl;
    cin >> id;
    writer << id << " ";
    cout << "请输入宿舍地址" << endl;
    cin >> address;
    writer << address << " ";
    cout << "请输入电话号码" << endl;
    cin >> telephone;
    writer << telephone << " ";
    cout << "请输入性别" << endl;
    cin >> sex;
    writer << sex << endl;
    cout << "登记完成" << endl;
    writer.close();
    int n;
    n = read_counter();
    writer_counter(n);
}

int read_counter()
{
    int a;
    ifstream number;
    number.open("./counter_student.txt", ios::in);
    number >> a;
    return a;
}

void writer_counter(int key)
{
    ofstream number;
    number.open("./counter_student.txt", ios::out);
    number << key + 1;
}

void search_student()
{
    int n;
    ifstream text;
    text.open("./data_student.txt", ios::in);
    char clock[50] = {"\n"};
    int v = 0, m = 0;
    string eval;
    cout << "请输入要查询的人员姓名" << endl;
    cin >> eval;
    int b = 0;
    while (text >> clock)
    {
        if (clock == eval)
        {
            m = 1;
            v++;
        }
        if (v >= 1 && v <= 5)
        {
            b++;
            if (b > 5)
            {
                goto w_w_W_W_W;
            }
            cout << clock << "\t";
        }
    };
    if (m == 0)
    {
        cout << "查无此人" << endl;
    }
w_w_W_W_W:
    cout << endl;
}

void read_student()
{
    int n;
    ifstream text;
    text.open("./data_student.txt", ios::in);
    char clock[50] = {"\n"};
    int v = 0;
    while (text >> clock)
    {
        cout << clock << "\t";
        v++;
        if (v == 5)
        {
            cout << endl;
            v = 0;
        }
    }
}

void student()
{
    int botton;
    cin >> botton;
    if (botton == 1)
    {
        register_student();
        student_menu();
    }
    else if (botton == 2)
    {
        search_student();
        student_menu();
    }
    else if (botton == 3)
    {
        cout << "已成功退出" << endl;
    }
    else
    {
        cout << "输入错误,请重新输入" << endl;
        student_menu();
    }
}

void teacher()
{
    int botton;
    cin >> botton;
    if (botton == 1)
    {
        register_student();
        teacher_menu();
    }
    else if (botton == 2)
    {
        search_student();
        teacher_menu();
    }
    else if (botton == 3)
    {
        revise_student();
        teacher_menu();
    }
    else if (botton == 4)
    {
        read_student();
        teacher_menu();
    }
    else if (botton == 5)
    {
        cout << "已成功退出" << endl;
    }
    else
    {
        cout << "输入错误,请重新输入" << endl;
        teacher_menu();
    }
}

void administrator()
{
    int botton;
    cin >> botton;
    if (botton == 1)
    {
        register_student();
        administrator_menu();
    }
    else if (botton == 2)
    {
        search_student();
        administrator_menu();
    }
    else if (botton == 3)
    {
        revise_student();
        administrator_menu();
    }
    else if (botton == 4)
    {
        read_student();
        administrator_menu();
    }
    else if (botton == 5)
    {
        register_teacher();
        administrator_menu();
    }
    else if (botton == 6)
    {
        search_teacher();
        administrator_menu();
    }
    else if (botton == 7)
    {
        revise_teacher();
        administrator_menu();
    }
    else if (botton == 8)
    {
        read_teacher();
        administrator_menu();
    }
    else if (botton == 9)
    {
        format_mode();
        administrator_menu();
    }
    else if (botton == 10)
    {
        cout << "已成功退出" << endl;
    }
    else
    {
        cout << "输入错误,请重新输入" << endl;
        administrator_menu();
    }
}
