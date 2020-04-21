using namespace std;
class Card
{
private:
	/* data */
	sf::Color card_color;
	int card_value = 0;
	string card_sign;
	sf::Texture* card_texture;
	sf::RectangleShape card_shape;
	string card_texture_path;
	bool is_ace = false;
	int ace_alternative_value = 1;
	bool is_null = false;

public:
	Card(string relative_path,sf::Vector2f cardsize, sf::Vector2f coordinates, string cardtag);
	Card(bool isnull);
	~Card();
	bool isNullable(){return is_null;}
	sf::RectangleShape getCard() {return card_shape;}
	//sf::Texture getTexture() {return card_texture;}
	int getCardValue(){return card_value;}
	bool isAce(){return is_ace;}
	int getAceAlternativeValue(){return ace_alternative_value;}
	void generateCardValueFromStrig(string cardtag);
	string printString(){return "This is card: " + to_string(card_value);}
};