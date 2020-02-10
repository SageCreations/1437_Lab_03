#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

#include <string>
#include <random>
#include <ctime>

class playerType
{
private:
    
    std::string character_name;
    int         coins;
    int         lives;
    
    // Where is the player
    int         level;
    int         x_pos;
    int         y_pos;

    // is the player using special attributes
    bool        special;
    bool        big;
    std::string special_items[5];
    std::string special_applied;

public:
    playerType(std::string cn);
    ~playerType();

    void set_name(std::string str);
    void set_coins(int x);
    void set_lives(int x);
    void set_level(int x);
    void set_xPos(int x);
    void set_yPos(int x);
    void set_special(bool x);
    void set_specialItem(std::string sp);
    void set_big(bool x);

    std::string get_name();
    int get_coins();
    int get_lives();
    int get_level();
    int get_xPos();
    int get_yPos();
    bool get_special();
    bool get_big();
    std::string get_special_Item();
    std::string get_specialItems();
};

playerType::playerType(std::string cn)
{
    character_name = cn;
    coins = 0;
    lives = 3;

    level = 0;
    x_pos = 0;
    y_pos = 0;

    special = false;
    big = false;
    special_items[0] = "Hammer";
    special_items[1] = "Red Mushroom";
    special_items[2] = "Green Mushroom";
    special_items[3] = "Cape";
    special_items[4] = "Star";
    special_applied = "nothing";
}

playerType::~playerType() {
    delete &character_name;
    delete &coins;
    delete &lives;

    delete &level;
    delete &x_pos;
    delete &y_pos;

    delete &special;
    delete &big;
    delete &special_applied;
}
    
//mutators
void playerType::set_name(std::string str) {
        character_name = str;
}
void playerType::set_coins(int x) {
    coins += x;
    while(coins >= 100) {
        set_lives(1);
        coins -= 100;
    }
}
void playerType::set_lives(int x) {
    lives += x;
}
void playerType::set_level(int x) {
    level = x;
}
void playerType::set_xPos(int x) {
    x_pos = x;
}
void playerType::set_yPos(int x) {
    y_pos = x;
}
void playerType::set_special(bool x) {
    special = x;
}
void playerType::set_specialItem(std::string sp) {
    special_applied = sp;
}
void playerType::set_big(bool x) {
    big = x;
}

//accessors
std::string playerType::get_name() {
    return character_name;
}
int playerType::get_coins() {
    return coins;
}
int playerType::get_lives() {
    return lives;
}
int playerType::get_level() {
    return level;
}
int playerType::get_xPos() {
    return x_pos;
}
int playerType::get_yPos() {
    return y_pos;
}
bool playerType::get_special() {
    return special;
}
bool playerType::get_big() {
    return big;
}
std::string playerType::get_special_Item() {
    return special_applied;
}
std::string playerType::get_specialItems() {
    std::srand(std::time(0));
    int x = std::rand() % 5;
    set_specialItem(special_items[x]);
    return get_special_Item();
}

#endif