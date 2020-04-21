#include "Carddeck.hpp"
using namespace std;
class Player
{
	private:
		string player_name;
		float player_cash_amount; //celoten znesek ki ga ima
		Carddeck player_deck; //karte ki jih ima uporabnik
		sf::Vector2f player_position;
		float lowest_limit;
	public:
		Player();
		Player(string playername, float cashamount, sf::Vector2f playerpos);
		Carddeck getPlayerDeck(){return player_deck;}
		void setPlayerCashAmount(float cash_amount){ player_cash_amount = cash_amount;}
		void setPlayerName(string playername) { player_name = playername;}
		void setPlayerPosition(sf::Vector2f playerpos) { player_position = playerpos;}
		float getPlayerCashAmount(){return player_cash_amount;}
		bool withdrawAmount(float someamount);
		bool drawCard(Carddeck fulldeck);
		void addAmount(float someamount);
		sf::Vector2f getPlayerPosition(){return player_position;}


};