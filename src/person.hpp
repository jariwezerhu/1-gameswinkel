// Header file for Person class

#include "game.hpp"
#include <string>
#include <list>
using namespace std;

class Person {
public:
    Person(float budget, string name);
    bool buy(Game game);
    bool sell(Game game, Person& buyer);
    float getBudget();
    void setBudget(float budget);
    list<Game> getGames();
    void setGames(list<Game> games);
    void addGame(Game game);
    void removeGame(Game game);
    string getName();
    void setName(string name);

private:
    float budget;
    string name;
};