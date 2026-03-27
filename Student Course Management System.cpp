#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person() {}
    Person(string n) {
        name = n;
    }
    string getName() {
        return name;
    }
};

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;
public:
    Student() {}
    Student(int i, string n, double g) : Person(n) {
        id = i;
        gpa = g;
    }
    int getId() {
        return id;
    }
    double getGpa() {
        return gpa;
    }
    set<string> getCourses() {
        return courses;
    }
    void enrollCourse(string course) {
        courses.insert(course);
    }
    void display() {
        cout << "ID: " << id << " , Name: " << name << " , GPA: " << gpa << endl;
    }
};

vector<Student> students;

void displayAllStudents();

void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter Student ID: ";
    cin >> id;

    for (Student s : students) {
        if (s.getId() == id) {
            cout << "ID already exists.\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0.0 || gpa > 4.0) {
        cout << "GPA must be between 0.0 and 4.0\n";
        return;
    }

    students.push_back(Student(id, name, gpa));
    cout << "Student added successfully.\n";
}

void removeStudent() {
    int id;
    cout << "Enter Student ID to remove: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(), [id](Student s) {
        return s.getId() == id;
        });

    if (it != students.end()) {
        students.erase(it);
        cout << "Student removed successfully.\n";
    }
    else {
        cout << "Student not found.\n";
    }
}

void searchStudent() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(),
        [id](Student s) { return s.getId() == id; });

    if (it != students.end()) {
        it->display();
    }
    else {
        cout << "Student not found.\n";
    }
}

void displayAllStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }
    cout << "\n All Students \n";
    for (Student s : students) {
        s.display();
    }
}

void sortByGPA() {
    sort(students.begin(), students.end(),
        [](Student a, Student b) {
            return a.getGpa() > b.getGpa();
        });
    cout << "Students sorted by GPA:\n";
    displayAllStudents();
}

void enrollStudentInCourse() {
    int id;
    string course;

    cout << "Enter Student ID: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(),
        [id](Student s) { return s.getId() == id; });

    if (it != students.end()) {
        cout << "Enter Course Name: ";
        cin >> course;
        it->enrollCourse(course);
        cout << "Enrolled successfully.\n";
    }
    else {
        cout << "Student not found.\n";
    }
}

void showStudentCourses() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(),
        [id](Student s) { return s.getId() == id; });

    if (it != students.end()) {
        set<string> courses = it->getCourses();

        if (courses.empty()) {
            cout << "No courses enrolled.\n";
            return;
        }

        cout << "\n Courses \n";
        for (string course : courses) {
            cout << "- " << course << endl;
        }
    }
    else {
        cout << "Student not found.\n";
    }
}
void saveToFile() {
    ofstream file("students.txt");

    for (Student s : students) {
        file << s.getId() << ","
            << s.getName() << ","
            << s.getGpa();

        for (string course : s.getCourses()) {
            file << "," << course;
        }
        file << "\n";
    }

    file.close();
    cout << "Data saved successfully.\n";
}
void loadFromFile() {
    ifstream file("students.txt");

    if (!file.is_open()) {
        cout << "No saved data found.\n";
        return;
    }

    students.clear();
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 3) {
            int id = stoi(tokens[0]);
            string name = tokens[1];
            double gpa = stod(tokens[2]);

            Student s(id, name, gpa);

            for (int i = 3; i < tokens.size(); i++) {
                s.enrollCourse(tokens[i]);
            }

            students.push_back(s);
        }
    }
    file.close();
    cout << "Data loaded successfully.\n";
}
void searchByName() {
    string name;
    cout << "Enter student name to search: ";
    cin >> name;

    bool found = false;
    for (Student s : students) {
        if (s.getName() == name) {
            s.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No student found with name: " << name << "\n";
    }
}

int main() {
    loadFromFile();  
    int choice;

    while (true) {
        cout << "\n Student Management System \n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll Student in Course\n";
        cout << "6. Show Student Courses\n";
        cout << "7. Sort Students by GPA\n";
        cout << "8. Search Student by Name\n"; 
        cout << "9. Save Data\n";              
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:  addStudent();            break;
        case 2:  removeStudent();         break;
        case 3:  searchStudent();         break;
        case 4:  displayAllStudents();    break;
        case 5:  enrollStudentInCourse(); break;
        case 6:  showStudentCourses();    break;
        case 7:  sortByGPA();             break;
        case 8:  searchByName();          break;
        case 9:  saveToFile();            break;
        case 10:
            saveToFile(); 
            cout << "Thanks for using.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
