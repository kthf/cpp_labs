#include <iostream>


class Weapon {
public:
    std::string name;
    double damage;
    double weight;

    Weapon(std::string name, double damage, double weight);
    Weapon();
    ~Weapon();

    bool is_max_weight(double max_weight);
    double sum_weight(Weapon* weapon);
    double sum_weight(double weight);

};