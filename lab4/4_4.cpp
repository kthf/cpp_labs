#include "4_4.h"

Weapon::Weapon(std::string name, double damage, double weight) : name(name), damage(damage), weight(weight) {}
Weapon::Weapon() : name("default"), damage(0), weight(0) {}
Weapon::~Weapon() { std::cout << "Удаление объекта" << std::endl; }
bool Weapon::is_max_weight(double max_weight) { return max_weight < weight; }
double Weapon::sum_weight(Weapon* weapon) { return sum_weight(weapon->weight); }
double Weapon::sum_weight(double weight) { return this->weight + weight; }
std::string Weapon::get_name() { return name; }
double Weapon::get_damage() { return damage; }
double Weapon::get_weight() { return weight; }
void Weapon::set_damage(double damage) { this->damage = damage; }

Characteristic::Characteristic(double power) : power(power) {}
double Characteristic::get_damage(Weapon* weapon) { return weapon->damage + power; }

int MyMath::count_calls = 0;

double MyMath::Add(double a, double b) { MyMath::count_calls++; return a + b; }
double MyMath::Sub(double a, double b) { MyMath::count_calls++; return a - b; }
double MyMath::Mult(double a, double b) { MyMath::count_calls++; return a * b; }
double MyMath::Div(double a, double b) { MyMath::count_calls++; return a / b; }


int main() {
    Weapon* a = new Weapon("sword", 10.0, 5.0);
    assert(a->get_name() == "sword");
    assert(a->get_damage() == 10.0);
    assert(a->get_weight() == 5.0);
    a->set_damage(20.0);
    assert(a->get_damage() == 20.0);

    Characteristic b(10.0);
    assert(b.get_damage(a) == 30.0);

    assert(MyMath::Add(1.0, 2.0) == 3.0);
    assert(MyMath::Sub(1.0, 2.0) == -1.0);
    assert(MyMath::Mult(1.0, 2.0) == 2.0);
    assert(MyMath::Div(1.0, 2.0) == 0.5);
    assert(MyMath::count_calls == 4);
    std::cout << "Результат MyMath::Add(1.0, 2.0): " << MyMath::Add(1.0, 2.0) << std::endl;
    std::cout << "Результат MyMath::Sub(1.0, 2.0): " << MyMath::Sub(1.0, 2.0) << std::endl;
    std::cout << "Результат MyMath::Mult(1.0, 2.0): " << MyMath::Mult(1.0, 2.0) << std::endl;
    std::cout << "Результат MyMath::Div(1.0, 2.0): " << MyMath::Div(1.0, 2.0) << std::endl;
    std::cout << "Значение вызовов функций MyMath: " << MyMath::count_calls << std::endl;
}
