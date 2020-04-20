using namespace std;
class Card
{
private:
	/* data */
	sf::Color card_color;
	int card_value;
	string card_sign;
	sf::Texture* card_texture;
	sf::RectangleShape card_shape;
	string card_texture_path;

public:
	Card(string relative_path,sf::Vector2f cardsize, sf::Vector2f coordinates);
	~Card();
	sf::RectangleShape getCard() {return card_shape;}
	//sf::Texture getTexture() {return card_texture;}
	int getCardValue(){return card_value;}
};