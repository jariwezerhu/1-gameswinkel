#include "game.cpp"
#include "person.cpp"
#include <ctime>
#include <iostream>


void logPurchaseAttempt(Person& person, Game& game) {
    // Stayed true to exercise output
    bool purchaseStatus = person.buy(game);
    string purchaseStatusString = purchaseStatus ? "succes" : "failed";
    
    cout <<
    person.getName() <<
    " buys " <<
    game.getTitle() <<
    ": " <<
    purchaseStatusString <<
    endl;
}

void logGameInfo(Game& game) {
    // Stayed true to exercise output
    string title = game.getTitle();
    int releaseDate = game.getReleaseDate();
    float originalPrice = game.getOriginalPrice();
    float currentPrice = game.calculateCurrentPrice();

    cout <<
    title <<
    ", released " <<
    releaseDate <<
    "; original price: " <<
    originalPrice <<
    " now: " <<
    currentPrice <<
    endl;
}

void logPersonInfo(Person& person) {
    // Stayed true to exercise output
    string name = person.getName();
    float budget = person.getBudget();
    list<Game> games = person.getGames();

    cout <<
    name <<
    "'s budget is " <<
    budget <<
    " and owns:" <<
    endl;

    for (Game game : games) {
        logGameInfo(game);
    }
}

void logSellAttempt(Person& seller, Person& buyer, Game& game) {
    // Stayed true to exercise output
    bool sellStatus = seller.sell(game, buyer);
    string sellStatusString = sellStatus ? "succes" : "failed";

    cout <<
    seller.getName() <<
    " sells " <<
    game.getTitle() <<
    " to " <<
    buyer.getName() <<
    ": " <<
    sellStatusString <<
    endl;
}

int main()
{
    std::time_t result = std::time(NULL);
    std::cout << std::asctime(std::localtime(&result));
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int releaseDate1 = tm_local->tm_year + 1899; // 1 year ago
    int releaseDate2 = tm_local->tm_year + 1898; // 2 years ago
    
    Game g1("Just Cause 3", releaseDate1 , 49.98);
    Game g2("Need for Speed: Rivals", releaseDate2 , 45.99);
    Game g3("Need for Speed: Rivals", releaseDate2 , 45.99);
    
    Person p1(200.00, "Eric");
    Person p2(55.00, "Hans");
    Person p3(185.00, "Arno");
    
    // Attempt a number of purchases by p1, p2 and p3
    logPurchaseAttempt(p1, g1);
    logPurchaseAttempt(p1, g2);
    logPurchaseAttempt(p1, g3);
    logPurchaseAttempt(p2, g2);
    logPurchaseAttempt(p2, g1);
    logPurchaseAttempt(p3, g3);
    
    // Log info of p1, p2 and p3
    cout << endl; // Empty lines for readability
    logPersonInfo(p1);
    cout << endl;
    logPersonInfo(p2);
    cout << endl;
    logPersonInfo(p3);
    cout << endl;


    // Attempt a number of sales by p1 and p2
    logSellAttempt(p1, p3, g1);
    logSellAttempt(p2, p3, g2);
    logSellAttempt(p2, p1, g1);
    
    // Log info of p1, p2 and p3
    cout << endl; // Empty lines for readability
    logPersonInfo(p1);
    cout << endl;
    logPersonInfo(p2);
    cout << endl;
    logPersonInfo(p3);
    cout << endl;

    // Wait for user input before exiting
    cout << "Press enter to exit..." << endl;
    cin.get();
    
    return 0;
}