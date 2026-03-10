#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <thread>
#include <vector>

/* TO DO NEXT:
    Hunger system
    Help expansion
*/


static std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return s;
}

class Item {
private:
    std::string name;
    float weight;

public:
    Item(std::string n, float w) {
        name = n;
        weight = w;
    }

    std::string getName() const {
        return name;
    }

    float getWeight() const {
        return weight;
    }
};

void Begin();

class Scene {
public:
    int name;
    std::string location;
    float bubbles;

    Scene() : name(0), location("Place"), bubbles(1.0f) {}

    Scene(int n, std::string l, int b) {
        name = n;
        location = l;
        bubbles = b;
    }
};

class Scenedatabase {
private:
    std::map<int, Scene> database;
    int turnIs;

public:
    void initializePresets() {
        std::random_device rd;
        std::mt19937 gen(rd()); //rand generator

        std::uniform_real_distribution<float> dist(0, 4); //rand distributor

        database[0] = Scene(0, "the docks", 0.0f);
        database[1] = Scene(1, "shallow sea", 1.0f);
        database[2] = Scene(2, "open sea", 2.0f);
        //Attempt to use for loops to initialize up to scene 100
        //Variable numscene, fully contained in scenedatabase public

        for (int ii = 3; ii < 100; ii++) {
            database[ii] = Scene(3, "deep sea", dist(gen));
        }

        /*database[3] = Scene(3, "deep sea", dist(gen));
        database[4] = Scene(3, "deep sea", dist(gen));
        database[5] = Scene(3, "deep sea", dist(gen));
        database[6] = Scene(3, "deep sea", dist(gen));
        database[7] = Scene(3, "deep sea", dist(gen));
        database[8] = Scene(3, "deep sea", dist(gen));
        database[9] = Scene(3, "deep sea", dist(gen));
        database[10] = Scene(3, "deep sea", dist(gen));*/

    }

    Scene getDescription(int associatedNumber) {
        if (database.count(associatedNumber)) {
            return database[associatedNumber];
        }
        else {
            std::cout << "Error: Scene ID " << associatedNumber << " not found." << std::endl;
            return Scene(0, "[No scene]", 0.0f);
        }
    }

    void setTurn(int t) {
        turnIs = t;
    }

    void updateBubbles(int id, float newAmount) {
        if (database.count(id)) {
            database[id].bubbles = newAmount;
        }
        else {
            std::cout << "Scene " << id << " not found." << std::endl;
        }
    }
};

class Fish {
public:
    std::string name;
    int weight;
    float chance;

    Fish() : name("Fshhat"), weight(1), chance(0.10f) {}

    Fish(std::string n, int w, float c) {
        name = n;
        weight = w;
        chance = c; //Clean up? Not needed I think.
    }
};

class Fishdatabase {
private:
    std::map<int, Fish> database;

public:
    void initializePresets() {
        std::random_device br;
        std::mt19937 gen(br()); //rand generator

        //rand distributors
        std::uniform_real_distribution<float> light(1, 2);
        std::uniform_real_distribution<float> medium(2, 4);
        std::uniform_real_distribution<float> heavy(3, 5);
        std::uniform_real_distribution<float> junk(4, 8);
        std::uniform_real_distribution<float> unique(0, 10);

        database[0] = Fish("Fish 1", 5, 0.1f);
        database[1] = Fish("Fish 2", 4, 0.2f);
        database[2] = Fish("Fish 3", 3, 0.25f);
        database[3] = Fish("Fish 4", 2, 0.3f);
        database[4] = Fish("Fish 5", 1, 0.3f); 
    }
    
    Fish getfish() {
        Scenedatabase db;
        db.initializePresets();

        std::random_device rd;
        std::mt19937 gen(rd()); //rand generator

        std::uniform_real_distribution<float> dist(0, 1.00); //rand distributor
        
        float fisch = dist(gen);
        
        if (fisch < .50) {
            std::cout << "Common catch!\n";
            return database[0];
        }
        else if (fisch < .70) {
            std::cout << "Uncommon catch!\n";
            return database[1];
        }
        else if (fisch < .85) {
            std::cout << "Rare catch!\n";
            return database[2];
        }
        else if (fisch < .95) {
            std::cout << "Unique catch!\n";
            return database[3];
        }
        else if (fisch <= 1.00) {
            std::cout << "Legendary catch!\n";
            return database[4];
        }
        else {
            std::cout << "Error: Fish name " << fisch << " not found." << std::endl;
            return Fish("Non-named fish", 6, 0.0f);
        }
        
    }
};

int main();

void death() {
    int score = 1;
    std::vector<std::string> attributes;

    std::cout << "It appears you have perished.\n";
    std::cout << "Your total score was " << score;
    if (score <= 10) {
        std::cout << ", marking you as an fluke of a zoteling\n";
    }
    else if (score <= 20) {
        std::cout << ", marking you as a ordinary zoteling\n";
        attributes.push_back("Terrifying");
        attributes.push_back("Beautiful");
        attributes.push_back("Powerful");
    }
    else if (score <= 30) {
        std::cout << ", marking you as an winged zoteling\n";
        attributes.push_back("Terrifying");
        attributes.push_back("Beautiful");
        attributes.push_back("Powerful");
        attributes.push_back("Gorgeous");
        attributes.push_back("Passionate");
    }
    else if (score <= 40) {
        std::cout << ", marking you as a hopping zoteling\n";
        attributes.push_back("Terrifying");
        attributes.push_back("Beautiful");
        attributes.push_back("Powerful");
        attributes.push_back("Gorgeous");
        attributes.push_back("Passionate");
                                                                                                            
    }
    else if (score <= 50) {
        std::cout << ", marking you as an lanky zoteling\n";
    }
    else if (score <= 60) {
        std::cout << ", marking you as a turret zoteling\n";
    }
    else if (score <= 70) {
        std::cout << ", marking you as a Head of Zote\n";
    }
    else if (score <= 90) {
        std::cout << ", marking you as an Zoteling the Zote\n";
    }
    else {
        std::cout << ", marking you as a Zote of true form\n";
    }
    //NEED TO FIX
    std::cout << "\nWould you like to play again (y / anything else to quit)\n\n";
    std::cout << "> ";
    std::string res;
    std::getline(std::cin, res);
    res = toLower(res);

    std::string restart = "y";

    if (res == restart) {
        std::cout << "\nRestarted" << std::endl;
        system("cls");
        main();
    }
    else {
        exit(EXIT_SUCCESS);
    }

}


void Begin() {
    std::cout << "\nThe program has begun\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //system("cls");
    std::cout << "'You are Zote.\nThe hero of this story\n";
    std::cout << "You have a boat\nNow you search for glory'\n\n"; //own
    std::cout << "The saga of ZOTE,\n  Written by Zote";
    std::this_thread::sleep_for(std::chrono::seconds(1)); //3

    std::cout << "\n\nYou take sail and can use the following commands:\n\n";
    std::cout << "-Sail\n"; //Mostly complete, add npc to class, hunger triggered here?
    std::cout << "-Eat [food]\n"; //Not done, hunger in progress
    std::cout << "-Fish (when bubbles)\n"; //Begun
    std::cout << "-Talk (npc)\n"; //Not done
    std::cout << "-Trade (npc)\n"; //Not done
    std::cout << "-Fight (enemy)\n"; //Not done
    std::cout << "-Inventory\n"; //Mostly complete?
    std::cout << "-Look\n"; //Complete!
    std::cout << "-Drop [item]\n"; //Not done
    std::cout << "-Take [item]\n"; //Item storage in place, need to make it so items can be picked up
    std::cout << "-Turns\n"; //Complete?
    std::cout << "-Help\n"; //Complete!
    std::cout << "-Restart\n"; //Complete!
    std::cout << "-Exit (quit)\n"; //Complete!
    //Dev
    std::cout << "-Die\n"; //Death complete

    std::cin.ignore(); //clear input to prevent double prompt

    Scenedatabase db;
    db.initializePresets();

    Fishdatabase dbb;
    dbb.initializePresets();

    /* Define outside so no reset
    actions lowercased, then compared against the full string and the shortened string.
    stringf = string full (full word)
    stringh = string half (two or three letters)
    strings = string shortened (letter) */

    //general management
    int turns = 0;
    std::string turnsf = "turns";
    std::string turnsh = "time";
    
    bool isDay = true;

    std::string sailf = "sail";
    std::string sailh = "s";
    std::string lookf = "look";
    std::string lookh = "l";

    std::string fishf = "fish";
    std::string fishs = "f";

    std::string eatf = "eat";
    std::string eats = "e";
    float belly = 5; //how full a person is, calculated per turn less hunger
    float hunger = 0.0; //rate at which belly decreases per turn
    
    std::string help = "help";

    std::string yesf = "yes";
    std::string yess = "y";

    std::string restart = "restart";

    std::string exit1 = "exit";
    std::string exit2 = "quit"; 
    std::string exit3 = "kill";

    //inventory management
    std::vector<Item> inventory;
    std::string invf = "inventory";
    std::string invh = "inv";
    std::string invs = "i";
    float currentTotalWeight = 0.0f;
    float maxTotalWeight = 10.0f;

    inventory.push_back(Item("Test Item 1", 2.1f));
    inventory.push_back(Item("Test Item 2", 5.7f));

    //take management
    std::string takef = "take";
    std::string takes = "t";

    //Dev commands
    std::string devf = "devloper";
    std::string devh = "access";
    std::string devs = "dev";
    std::string deathf = "death";
    std::string deaths = "die";

    while (true) {
        std::string action;
        std::string res; //Restart verification
        
        //recieve action
        std::cout << "\n> ";
        std::getline(std::cin, action);
        action = toLower(action);

        //return check
        if (action.empty()) {
            continue;
        }

        //Developer access
        if (action == devf ||
            action == devh ||
            action == devs) {
            //Must input password, all else kicks to main gameplay loop. No prompt.
            std::string pass;
            std::string match = "cmbId";
            std::getline(std::cin, pass);

            if (pass == match) {
                //enter dev mode and prompt
                std::cout << "\x1b[1A";   
                std::cout << "\x1b[2K";   
                std::cout << "\r";        
                std::cout.flush();
                std::cout << "Dev mode entered\n";
                std::cout << "\n> ";
            }
            else {
                continue;
            }
        }

        //gameplay checks
        if (action == invf ||
            action == invh ||
            action == invs)
        {
            currentTotalWeight = 0;

            std::cout << "You check in the hold and find:\n";
            for (const Item& item : inventory) {
                std::cout << "- " << item.getName() << std::endl;

                currentTotalWeight += item.getWeight();
            }
            std::cout << "\nTotal current weight: " << currentTotalWeight << "/" << maxTotalWeight << std::endl;
        }

        else if (action == lookf ||
                 action == lookh) {
            std::cout << "You look at your surroundings:\n";
            int roomdef = turns;
            if (isDay) {
                std::cout << " (It is day)\n";
            }
            else if (!isDay) {
                std::cout << " (It is night)\n";
            }

            Scene getDef = db.getDescription(roomdef);
            std::cout << " You are in [" << getDef.location << "]" << std::endl;
            std::cout << " There are " << (int)getDef.bubbles << " bubbly areas" << std::endl;
        }

        else if (action == sailf ||
                 action == sailh) {
            turns += 1;
            if ((turns % 5) == 0) {
                if (isDay) {
                    std::cout << "The sun slides behind the horizon. It is now night.\n";
                    isDay = 0;
                }
                else if (!isDay) {
                    std::cout << "The dawn breaks over the smooth sea. It is now day.\n";
                    isDay = 1;
                }
            }

            belly -= hunger;
            if (belly == 0) {
                std::cout << "Your stomach growls immensely and you feel weak\n";
                std::cout << "You fall to the ground and your vision fades to black.\n\n\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));
                death();
            }

            int roomdef = turns;

            Scene getDef = db.getDescription(roomdef);
            std::cout << " You are in " << getDef.location << std::endl;
            std::cout << " There are " << (int)getDef.bubbles << " areas with bubbles" << std::endl;
        }

        else if (action == fishf ||
                 action == fishs) {
            int roomdef = turns;

            Scene getDef = db.getDescription(roomdef);


            if ((int)(getDef).bubbles > 0) {
                Fish Fissh = dbb.getfish();
                //if (Fissh.weight + inventory.max_size)
                inventory.push_back(Item(Fissh.name, Fissh.weight));
                std::cout << "You fished up " << Fissh.name << std::endl;
                
                db.updateBubbles(turns, (getDef.bubbles - 1));
            }

            else {
                std::cout << "You cannot fish right now; there are no bubbles here.\n";
            }
        }

        else if (action == takef ||
                 action == takes) {
            std::cout << "taken" << std::endl;
        }

        else if (action == turnsf ||
                 action == turnsh) {
            if (isDay) {
                std::cout << " (It is day)\n";
            }
            else if (!isDay) {
                std::cout << " (It is night)\n";
            }
            std::cout << turns << " turns have passed.\n";
        }

        else if (action == help) {
            std::cout << "List of commands:\n";
            std::cout << "-Sail\n";
            std::cout << "-Eat [food]\n";
            std::cout << "-Fish (when bubbles)\n";
            std::cout << "-Talk (npc)\n";
            std::cout << "-Trade (npc)\n";
            std::cout << "-Fight (enemy)\n";
            std::cout << "-Inventory\n";
            std::cout << "-Look\n";
            std::cout << "-Drop [item]\n";
            std::cout << "-Take [item]\n";
            std::cout << "-Turns\n";
            std::cout << "-Help\n";
            std::cout << "-Restart\n";
            std::cout << "-Exit (quit)\n";
        }

        else if (action == deathf ||
                 action == deaths) {
            death();
            /*if (split == 3) {
                break;
            }*/
        }

        else if (action == restart) {
            std::cout << "\n> Are you sure you want to restart? (y/n) ";
            std::getline(std::cin, res);
            res = toLower(res);

            std::string yes = "y";
            std::string no = "n";

            if (res == yes) {
                std::cout << "\nRestarted" << std::endl;
                main();
                system("cls");
                break;
            }

            else if (res == no) {
                std::cout << "Well then, go and beat the game!\n";
                continue;
            }
        }

        else if (action == exit1 ||
                 action == exit2 ||
                 action == exit3) {
            std::cout << "\nThank you for playing\n";
            break;
        }

        else
        {
            std::cout << "Invalid command\n";
        }

    }
    
    std::this_thread::sleep_for(std::chrono::seconds(1));

}

int main()
{
    std::string input;

    std::cout << "Welcome to Zoteboat: The Text Adventure 1.0\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "A fanmade text adventure by Team Lemon\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    while (true) {
        std::cout << "Enter 'begin' to start your grand adventure" << std::endl << "> ";
        std::cin >> input;
        input = toLower(input);
        std::string beginf = "begin";
        std::string beginh = "bg";
        std::string begins = "b";
        std::string kill1 = "kill";
        std::string kill2 = "exit";
        std::string kill3 = "quit";

        if (input == beginf ||
            input == beginh ||
            input == begins )
        {
            Begin();
            break;
        }
        else if (input == kill1 ||
                 input == kill2 ||
                 input == kill3) {
            std::cout << "\nThank you for playing\n";
            break;
        }
        else
        {
            std::cout << "Invalid command\n\n";
            std::cout << "> ";
        }
    }

    std::cout << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(255));
    std::cout << "Each repeat = 1 attempt\n";

    return 0;

}
