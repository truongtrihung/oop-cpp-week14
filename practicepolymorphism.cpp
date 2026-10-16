#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string cccd;
    string phone;
    string address;

public:
    Employee() {
       cccd = "";
       phone = "";
       address = "";
    } 
    Employee(string c, string p, string a) {
        cccd = c;
        phone = p;
        address = a;
    }

    virtual double calculateSalary(int month, int year) = 0;

    virtual void displayInfo() {
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee() = default;
};

// ==========================================
class HourlyEmployee : public Employee {
private:
    int hours;
    double salaryPerHour;
    int month, year;

public:
    HourlyEmployee() : Employee() {
        hours = 0;
        salaryPerHour = 0.0;
        month = 0;
        year = 0;
    } 
    
    HourlyEmployee(string c, string p, string a, int h, double s, int m, int y) : Employee(c, p, a) {
        hours = h;
        salaryPerHour = s;
        month = m;
        year = y;
    }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return hours * salaryPerHour;

        return 0;
    }

    void displayInfo() override {
        Employee::displayInfo();
        cout << "Type: Hourly Employee (" << month << "/" << year << ")" << endl;
    }
};

// ==========================================
class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month, year;

public:
    MonthlyEmployee() : Employee() {
        monthlySalary = 0.0;
        month = 0;
        year = 0;
    }

    MonthlyEmployee(string c, string p, string a, double s, int m, int y)
        : Employee(c, p, a) {
        monthlySalary = s;
        month = m;
        year = y;
    }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return monthlySalary;

        return 0;
    }

    void displayInfo() override {
        Employee::displayInfo();
        cout << "Type: Monthly Employee (" << month << "/" << year << ")" << endl;
    }
};

// ==========================================
class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month, year;

public:
    DailyEmployee() : Employee() {
        numberOfDays = 0;
        salaryPerDay = 0.0;
        month = 0;
        year = 0;
    }

    DailyEmployee(string c, string p, string a, int d, double s, int m, int y)
        : Employee(c, p, a) {
        numberOfDays = d;
        salaryPerDay = s;
        month = m;
        year = y;
    }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year)
            return numberOfDays * salaryPerDay;

        return 0;
    }

    void displayInfo() override {
        Employee::displayInfo();
        cout << "Type: Daily Employee (" << month << "/" << year << ")" << endl;
    }
};

// ==========================================
// Hàm tính tổng lương cả năm của danh sách nhân viên
double calculateYearlySalary(Employee* employees[], int size, int year) {
    double totalYearlySalary = 0;
    
    // Duyệt qua từng nhân viên trong danh sách
    for (int i = 0; i < size; ++i) {
        // Duyệt qua cả 12 tháng trong năm đó để cộng dồn lại
        for (int month = 1; month <= 12; ++month) {
            totalYearlySalary += employees[i]->calculateSalary(month, year);
        }
    }
    return totalYearlySalary;
}

int main() {
    HourlyEmployee h(
        "001", "0901", "HCM",
        160, 50000, 10, 2026
    );

    MonthlyEmployee m(
        "002", "0902", "Dong Nai",
        15000000, 10, 2026
    );

    DailyEmployee d(
        "003", "0903", "Ha Noi",
        22, 400000, 10, 2026
    );

    // Con trỏ lớp cha trỏ đến đối tượng lớp con
    Employee* employees[] = {&h, &m, &d};
    int totalEmployees = sizeof(employees) / sizeof(employees[0]);

    cout << "=== LUONG THANG 10/2026 CHI TIET ===" << endl;
    for (Employee* e : employees) {
        e->displayInfo();
        cout << "Salary: " << e->calculateSalary(10, 2026) << " VND" << endl;
        cout << "------------------------------------" << endl;
    }
     
    // Gọi hàm tính lương theo năm cho năm 2026
    double yearlySalary = calculateYearlySalary(employees, totalEmployees, 2026);
    cout << "==> Tong quy luong cua toan bo nhan vien trong nam 2026: " << yearlySalary << " VND" << endl;

    return 0;
}
