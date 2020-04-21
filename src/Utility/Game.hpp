#include "Player.hpp" //includes Carddeck -> which includes Card
#include "Button.hpp" //includes Text
using namespace std;
class Game
{
	private:
		vector<Player> players;
		Player dealer;
		float house_cash;
		float entrance_fee;
		Carddeck table_full_deck;
	public:
		string game_name;
		Game();
		float getHouseCash(){return house_cash;}
		void setHouseCash(float housecash){house_cash=housecash;}
		bool addPlayer(Player newplayer);

};