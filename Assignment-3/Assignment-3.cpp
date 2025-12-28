#include <iostream>
#include <string>
using namespace std;

// Base Class
class User {
protected:
    string name;
    int id;

public:

    User(string n, int i) : name(n), id(i) {
        cout << "[User Constructor] Created User: " << name << " (ID: " << id << ")" << endl;
    }


    // declared virtual to ensure correct destructor sequence
    virtual ~User() {
        cout << "[User Destructor] Cleaning up User: " << name << endl;
    }

    void login() {
        cout << name << " logged in." << endl;
    }

    void logout() {
        cout << name << " logged out." << endl;
    }
};

// Derived Class Student
class Student : public User {
public:

    Student(string n, int i) : User(n, i) {
        cout << "  -> [Student Constructor] Initialized Student specifics." << endl;
    }

    ~Student() {
        cout << "  -> [Student Destructor] Cleaning up Student resources." << endl;
    }

    void registerCourse() {
        cout << "Action: " << name << " is registering for a course." << endl;
    }
};

// Derived Class Teacher
class Teacher : public User {
public:
    Teacher(string n, int i) : User(n, i) {
        cout << "  -> [Teacher Constructor] Initialized Teacher specifics." << endl;
    }

    ~Teacher() {
        cout << "  -> [Teacher Destructor] Cleaning up Teacher resources." << endl;
    }

    void uploadMarks() {
        cout << "Action: " << name << " is uploading marks." << endl;
    }
};

// Derived Class Admin
class Admin : public User {
public:
    Admin(string n, int i) : User(n, i) {
        cout << "  -> [Admin Constructor] Initialized Admin specifics." << endl;
    }

    ~Admin() {
        cout << "  -> [Admin Destructor] Cleaning up Admin resources." << endl;
    }

    void manageSystem() {
        cout << "Action: " << name << " is managing system configurations." << endl;
    }
};

int main() {
    cout << "=== STARTING SYSTEM SIMULATION ===\n" << endl;

    {
        cout << "\n--- Creating Objects ---\n" << endl;

        // 1. Create Student
        Student s1("Zamad", 1001);
        s1.login();
        s1.registerCourse();
        cout << endl;

        // 2. Create Teacher
        Teacher t1("Prof. Ahmed", 2001);
        t1.login();
        t1.uploadMarks();
        cout << endl;

        // 3. Create Admin
        Admin a1("SysAdmin", 9999);
        a1.login();
        a1.manageSystem();

        cout << "\n--- Exiting Scope (Destructors Triggered) ---" << endl;
    }
  

    cout << "\n=== END OF PROGRAM ===" << endl;
    return 0;
}
