# Student Course Management System

A menu-driven C++ console application for managing students and course enrollments.
Built using OOP principles, STL containers, and STL algorithms.

## Installation

Make sure you have a C++ compiler installed (g++, MinGW, or MSVC).

```bash
g++ main.cpp -o program
```

## Usage

```bash
# Linux / Mac
./program

# Windows
program.exe
```

Example:

```
=== Student Management System ===
1. Add Student
2. Remove Student
3. Search Student by ID
4. Display All Students
5. Enroll Student in Course
6. Show Student Courses
7. Sort Students by GPA
8. Search Student by Name
9. Save Data
10. Exit

Enter your choice: 1
Enter Student ID: 1001
Enter Name: Sarah
Enter GPA: 3.5
Student added successfully.
```

## Requirements

- C++ compiler with C++11 support or later
- Works on Windows, Linux, and Mac

## Features

- Add / Remove / Search students by ID or name
- Display all registered students
- Enroll students in courses (no duplicate courses allowed)
- Show all courses for a specific student
- Sort students by GPA (descending)
- Save data to file and load automatically on startup

## Project Structure

```
├── main.cpp        # Main source code
├── students.txt    # Auto-generated data file (created after first save)
├── uml_diagram.pdf # UML class diagram
└── README.md
```

## Contributing

This is an individual academic project. Pull requests are not open at this time.

## Authors and Acknowledgment

**Sarah Abdelsamie Ahmed** — Student ID: 12257

## License

This project is submitted as part of an academic assignment and is not licensed for redistribution.
