#include "Carddeck.hpp"


namespace fs = std::experimental::filesystem;
Carddeck::Carddeck(/* args */sf::Vector2f starting_position, string relative_path_to_images, int deck_size)
{
	deck_position = starting_position;
	size_of_deck = deck_size;
	path_to_deck_textures = relative_path_to_images;
}

Carddeck::Carddeck()
{
	path_to_deck_textures = "";
	deck_position = {0,0};
}

int Carddeck::randomizeShuffle(int i){
	return std::rand() % i;
}

bool Carddeck::createFullDeck(){
	if(path_to_deck_textures == "" || (&path_to_deck_textures==NULL)){
		return false;
	}
	int current_deck = 0;
	//std::random_shuffle(textures_list.begin(), textures_list.end());
	std::random_device r;
	auto rng = std::default_random_engine{r()};
	std::shuffle(std::begin(textures_list),std::end(textures_list),rng);
	sf::Vector2f current_coordinates = deck_position;
	for(string card_texture : textures_list){
		//std::cout << "Full size: " << size_of_deck << " current size: " << current_deck << std::endl;
		if(current_deck == size_of_deck){
			break;
		}
		//pathtotexture
		//size
		//coordinates
		string full_path_to_card = path_to_deck_textures+"/"+card_texture+texture_extension;
		if(fs::is_regular_file(full_path_to_card)){
			//std::cout << "Texture works: " + full_path_to_card << std::endl;
			Card the_card(full_path_to_card,card_size,current_coordinates,card_texture);//card_texture == vrednost karte.
			deck_score+= the_card.getCardValue();
			my_cards.push_back(the_card);
			addStepOnCoordinates(&current_coordinates,&card_size,cards_offset);
		}
		current_deck++;

	}

	//std::random_shuffle(my_cards.begin(), my_cards.end());
	return true;

}
void Carddeck::addCardValueToDeck(Card thecard){
	if(thecard.isAce() && (deck_score + thecard.getCardValue() > black_jack_perfection)){
		deck_score += thecard.getAceAlternativeValue();
	}else{
		deck_score+=thecard.getCardValue();
	}
}
int Carddeck::calculateDeckValue(){
	int deck_value = 0;
	for(Card card : my_cards){
		deck_value += card.getCardValue();
	}
	return deck_value;
}
void Carddeck::addStepOnCoordinates(sf::Vector2f* pos, sf::Vector2f* cardsize, float offset){
	pos->x = pos->x  + cardsize->x+ offset;
}

void Carddeck::addCard(Card new_card){
	my_cards.push_back(new_card);
	deck_score+=new_card.getCardValue();
	size_of_deck+=1;
}

//Card Carddeck::drawCard(){
Card Carddeck::drawCard(){
	/**
	 *
	 * lahko vrnemo le referenco do karte... ne moremo kar vrniti karto in jo izbrisati iz my_cards ker potem
	 * izgubimo podatek ki ga referencira izbrisani podatek....
	 */
	//return my_cards.back();
	if(my_cards.size() < 1){
		return Card(true);
	}
	Card last_card = my_cards.back();
	my_cards.pop_back();
	deck_score-=last_card.getCardValue();
	size_of_deck-=1;
	return last_card;
}

void Carddeck::setCardSize(sf::Vector2f new_card_size){
	card_size = new_card_size;
}


