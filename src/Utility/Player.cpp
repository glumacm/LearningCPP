#include "Player.hpp"


Player::Player(){
	//ocitno je treba pri "PRAZNEM" kontruktorju dodati '~'.
	player_cash_amount = 0;
	player_name = "Unknown player";
	player_position = {0,0};
}


Player::Player(string playername, float cashamount, sf::Vector2f playerpos){
	//for now we will not let Carddeck to be passed in the constructor. Why ? ...
	//... because cards are always given one by one at game start and not before hand in a bunch.
	player_name = playername;
	player_cash_amount = cashamount;
	player_position = playerpos;
}

/**
 * Poskrbimo, da vemo ali je deck prazen.... Da lahko potem izpisemo na zaslonu , itd....
 */
bool Player::drawCard(Carddeck fulldeck){
	Card drawn_card = fulldeck.drawCard();
	if(!drawn_card.isNullable())
	{
		return false;
	}
	player_deck.addCard(drawn_card);
	return true;
}
