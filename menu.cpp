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
    cout << "�������˺�:";
    cin >> name;
    cout << endl;
    cout << "����������";
    cin >> password;
    if (password != A.password || name != A.id)
    {
        cout << "�˺��������,����������" << endl;
        goto a;
    }
}

void load1()
{
    string name, id_teacher;
    cout << "������������";
    cin >> name;
    cout << "������id:";
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
        cout << "�������,����������" << endl;
        teacher_menu();
    }
}

void student_menu()
{
    cout << "============================================" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "===-<         ��ӭʹ��ѧ����ϵͳ        >-===" << endl;
    cout << "===-   1.ע��                           -===" << endl;
    cout << "===-   2.��ѯ                           -===" << endl;
    cout << "===-   3.�˳�                           -===" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "============================================" << endl;
    student();
}

void teacher_menu()
{
    cout << "============================================" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "===-<         ��ӭʹ�ý�ʦ��ϵͳ        >-===" << endl;
    cout << "===-   1.ѧ��ע��                       -===" << endl;
    cout << "===-   2.ѧ�����ݲ�ѯ                   -===" << endl;
    cout << "===-   3.ѧ�������޸�                   -===" << endl;
    cout << "===-   4.ѧ������ȫ��                   -===" << endl;
    cout << "===-   5.�˳�                          -===" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "============================================" << endl;
    teacher();
}

void administrator_menu()
{
    cout << "============================================" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "===-<       ��ӭʹ�ù���Ա��ϵͳ        >-===" << endl;
    cout << "===-   1.ѧ��ע��                       -===" << endl;
    cout << "===-   2.ѧ�����ݲ�ѯ                   -===" << endl;
    cout << "===-   3.ѧ�������޸�                   -===" << endl;
    cout << "===-   4.ѧ������ȫ��                   -===" << endl;
    cout << "===-   5.��ʦע��                       -===" << endl;
    cout << "===-   6.��ʦ���ݲ�ѯ                   -===" << endl;
    cout << "===-   7.��ʦ�����޸�                   -===" << endl;
    cout << "===-   8.��ʦ����ȫ��                  -===" << endl;
    cout << "===-   9.��ʽ��ϵͳ                     -===" << endl;
    cout << "===-   10.�˳�                          -===" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "============================================" << endl;
    administrator();
}

void menu()
{
    cout << "============================================" << endl;
    cout << "===--------------------------------------===" << endl;
    cout << "===-<       ��ӭʹ��ѧ������ϵͳ        >-===" << endl;
    cout << "===-   1.����ѧ��                       -===" << endl;
    cout << "===-   2.���ǽ�ʦ                       -===" << endl;
    cout << "===-   3.���ǹ���Ա                     -===" << endl;
    cout << "===-   4.�˳�                           -===" << endl;
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
    cout << "����������" << endl;
    cin >> name;
    writer << name << " ";
    cout << "������ѧ��" << endl;
    cin >> id;
    writer << id << " ";
    cout << "�����������ַ" << endl;
    cin >> address;
    writer << address << " ";
    cout << "������绰����" << endl;
    cin >> telephone;
    writer << telephone << " ";
    cout << "�������Ա�" << endl;
    cin >> sex;
    writer << sex << endl;
    cout << "�Ǽ����" << endl;
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
        cout << "�������,����������" << endl;
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
    cout << "������Ҫ��ѯ����Ա����" << endl;
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
        cout << "���޴���" << endl;
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
    cout << "����������" << endl;
    cin >> name;
    writer << name << " ";
    cout << "������ѧ��" << endl;
    cin >> id;
    writer << id << " ";
    cout << "�����������ַ" << endl;
    cin >> address;
    writer << address << " ";
    cout << "������绰����" << endl;
    cin >> telephone;
    writer << telephone << " ";
    cout << "�������Ա�" << endl;
    cin >> sex;
    writer << sex << endl;
    cout << "�Ǽ����" << endl;
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
    cout << "������Ҫ��ѯ����Ա����" << endl;
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
        cout << "���޴���" << endl;
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
        cout << "�ѳɹ��˳�" << endl;
    }
    else
    {
        cout << "�������,����������" << endl;
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
        cout << "�ѳɹ��˳�" << endl;
    }
    else
    {
        cout << "�������,����������" << endl;
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
        cout << "�ѳɹ��˳�" << endl;
    }
    else
    {
        cout << "�������,����������" << endl;
        administrator_menu();
    }
}
