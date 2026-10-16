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
    // 6. Tạo danh sách phương tiện bằng vector<Vehicle*>
    vector<Vehicle*> rentalList;

    // Cấp phát động các đối tượng lớp con
    rentalList.push_back(new Car("C001", "Toyota Camry", 1200000));      // Thuê xe ô tô
    rentalList.push_back(new Motorbike("M001", "Honda Sh", 300000));     // Thuê xe máy
    rentalList.push_back(new Truck("T001", "Hyundai Mighty", 2000000, 500000)); // Xe tải + 500k phí ship cố định

    int rentalDays = 7; // Giả định tất cả đều thuê trong 7 ngày để test ưu đãi
    double totalRevenue = 0;

    cout << "=== DANH SACH PHUONG TIEN THUE (" << rentalDays << " NGAY) ===" << endl;
    for (size_t i = 0; i < rentalList.size(); ++i) {
        rentalList[i]->displayInfo(); // Thể hiện đa hình của displayInfo()
        double fee = rentalList[i]->calculateRentalFee(rentalDays); // Thể hiện đa hình tính phí
        cout << "-> Rental Fee: " << fee << " VND" << endl;
        cout << "--------------------------------------------------------" << endl;
        
        // Cộng dồn doanh thu
        totalRevenue += fee;
    }

    cout << "==> TONG DOANH THU THUE XE: " << totalRevenue << " VND" << endl << endl;

    // Tìm phương tiện có phí thuê cao nhất
    if (!rentalList.empty()) {
        Vehicle* highestVehicle = rentalList[0];
        double maxFee = highestVehicle->calculateRentalFee(rentalDays);

        for (size_t i = 1; i < rentalList.size(); ++i) {
            double currentFee = rentalList[i]->calculateRentalFee(rentalDays);
            if (currentFee > maxFee) {
                maxFee = currentFee;
                highestVehicle = rentalList[i];
            }
        }

        cout << "=== PHUONG TIEN CO PHI THUE CAO NHAT ===" << endl;
        highestVehicle->displayInfo();
        cout << "-> Cost: " << maxFee << " VND" << endl << endl;
    }

    // Thu hồi vùng nhớ động (Cực kỳ quan trọng để tránh Memory Leak)
    for (size_t i = 0; i < rentalList.size(); ++i) {
        delete rentalList[i];
    }
    rentalList.clear();

    return 0;
}
