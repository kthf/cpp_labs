#include <iostream>

using namespace std;

enum WeaponType {
    ONEHANDED,
    TWOHANDED,
    BOW,
    CROSSBOW
};

class Weapon {
protected:
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
    virtual double get_damage();
    double get_weight();
    WeaponType get_weapon_type();
    
    void set_damage(double damage);

    bool is_max_weight(double max_weight);
    double sum_weight(Weapon* weapon);
    double sum_weight(double weight);

    virtual void Attack() {}

    bool operator>(Weapon weapon);
    bool operator<(Weapon weapon);
};

class MagicWeapon : public Weapon {
protected:
    double magic_damage;
public:
    MagicWeapon(std::string name, double damage, double weight, WeaponType weaponType, double magic_damage);
    MagicWeapon();

    double get_magic_damage();
    double get_damage() override;

    void Attack() override;
};

class DisposableWeapon : public Weapon {
protected:
    bool used = false;
public:
    DisposableWeapon(std::string name, double damage, double weight, WeaponType weaponType);
    DisposableWeapon();

    bool is_used();
    void Attack() override;
};


template<typename A, typename B>
class WeaponArms {
protected:
    A* weapon1;
    B* weapon2;
public:
    WeaponArms(A* weapon1, B* weapon2);

    A* get_weapon1();
    B* get_weapon2();

    void set_weapon1(A* weapon1);
    void set_weapon2(B* weapon2);
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


