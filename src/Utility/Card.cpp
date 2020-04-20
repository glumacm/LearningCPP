#include "Card.hpp"
using namespace  std;

/**
	 * Najboljsa lekcija kar se tice pointerjev do sedaj je ta... da takoj ko koristimo nek objekt,
	 * ki ga vracamo v funkciji, ki je kasneje odvisen od nekega pointerja. Je dobro to stvar preoblikovati
	 * v class. Pri setTexture smo videli da smo potrebovali texturo v ReactangleShape. A sele pri draw,
	 * se textura uporablja. Ampak ko smo naredili to samo preko funkcije, se je textura izgubila,
	 * sla je iz spomina. Zato je bilo potrebno narediti razred, ki je lahko hranil tako texturo kot
	 * RectangleShape!!!!
	 *
	 * Sedaj pa gremo v next step. Ko bomo naredili DECK. Torej bomo postavili deck na neko poljubno
	 * tocko!!!!
	 */

Card::Card(string relative_path, sf::Vector2f cardsize, sf::Vector2f coordinates, string cardtag)
{
	card_shape = sf::RectangleShape(cardsize);
	card_shape.setPosition(coordinates);
	/**
	 * KAKO SEM PO-OWNAL TO ZADEVO!!!!
	 * ZDEJ VIDIM KAKO IN KJE UPORABITI POINTER.... TUKAJ BI SPREMENLJIVKA BREZ POINTERJA IZGUBILA
	 * VREDNOST PO IZHODU IZ KONSTRUKTORJA, AMPAK KER SEM NASTAVIL POINTER JE TO OBSTALO!!!!
	*/
	card_texture = new sf::Texture();
	card_texture->loadFromFile(relative_path);
	//card_color = sf::Color::White;
	card_shape.setTexture(card_texture);
	generateCardValueFromStrig(cardtag);
}

Card::~Card()
{
}

/**
 * Primitivna resitev ampak zaenkrat bo ok.....
 *
 */
void Card::generateCardValueFromStrig(string cardtag){
	/**
	 * PREDPOSTAVKA: Vsako ime karte je sestavljeno iz __stevilo____crka__ (npr. 10C, 2S ,...)
	 * Zato bom vzel stevilo do zadnjega stringa, ker tam bo oznaka karte.
	 */
	if(cardtag == ""){
		return;
	}

	string cardvaluestring = cardtag.substr(0, cardtag.size()-1);
	vector<string> figures {"Q", "J", "K", "A"};
	try
	{
		card_value = stoi(cardvaluestring);
	}catch(std::exception e)
	{
		if(find(figures.begin(),figures.end(), cardvaluestring)!= figures.end()){
			if(cardvaluestring == "A"){
				card_value =11;
				is_ace = true;
			}else{
				card_value = 10;
			}
			return;
		}
		cout << "There was an error when casting card value for card tag: " + cardtag << endl;
	}

}


