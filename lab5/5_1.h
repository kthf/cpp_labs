#include <iostream>

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class Weapon {
private:
    std::string name;
    double damage;
    double weight;
    WeaponType weapon_type;

    friend class Characteristic;

public:
    Weapon(std::string name, double damage, double weight, WeaponType weaponType);
    Weapon();
    ~Weapon();

    std::string get_name();
    double get_damage();
    double get_weight();
    WeaponType get_weapon_type();
    
    void set_damage(double damage);

    bool is_max_weight(double max_weight);
    double sum_weight(Weapon* weapon);
    double sum_weight(double weight);
};

class MagicWeapon : public Weapon {
private:
    double magic_damage;
public:
    MagicWeapon(std::string name, double damage, double weight, WeaponType weaponType, double magic_damage);
    MagicWeapon();

    double get_magic_damage();
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

struct Player {
    int id;
    std::string login;
    std::string password;

    Player(int id, std::string login, std::string password);
    void print_info();
};