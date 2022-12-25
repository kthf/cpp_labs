#include <iostream>


class Weapon {
private:
    std::string name;
    double damage;
    double weight;

    friend class Characteristic;

public:
    Weapon(std::string name, double damage, double weight);
    Weapon();
    ~Weapon();

    std::string get_name();
    double get_damage();
    double get_weight();
    
    void set_damage(double damage);

    bool is_max_weight(double max_weight);
    double sum_weight(Weapon* weapon);
    double sum_weight(double weight);

};

class Characteristic {
private:
    double power;

public:
    Characteristic(double power);

    double get_damage(Weapon* weapon);
};

class MyMath {
public:
    static int count_calls;

    static double Add(double a, double b);
    static double Sub(double a, double b);
    static double Mult(double a, double b);
    static double Div(double a, double b);
};