#include "Game.hpp"

Game::Game(std::string name, bool online, double sales, std::string console, char rating, int releaseYear) {
  this->name = name;
  this->online = online;
  this->sales = sales;
  this->console = console;
  this->rating = rating;
  this->releaseYear = releaseYear;
}
std::string Game::getName() {
  return name;
}
bool Game::getOnline() {
 return online;
}
double Game::getSales() {
  return sales;
}
std::string Game::getConsole() {
  return console;
}
char Game::getRating() {
  return rating;
}
int Game::getReleaseYear() {
  return releaseYear;
}
