/*
http://www.cplusplus.com/forum/articles/12974/
_________________________________________________________________________________
Graduation:
Requires:
variables, data types, and numerical operators
basic input/output
logic (if statements, switch statements)
loops (for, while, do-while)
arrays
pseudo random number generation
strings & string functions
functions
structures/classes
enumerated data
file input/output
pointers
sorting
linked lists
advanced classes

Write a program that creates a linked list of bunny objects.
Each bunny object must have
Sex: Male, Female (random at creation 50/50)
color: white, brown, black, spotted
age : 0-10 (years old)
Name : randomly chosen at creation from a list of bunny names.
radioactive_mutant_vampire_bunny: true/false (decided at time of bunny creation 2% chance of true)

At program initialization 5 bunnies must be created and given random colors.
Each turn afterwards the bunnies age 1 year.
So long as there is at least one male age 2 or older, for each female bunny in the list age 2 or older;
a new bunny is created each turn. (i.e. if there was 1 adult male and 3 adult female bunnies, three new bunnies would be born each turn)
New bunnies born should be the same color as their mother.
If a bunny becomes older than 10 years old, it dies.
If a radioactive mutant vampire bunny is born then each turn it will change exactly one non radioactive bunny into a radioactive vampire bunny.
(if there are two radioactive mutant vampire bunnies two bunnies will be changed each turn and so on...)
Radioactive vampire bunnies are excluded from regular breeding and do not count as adult bunnies.
Radioactive vampire bunnies do not die until they reach age 50.
The program should print a list of all the bunnies in the colony each turn along w/ all the bunnies details, sorted by age.
The program should also output each turns events such as
"Bunny Thumper was born!
Bunny Fufu was born!
Radioactive Mutant Vampire Bunny Darth Maul was born!
Bunny Julius Caesar died!
The program should write all screen output to a file.
When all the bunnies have died the program terminates.
If the bunny population exceeds 1000 a food shortage must occur killing exactly half of the bunnies (randomly chosen)

★ Modify the program to run in real time, with each turn lasting 2 seconds, and a one second pause between each announement.

★★ Allow the user to hit the 'k' key to initiate a mass rabit cull! which causes half of all the rabits to be killed (randomly chosen).

★★★★ Modify the program to place the rabits in an 80x80 grid. Have the rabits move one space each turn randomly.
Mark juvenile males with m, adult males w/ M,
juvenile females w/ f, adult femails w/ F
radioactive mutant vampire bunnies with X

Modify the program so that radioactive mutant vampire bunnies only convert bunnies that end a turn on an adjacent square.
Modify the program so that new babies are born in an empty random adjacent square next to the mother bunny. (if no empty square exits then the baby bunny isn't born)

★★★★★ Modify the program so that it saves each turn to a file and can play back at accelearted speed all subsequent turns.
*/

#include <iostream>
#include <string>
#include <random>

const std::string nameList [] = {"Mario", "Luigi", "Donkey Kong", "Captain Falcon", "Fox", "Falco", "Pikachu", "Ness", "Kirby", "Jigglypuff", "Ganondorf", "Marth", "Roy", "Zelda", "Link", "Young Link", "Sheik", "Yoshi", "Doctor Mario", "Pichu", "Samus", "Mewtwo", "Popo", "Nana", "Mr. Game & Watch", "Peach", "Bowser"};

enum sex_enum {
  male, female
};

enum color_enum {
  white, brown, black, spotted
};

class Bunny {
  private:
  sex_enum sex;
  color_enum color;
  int age;
  std::string name;
  bool radioactive_mutant_vampire_bunny;
  
  
  public:
  Bunny (std::mt19937 eng, std::uniform_int_distribution<> distr_sex, std::uniform_int_distribution<> distr_color, std::uniform_int_distribution<> distr_name, std::uniform_int_distribution<> distr_rmvb) {
    sex = static_cast<sex_enum>(distr_sex(eng));
    color = static_cast<color_enum>(distr_color(eng));
    age = 0;
    name = nameList[distr_name(eng)];
    int rmvb_random_num = distr_rmvb(eng);
    if (rmvb_random_num >= 0 && rmvb_random_num < 2) {
      radioactive_mutant_vampire_bunny = true;
    }
    else {
      radioactive_mutant_vampire_bunny = false;
    }
      
  }
  ~Bunny () {
    
  }
  
  void printBunny () {
    std::string str_sex;
    std::string str_color;
    switch (sex) {
      case male:
        str_sex = "male";
        break;
      case female:
        str_sex = "female";
        break;
      default:
        str_sex = "enum_switch_had_a_problem";
    }
    switch (color) {
      case white:
        str_color = "white";
        break;
      case brown:
        str_color = "brown";
        break;
      case black:
        str_color = "black";
        break;
      case spotted:
        str_color = "spotted";
        break;
      default:
        str_color = "enum_switch_had_a_problem";
    }
    
    std::cout << str_sex << " " << str_color << " " << age << " " << name << " " << (radioactive_mutant_vampire_bunny ? "true" : "false") << std::endl;
  }
};

int gameInit();
int gameLoop();
int gameQuit();

int main ()
{
  std::random_device rd; // obtain a random number from hardware
  std::mt19937 eng(rd()); // seed the generator
  std::uniform_int_distribution<> distr_sex(0, 1); // define the range
  std::uniform_int_distribution<> distr_color(0, 3);
  std::uniform_int_distribution<> distr_name(0, sizeof(nameList)/sizeof(nameList[0]) - 1);
  std::uniform_int_distribution<> distr_rmvb(0, 99);

  Bunny lab_bunny(eng, distr_sex, distr_color, distr_name, distr_rmvb);
  
  lab_bunny.printBunny();
  
  return 0;
}