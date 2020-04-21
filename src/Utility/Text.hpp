#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;
class Text
{
	private:
		int text_size;
		sf::Color text_color;
		bool is_bold;
		sf::Vector2f text_position;
		sf::Font* text_font;
		string path_to_font = fs::absolute("").string()+"/content/fonts/arial.ttf";//absolute path
		sf::Text txt;
		string text_content;

		void createFont();
		void setTextProps();
	public:
		Text();
		Text(int textsize,string textcontent, string pathtofont, sf::Color textcolor, bool isbold, sf::Vector2f textposition);
		sf::Vector2f getTextPosition(){return text_position;}
		sf::Color getTextColor(){return text_color;}
		bool setFont(string pathtofont);
		sf::Text getTxt(){return txt;}
		void setText(string newtext){text_content = newtext;setTextProps();};
		void draw(sf::RenderWindow* window){window->draw(txt);}
		void setOrigin(sf::Vector2f origin){txt.setOrigin(origin);}
		void setPosition(sf::Vector2f pos){text_position=pos;setTextProps();}
};