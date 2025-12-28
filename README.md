# Assignment-3

A small C++ program that demonstrates single inheritance and destructor order for a simple school system with **User**, **Student**, **Teacher**, and **Admin** classes. Each object logs its lifecycle (construction, actions, and destruction) to the console to make ownership and cleanup visible.

## Prerequisites
- C++ compiler (e.g., `g++`, clang, or MSVC)
- Optional: Visual Studio can open the provided `Assignment-3.vcxproj`

## Build & Run
### Using g++
```bash
cd /home/runner/work/Assignment-3/Assignment-3/Assignment-3
g++ Assignment-3.cpp -o assignment3
./assignment3
```

### Using Visual Studio
1. Open `Assignment-3/Assignment-3.vcxproj`.
2. Build the solution.
3. Run the produced executable from Visual Studio or the output directory.

## Program Flow
1. Creates one `Student`, one `Teacher`, and one `Admin`, each derived from `User`.
2. Calls `login()` plus a role-specific action (`registerCourse`, `uploadMarks`, `manageSystem`).
3. Exiting scope triggers destructors in reverse creation order, illustrating proper cleanup.

## Sample Output
```
=== STARTING SYSTEM SIMULATION ===

--- Creating Objects ---
[User Constructor] Created User: Zamad (ID: 1001)
  -> [Student Constructor] Initialized Student specifics.
Zamad logged in.
Action: Zamad is registering for a course.

[User Constructor] Created User: Prof. Ahmed (ID: 2001)
  -> [Teacher Constructor] Initialized Teacher specifics.
Prof. Ahmed logged in.
Action: Prof. Ahmed is uploading marks.

[User Constructor] Created User: SysAdmin (ID: 9999)
  -> [Admin Constructor] Initialized Admin specifics.
SysAdmin logged in.
Action: SysAdmin is managing system configurations.

--- Exiting Scope (Destructors Triggered) ---
  -> [Admin Destructor] Cleaning up Admin resources.
[User Destructor] Cleaning up User: SysAdmin
  -> [Teacher Destructor] Cleaning up Teacher resources.
[User Destructor] Cleaning up User: Prof. Ahmed
  -> [Student Destructor] Cleaning up Student resources.
[User Destructor] Cleaning up User: Zamad

=== END OF PROGRAM ===
```
