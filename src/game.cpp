#include "game.hpp"
#include <ctime>
#include <cmath>
#include <string>

Game::Game(string title, int releaseDate, float originalPrice) {
    this->title = title;
    this->releaseDate = releaseDate;
    this->originalPrice = originalPrice;
}

bool Game::operator==(const Game& other) const {
    // check if titles are equal
    return (title == other.title);
}

string Game::getTitle() {
    return title;
}

void Game::setTitle(string title) {
    this->title = title;
}

int Game::getReleaseDate() {
    return releaseDate;
}

void Game::setReleaseDate(int releaseDate) {
    this->releaseDate = releaseDate;
}

float Game::getOriginalPrice() {
    return originalPrice;
}

void Game::setOriginalPrice(float originalPrice) {
    this->originalPrice = originalPrice;
}

float Game::calculateCurrentPrice() {
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int currentYear = tm_local->tm_year + 1900;
    int yearsSinceRelease = currentYear - releaseDate;
    float currentPrice = originalPrice * pow(0.7, yearsSinceRelease); // 30% price drop per year
    float roundedCurrentPrice = ceil(currentPrice * 100) / 100; // round to 2 decimals. ceil cuz capitalism
    return roundedCurrentPrice;
}