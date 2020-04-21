#include "PlayerUiContainer.hpp"

PlayerUiContainer::PlayerUiContainer()
{

}

PlayerUiContainer::PlayerUiContainer(Player theplayer)
{
	the_player = theplayer;
	//Button(sf::Vector2f buttonsize, sf::Vector2f buttonpos, sf::Color buttoncolor, string text);
	sf::Vector2f buttonposition = the_player.getPlayerPosition();
	buttonposition.x +=70;
	draw_card = Button(default_button_size,buttonposition,sf::Color::Blue,"Draw card");
	//string absolutepath = fs::absolute("").string()+"/content/PNG/green_back.png";
	//playerposition.x -= 20;
	//draw_card = Card(absolutepath,default_card_size,playerposition,"");
	//draw_card(fs::absolute("").string()+"/content/PNG/green_back.png",);
	setPlayerTextUi();


}

void PlayerUiContainer::checkAndUpdate(sf::Event* event){
	if(event->type == sf::Event::MouseButtonReleased){

		if(event->mouseButton.button == sf::Mouse::Left){
			//kliknili smo gumb
			//cout << "AT least works???  " << event->mouseButton.x << "   " << event->mouseButton.y << endl;
			bool drawncard = drawClicked(event->mouseButton.x, event->mouseButton.y);
			if(drawncard){
				cout << "Button CLICKED : " + draw_card.getButtonName() << endl;
				addAmountToPlayer(500);
			}
		}
	}
}
bool PlayerUiContainer::drawClicked(int clickX, int clickY){
	sf::Vector2f drawcardpos = draw_card.getButtonPosition();
	sf::Vector2f drawcardsize = draw_card.getButtonSize();
	if(
		((clickX >= drawcardpos.x) && (clickX <= (drawcardpos.x + drawcardsize.x))) &&
		((clickY >= drawcardpos.y) && (clickY <=(drawcardpos.y + drawcardsize.y)))
		)
	{
		return true;
	}
	return false;
}

void PlayerUiContainer::addAmountToPlayer(float amount)
{
	the_player.addAmount(amount);
	player_cash_amount_text.setText(to_string(the_player.getPlayerCashAmount()));
}

void PlayerUiContainer::setPlayerTextUi(){

	sf::Vector2f playerglobalposition = the_player.getPlayerPosition();
	sf::Vector2f amountpos = playerglobalposition;
	amountpos.y += 150;
	amountpos.x+=150;
	//nastavimo sf::Text za ime
	Text playertextname;
	//playertextname.setPosition(amountpos);
	playertextname.setText(the_player.getPlayerName());

	player_name_text = playertextname;

	//nastavimo sf::Text za cash for gold --> there lies south park

	sf::Vector2f amountpos1 = playerglobalposition;
	Text playercashamount;
	amountpos1.y+=60;
	playercashamount.setPosition(amountpos1);
	playercashamount.setText(to_string(the_player.getPlayerCashAmount()));
	player_cash_amount_text = playercashamount;


}

void PlayerUiContainer::draw()
{
	/**
	 * izrisimo karte igralca
	 * --------------------------------
	 */
	Carddeck player_deck = the_player.getPlayerDeck();
	vector<Card> player_cards = player_deck.getDeck();
	if(player_cards.size() >0){
		//samo ce imamo karte jih risemo!!!
		for(Card player_card : player_cards)
		{
			window_reference->draw(player_card.getCard());
		}
	}

	/**
	 * izrisimo ime igralca
	 * --------------------------------
	 */
	window_reference->draw(player_name_text.getTxt());//ta ima default vrednost
	window_reference->draw(player_cash_amount_text.getTxt());

	/**
	 * izrisimo karto za draw
	 * --------------------------------
	 */
	draw_card.draw(window_reference);
}
