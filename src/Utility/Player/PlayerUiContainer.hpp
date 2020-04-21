#include "../Player.hpp"
#include "../Button.hpp"

class PlayerUiContainer
{
	private:
		Player the_player;
		Text player_name_text;//from contructor
		Text player_cash_amount_text;//from constructor
		void setPlayerTextUi();
		sf::RenderWindow* window_reference;
		sf::Vector2f default_button_size {80,20};
		Button draw_card; //from constructor
		//Card draw_card;
	public:
		PlayerUiContainer();
		PlayerUiContainer(Player the_player);
		void setWindowReference(sf::RenderWindow* wf){window_reference = wf;}
		void checkAndUpdate(sf::Event* event);
		bool drawClicked(int clickX, int clickY);
		void addAmountToPlayer(float amount);
		void draw();
};