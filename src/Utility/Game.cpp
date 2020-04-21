#include <experimental/filesystem>
#include "Game.hpp"

namespace fs = experimental::filesystem;

/**
 * Ena ideja , ki sem jo imel je ta, da bi imel POINTER na naslednjega igralca. S tem bi lahko
 * mannipuliral lazje potezo naslednjega igralca.
 **/
Game::Game()
{
	game_name = "Default game name";
	house_cash =0;
	entrance_fee = 1;

	//deck from which players will receive cards
	table_full_deck = Carddeck(sf::Vector2f{0,0},fs::absolute("/../content/PNG"),52);

}

/**
 * dodamo lahko le igralca ki:
 *  - ima dovolj denarja
 *  - ...
**/
bool Game::addPlayer(Player newplayer)
{
	//preverimo ali ima dovolj denarja
	if(newplayer.getPlayerCashAmount() < entrance_fee)
	{
		std::cout << "Cannot add player with unsufficient amount." << std::endl;
		return false;
	}
	//check if withdrawal was successfull
	bool entrance_fee_withdrawn = newplayer.withdrawAmount(entrance_fee);
	if(entrance_fee_withdrawn)
	{
		players.push_back(newplayer);//add player to the table;
		return true;
	}else
	{
		return false;
	}
}