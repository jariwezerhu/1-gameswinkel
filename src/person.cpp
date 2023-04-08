#include "person.hpp"
#include <string>
#include <list>
using namespace std;

Person::Person(float budget, string name) {
    this->budget = budget;
    this->name = name;
}

bool Person::buy(Game game) {
    // check if game is already in owned games
    for (Game g : games) {
        if (g == game) {
            return false;
        }
    }
    // check if budget is sufficient, if so, add game to owned games
    if (game.calculateCurrentPrice() <= budget) {
        budget -= game.calculateCurrentPrice();
        games.push_back(game);
        return true;
    }
    return false;
}

bool Person::sell(Game game, Person& buyer) {
    // check if game is in owned games
    for (Game g : games) {
        if (g == game) {
            if (buyer.buy(game)) { // check if buyer has enough budget, and doesn't already own the game
                removeGame(game); // remove game from owned games. 
                budget += game.calculateCurrentPrice(); // add money to budget
                return true;
            }
            return false;
        }
    }
    return false;
}

float Person::getBudget() {
    return budget;
}

void Person::setBudget(float budget) {
    this->budget = budget;
}

list<Game> Person::getGames() {
    return games;
}

void Person::setGames(list<Game> games) {
    this->games = games;
}

void Person::addGame(Game game) {
    games.push_back(game);
}

void Person::removeGame(Game game) {
    games.remove(game); //uses operator== from Game class
}

string Person::getName() {
    return name;
}

void Person::setName(string name) {
    this->name = name;
}