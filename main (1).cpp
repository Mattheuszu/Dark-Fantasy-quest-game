/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

class Enemy {
    public:
    std::string type;
    int health;
    
    Enemy(std::string t, int h) : type(t), health(h) {}
    
    std::string getType() const {
        return type;
    }
    
    void setType(const std::string &t) {
        type = t;
    }
    
    int getHealth() const {
        return health;
    }
    
    void setHealth(int h) {
        health = h;
    }
    
    virtual void print() const {
        std::cout << "Type of enemy: " << type << ", Health: " << health << std::endl;
    }
};

class Zombie : public Enemy {
    public:
    Zombie(int h) : Enemy("Zombie", h) {}
};

class Wolf : public Enemy {
    public:
    Wolf(int h) : Enemy("Wolf", h) {}
};

class Player {
    private:
    std::string name;
    int health;
    
    public:
    Player(std::string n, int h) : name(n), health(h) {}
    
    std::string getName() const {
        return name;
    }
    
    void setName(const std::string &n) {
        name = n;
    }
    
    int getHealth() {
        return health;
    }
    
    void setHealth(int h){
        health = h;
    }
    
    void takeDamage(int dmg) {
        health -= dmg;
        if (health < 0) health = 0;
    }
    
    void heal(int amount) {
        health += amount;
    }
    
    void print() const {
        std::cout << "Player: " << name << ", Health: " << health << std::endl;
    }
};

class Item {
private:
    std::string name;

public:
    Item(std::string n) : name(n) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string &n) {
        name = n;
    }

    virtual void use() const = 0;
};

class Sword : public Item {
private:
    int damage;

public:
    Sword(std::string n, int d) : Item(n), damage(d) {}

    int getDamage() const {
        return damage;
    }

    void setDamage(int d) {
        damage = d;
    }

    void use() const override {
        std::cout << "Using sword: " << getName() << " with damage: " << damage << std::endl;
    }
};

class Bottle : public Item {
private:
    int healAmount;

public:
    Bottle(std::string n, int h) : Item(n), healAmount(h) {}

    int getHealAmount() const {
        return healAmount;
    }

    void setHealAmount(int h) {
        healAmount = h;
    }

    void use() const override {
        std::cout << "Using bottle: " << getName() << " with heal amount: " << healAmount << std::endl;
    }
};

class Game {
    private:
    Player player;
    Sword sword;
    Bottle bottle;
    
    void TripOne () {
        Zombie z(100);
        z.print();
        
         std::cout << "You encounter a Zombie! Prepare to fight!" << std::endl;
        while (z.getHealth() > 0 && player.getHealth() > 0) {
            std::cout << "Attacking the Zombie with your sword..." << std::endl;
            z.setHealth(z.getHealth() - sword.getDamage());
            if (z.getHealth() > 0) {
                std::cout << "The Zombie attacks you back!" << std::endl;
                player.takeDamage(20);
                player.print();
            }
        }
        if (player.getHealth() > 0) {
            std::cout << "You defeated the Zombie!" << std::endl;
        } else {
            std::cout << "You were defeated by the Zombie..." << std::endl;
        }
    }
    
    void TripTwo() {
        Wolf w(75);
        w.print();
        
         std::cout << "You encounter a Wolf! Prepare to fight!" << std::endl;
        while (w.getHealth() > 0 && player.getHealth() > 0) {
            std::cout << "Attacking the Wolf with your sword..." << std::endl;
            w.setHealth(w.getHealth() - sword.getDamage());
            if (w.getHealth() > 0) {
                std::cout << "The Wolf attacks you back!" << std::endl;
                player.takeDamage(15);
                player.print();
    }
        }
    }
    
    void TripThree() {
        std::cout << "You found the safety trip to home and some resourses..." << std::endl;
        bottle.use();
        player.heal(bottle.getHealAmount());
        player.print();
    }
    
    public: 
    Game(Player p, Sword s, Bottle b) : player(p), sword(s), bottle(b) {}
    
    void start() {
        std::cout << "Welcome to the game!" << std::endl;
        player.print();
        std::cout << "Choose path 1,2 or 3" << std::endl;
        int choice;
        std::cin >> choice;
        
        switch(choice) {
            case 1:
            TripOne();
            break;
            
            case 2:
            TripTwo();
            break;
            
            case 3:
            TripThree();
            break; 
            
            default:
            std::cout << "Invalid choice" << std::endl;
        }
        if(player.getHealth() > 0){
            std::cout << "You survived this adventure. Game over!" << std::endl;
        } else {
            std::cout << "You died. Game over:(" << std::endl;
        }
    }
};
int main()
{
    Player p1("Knight", 175);
    Sword s1("Terra sword", 45);
    Bottle b1("Dark potion", 15);
    
    Game game(p1,s1,b1);
    game.start();
  
    

    return 0;
}
