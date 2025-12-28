#include <iostream>
#include <string>
using namespace std;

// Base Class
class User {
protected:
    string name;
    int id;

public:
    // Base Constructor
    User(string n, int i) : name(n), id(i) {
        cout << "[User Constructor] Created User: " << name << " (ID: " << id << ")" << endl;
    }

    // Base Destructor
    // declared virtual to ensure correct destructor sequence if deleted via base pointer
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

// Derived Class 1: Student
class Student : public User {
public:
    // Student Constructor calls User Constructor
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

// Derived Class 2: Teacher
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

// Derived Class 3: Admin
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

    // Using a local scope block {} to demonstrate destructor calls
    // before the program completely ends.
    {
        cout << "--- Creating Objects ---" << endl;

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
    // Objects are destroyed here in reverse order of creation (Stack behavior)

    cout << "\n=== END OF PROGRAM ===" << endl;
    return 0;
}
