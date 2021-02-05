#include <string>

class Game {
  public:
    Game(std::string name, bool online, double sales, std::string console, char rating, int releaseYear);
    std::string getName();
    bool getOnline();
    double getSales();
    std::string getConsole();
    char getRating();
    int getReleaseYear();

  private:
    std::string name;
    std::string console;
    bool online;
    int releaseYear;
    double sales;
    char rating;
};
