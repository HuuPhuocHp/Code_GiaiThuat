#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    int day, month, year;
    string gender;
    double gpa;
};

void saveStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Khong the mo file de ghi!" << endl;
        return;
    }
    for (const Student& student : students) {
        outFile << student.id << " " << student.firstName << " " << student.lastName << " "
                << student.day << " " << student.month << " " << student.year << " "
                << student.gender << " " << student.gpa << "\n";
    }
    outFile.close();
}

int main() {
    vector<Student> students = {
        {1, "Nguyen Van", "A", 1, 1, 2000, "Nam", 8.5},
        {2, "Tran Thi", "B", 2, 2, 2001, "Nu", 9.0}
    };

    saveStudentsToFile(students, "SINHVIEN.DAT");
    cout << "Da luu danh sach sinh vien vao file SINHVIEN.DAT" << endl;
    return 0;
}
