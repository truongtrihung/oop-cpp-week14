#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected:
    string id;
    string phone;
    string address;
public :
    Employee () {
        id = "";
        phone = "";
        address = "";
    }
    Employee (string i, string p, string ad) {
        id = i;
        phone = p;
        address = ad;
    }

    // Getter
    string getID () const {return id;}
    string getPhone () const {return phone;}
    string getAddress () const {return address;}

    // Setter
    void setID (string i) {id = i;}
    void setPhone (string p) {phone = p;}
    void setAddress (string ad) {address = ad;}
};

class HourlyEmployee : public Employee {
private :
    int hours;
    double salaryPerHours;
    int month;
    int year;
public :
    HourlyEmployee () : Employee () {
        hours = 0;
        salaryPerHours = 0.0;
        month = 0;
        year = 0;
    }
    HourlyEmployee (string i, string p, string ad, int h, double sph, int m, int y) : Employee (i, p, ad) {
        hours = h;
        salaryPerHours = sph;
        month = m;
        year = y;
    }

    // Getter 
    int getSoGioLamViec () const {return hours;}
    double getLuongMoiGio () const {return salaryPerHours;}
    int getSoThangLam () const {return month;}
    int getSoNamLam () const {return year;}

    // Setter
    void setSoGioLamViec (int h) {hours = h;}
    void setLuongMoiGio (double sph) {salaryPerHours = sph;}
    void setSoThangLam (int m) {month = m;}
    void setSoNamLam (int y) {year = y;}    
};

class MonthlyEmployee : public Employee {
private:
    double monthlySalary; // Lương cố định nhận của tháng đó
    int month;
    int year;
public:
    MonthlyEmployee() : Employee() {
        monthlySalary = 0.0;
        month = 0;
        year = 0;
    }
    MonthlyEmployee(string i, string p, string ad, double ms, int m, int y) : Employee(i, p, ad) {
        monthlySalary = ms;
        month = m;
        year = y;
    }

    // Getter
    double getMonthlySalary() const { return monthlySalary; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    // Setter
    void setMonthlySalary(double ms) { monthlySalary = ms; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
};

class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay; // Định mức lương theo ngày
    int month;
    int year;
public:
    DailyEmployee() : Employee() {
        numberOfDays = 0;
        salaryPerDay = 0.0;
        month = 0;
        year = 0;
    }
    DailyEmployee(string i, string p, string ad, int nod, double spd, int m, int y) : Employee(i, p, ad) {
        numberOfDays = nod;
        salaryPerDay = spd;
        month = m;
        year = y;
    }
    
    // Getter
    int getNumberOfDays() const { return numberOfDays; }
    double getSalaryPerDay() const { return salaryPerDay; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setter
    void setSalaryPerDay(double spd) { salaryPerDay = spd; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
};
int main() {

    return 0;
}