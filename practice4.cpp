#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Vehicle {
private:
    string id;
    string brand;
    double basePricePerDay;

public:
    Vehicle() {
        id = "";
        brand = "";
        basePricePerDay = 0.0;
    }

    Vehicle(string i, string b, double price) {
        id = i;
        brand = b;
        basePricePerDay = price;
    }

    // Hàm thuần ảo tính phí thuê (Tính trừu tượng)
    virtual double calculateRentalFee(int days) const = 0;

    // Hàm ảo hiển thị thông tin
    virtual void displayInfo() const {
        cout << "ID: " << id << " | Brand: " << brand << " | Base Price/Day: " << basePricePerDay << " VND";
    }

    // Getter 
    string getId() const { return id; }
    string getBrand() const { return brand; }
    double getBasePricePerDay() const { return basePricePerDay; }

    // Setter
    void setId(string i) { id = i; }
    void setBrand(string b) { brand = b; }
    void setBasePricePerDay(double price) { basePricePerDay = price; }

    // Hàm hủy ảo tránh rò rỉ bộ nhớ
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    Car() : Vehicle() {}
    Car(string i, string b, double price) : Vehicle(i, b, price) {}

    // Số ngày × đơn giá, giảm 10% nếu thuê từ 7 ngày trở lên
    double calculateRentalFee(int days) const override {
        double total = days * getBasePricePerDay();
        if (days >= 7) {
            total *= 0.9; // Giảm 10%
        }
        return total;
    }

    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi hàm của lớp cha
        cout << " | Type: Car" << endl;
    }
};

class Motorbike : public Vehicle {
public:
    Motorbike() : Vehicle() {}
    Motorbike(string i, string b, double price) : Vehicle(i, b, price) {}

    // Số ngày × đơn giá, giảm 5% nếu thuê từ 5 ngày trở lên
    double calculateRentalFee(int days) const override {
        double total = days * getBasePricePerDay();
        if (days >= 5) {
            total *= 0.95; // Giảm 5%
        }
        return total;
    }

    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi hàm của lớp cha
        cout << " | Type: Motorbike" << endl;
    }
};

class Truck : public Vehicle {
private:
    double fixedDeliveryFee; // Phí vận chuyển cố định đặc trưng của Xe tải

public:
    Truck() : Vehicle() {
        fixedDeliveryFee = 0.0;
    }
    Truck(string i, string b, double price, double fee) : Vehicle(i, b, price) {
        fixedDeliveryFee = fee;
    }

    // Số ngày × đơn giá + phí vận chuyển cố định
    double calculateRentalFee(int days) const override {
        return (days * getBasePricePerDay()) + fixedDeliveryFee;
    }

    void displayInfo() const override {
        Vehicle::displayInfo(); // Gọi hàm của lớp cha
        cout << " | Type: Truck | Fixed Delivery Fee: " << fixedDeliveryFee << " VND" << endl;
    }

    // Getter & Setter riêng cho Truck
    double getFixedDeliveryFee() const { return fixedDeliveryFee; }
    void setFixedDeliveryFee(double fee) { fixedDeliveryFee = fee; }
};

int main() {

    return 0;
}
