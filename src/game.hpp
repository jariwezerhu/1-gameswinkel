// Header file for Game class
#pragma once
#include <string>

using namespace std;

class Game {
public:
    Game(string title, int releaseDate, float originalPrice);
    bool operator==(const Game& other) const; // compare games by title
    string getTitle();
    void setTitle(string title);
    int getReleaseDate();
    void setReleaseDate(int releaseDate);
    float getOriginalPrice();
    void setOriginalPrice(float originalPrice);
    float calculateCurrentPrice();

private:
    string title;
    int releaseDate;
    float originalPrice;
};