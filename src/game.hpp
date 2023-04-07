// Header file for Game class

#include <string>

using namespace std;

class Game {
public:
    Game(string title, int releaseDate, float originalPrice);
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