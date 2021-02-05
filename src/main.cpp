#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>

std::vector<Game*>* getGames(){

  // column numbers for the data we need from each row
  // (excluding the last column)
  int titleColumn = 0;
  int onlineColumn = 4;
  int salesColumn = 10;
  int consoleColumn = 12;
  int ratingColumn = 13;

  // define the file stream, string, and vectors we're going to be using
  std::ifstream gamesFile("data/video_games.csv");
  std::string token;
  std::vector<std::string> *tokens = new std::vector<std::string>();
  std::vector<Game*> *games = new std::vector<Game*>();

  // skip the first line of the data file
  std::getline(gamesFile, token);

  // get each "line" up until a comma character, really
  // we're just getting each cell in the data file at a time
  while(std::getline(gamesFile, token, ',')) {

    // if there's a newline character, that means we reached a new row
    if(token.find("\n") != std::string::npos) {

      // make the new Game object from the data in the current row
      Game *game = new Game(tokens->at(titleColumn),
                            tokens->at(onlineColumn).compare("True") == 0 ? true : false,
                            std::stod(tokens->at(salesColumn)),
                            tokens->at(consoleColumn),
                            tokens->at(ratingColumn).at(0),
                            std::stoi(token.substr(0, token.find("\n")))); // currently, token holds two "cells" from
                                                                           // the data file, since we're splitting things
                                                                           // based on comma characters, not newline characters
                                                                           // so we have to "manually" split token at this stage

      // at the newly created game to the list of games,
      // clear the list of tokens and split the current value
      // of token before we add it to the list
      games->push_back(game);
      token = token.substr(token.find("\n") + 1);
      tokens->clear();
    }

    // add the current token to the list of tokens
    tokens->push_back(token);
  }

  // close stream/return
  gamesFile.close();
  return games;
}

TEST_CASE( "Testing...", "[all]" ) {
    std::vector<Game*> *games = getGames();
    REQUIRE( games->size() == 1114);
    Game* g = games->at(222);
    REQUIRE( g->getName() == "WWE SmackDown vs. Raw 2007" );
    g = games->at(235);
    REQUIRE( g->getName() == "Rockstar Games presents Table Tennis");
    REQUIRE( g->getOnline());
    g = games->at(254);
    REQUIRE( g->getSales() == 0.23 );
    g = games->at(541);
    REQUIRE( g->getConsole() == "PlayStation 3");
    g = games->at(978);
    REQUIRE( g->getRating() == 'M');
    g = games->at(1113);
    REQUIRE( g->getName() == "Chicken Hunter");
    REQUIRE( g->getReleaseYear() == 2008);
    double value = 0;
    for(auto it=games->begin(); it!=games->end(); ++it){
        value += (*it)->getSales();
    }
    REQUIRE( value > 574.3);
    REQUIRE( value < 574.4);
}
