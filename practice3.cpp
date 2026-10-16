#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Drinks {
private:
    string id;
    string name;

public:
    Drinks() {
        id = "";
        name = "";
    }
    Drinks(string i, string n) {
        id = i;
        name = n;
    }

    // Hàm trừu tượng tính doanh thu theo ngày/tháng/năm
    virtual double calculateRevenue(int d, int m, int y) = 0;

    virtual void displayInfo() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }

    // Getter & Setter
    string getId() const { return id; }
    string getName() const { return name; }
    void setId(string i) { id = i; }
    void setName(string n) { name = n; }

    virtual ~Drinks() = default;
};

class Coffee : public Drinks {
private:
    int quantity;
    double price;
    int day, month, year;

public:
    Coffee() : Drinks(), quantity(0), price(0.0), day(0), month(0), year(0) {}
    Coffee(string i, string n, int q, double p, int d, int m, int y)
        : Drinks(i, n), quantity(q), price(p), day(d), month(m), year(y) {}

    double calculateRevenue(int d, int m, int y) override {
        if (d == day && m == month && y == year)
            return quantity * price;
        return 0;
    }
};

class Tea : public Drinks {
private:
    int quantity;
    double price;
    int day, month, year;

public:
    Tea() : Drinks(), quantity(0), price(0.0), day(0), month(0), year(0) {}
    Tea(string i, string n, int q, double p, int d, int m, int y)
        : Drinks(i, n), quantity(q), price(p), day(d), month(m), year(y) {}

    double calculateRevenue(int d, int m, int y) override {
        if (d == day && m == month && y == year)
            return quantity * price;
        return 0;
    }
};

class Smoothies : public Drinks {
private:
    int quantity;
    double price;
    int day, month, year;

public:
    Smoothies() : Drinks(), quantity(0), price(0.0), day(0), month(0), year(0) {}
    Smoothies(string i, string n, int q, double p, int d, int m, int y)
        : Drinks(i, n), quantity(q), price(p), day(d), month(m), year(y) {}

    double calculateRevenue(int d, int m, int y) override {
        if (d == day && m == month && y == year)
            return quantity * price;
        return 0;
    }
};

class Juices : public Drinks {
private:
    int quantity;
    double price;
    int day, month, year;

public:
    Juices() : Drinks(), quantity(0), price(0.0), day(0), month(0), year(0) {}
    Juices(string i, string n, int q, double p, int d, int m, int y)
        : Drinks(i, n), quantity(q), price(p), day(d), month(m), year(y) {}

    double calculateRevenue(int d, int m, int y) override {
        if (d == day && m == month && y == year)
            return quantity * price;
        return 0;
    }
};

class Foods {
private:
    string id;
    string name;

public:
    Foods() {
        id = "";
        name = "";
    }
    Foods(string i, string n) {
        id = i;
        name = n;
    }

    // Hàm trừu tượng tính doanh thu theo ngày/tháng/năm
    virtual double calculateRevenue(int d, int m, int y) = 0;

    virtual void displayInfo() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }

    // Getter & Setter
    string getId() const { return id; }
    string getName() const { return name; }
    void setId(string i) { id = i; }
    void setName(string n) { name = n; }

    virtual ~Foods() = default;
};

class Cake : public Foods {
private:
    int quantity;
    double price;
    int day, month, year;

public:
    Cake() : Foods(), quantity(0), price(0.0), day(0), month(0), year(0) {}
    Cake(string i, string n, int q, double p, int d, int m, int y)
        : Foods(i, n), quantity(q), price(p), day(d), month(m), year(y) {}

    double calculateRevenue(int d, int m, int y) override {
        if (d == day && m == month && y == year)
            return quantity * price;
        return 0;
    }
};

class Breads : public Foods {
private:
    int quantity;
    double price;
    int day, month, year;

public:
    Breads() : Foods(), quantity(0), price(0.0), day(0), month(0), year(0) {}
    Breads(string i, string n, int q, double p, int d, int m, int y)
        : Foods(i, n), quantity(q), price(p), day(d), month(m), year(y) {}

    double calculateRevenue(int d, int m, int y) override {
        if (d == day && m == month && y == year)
            return quantity * price;
        return 0;
    }
};

double calculateDailyDrinksRevenue(Drinks* drinksList[], int size, int d, int m, int y) {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        total += drinksList[i]->calculateRevenue(d, m, y);
    }
    return total;
}

double calculateDailyFoodsRevenue(Foods* foodsList[], int size, int d, int m, int y) {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        total += foodsList[i]->calculateRevenue(d, m, y);
    }
    return total;
}

int main() {
    int targetDay = 16;
    int targetMonth = 10;
    int targetYear = 2026;

    Coffee cf("D001", "Espresso", 10, 45000, 16, 10, 2026);
    Tea t("D002", "Oolong Tea", 15, 40000, 16, 10, 2026);
    Smoothies sm("D003", "Mango Smoothie", 8, 55000, 16, 10, 2026);
    Juices j("D004", "Orange Juice", 12, 45000, 17, 10, 2026); // Ngày 17 (không tính vào ngày 16)

    // Đưa vào mảng con trỏ Drinks
    Drinks* drinksMenu[] = {&cf, &t, &sm, &j};
    int totalDrinks = sizeof(drinksMenu) / sizeof(drinksMenu[0]);

    // --- Khởi tạo các món Đồ ăn ---
    Cake c("F001", "Tiramisu", 5, 60000, 16, 10, 2026);
    Breads b("F002", "Croissant", 20, 30000, 16, 10, 2026);

    // Đưa vào mảng con trỏ Foods
    Foods* foodsMenu[] = {&c, &b};
    int totalFoods = sizeof(foodsMenu) / sizeof(foodsMenu[0]);

    // --- Tính toán doanh thu ---
    double dailyDrinksRev = calculateDailyDrinksRevenue(drinksMenu, totalDrinks, targetDay, targetMonth, targetYear);
    double dailyFoodsRev = calculateDailyFoodsRevenue(foodsMenu, totalFoods, targetDay, targetMonth, targetYear);

    // --- Hiển thị kết quả ---
    cout << "=== TONG DOANH THU NGAY " << targetDay << "/" << targetMonth << "/" << targetYear << " ===" << endl;
    cout << "- Drinks: " << dailyDrinksRev << " VND" << endl;
    cout << "- Foods : " << dailyFoodsRev << " VND" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "=> Tong cong: " << (dailyDrinksRev + dailyFoodsRev) << " VND" << endl;

    return 0;
}
