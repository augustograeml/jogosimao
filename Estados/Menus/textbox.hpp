//codigo reaproveitado de https://www.youtube.com/watch?v=T31MoLJws4U&t=1788s

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#define DELETE_TECLA 8
#define ENTER_TECLA 13
#define ESC_TECLA 27

namespace Estados
{
    namespace Menus
    {
        class Textbox
        {
        private:
            bool isSelected = false;
            sf::Text textbox; 
            std::ostringstream text;
            bool hasLimit = false;
            int limit;
            
            void deleteLastChar() {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		text.str("");
		text << newT;
		textbox.setString(text.str() + "_");
	}

	// Get user input:
	    void inputLogic(int charTyped) {
		// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
		if (charTyped != DELETE_TECLA && charTyped != ENTER_TECLA && charTyped != ESC_TECLA) {
			text << static_cast<char>(charTyped);
		}
		// If the key is delete, then delete the char:
		else if (charTyped == DELETE_TECLA) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
		}
		// Set the textbox text:
		textbox.setString(text.str() + "_");
	}

            
        public:
            Textbox(){}
            Textbox(int size, sf::Color color, bool sel);
            ~Textbox() {}
            void setFont(sf::Font &font) {textbox.setFont(font);}
            void setPosition(sf::Vector2f pos){textbox.setPosition(pos);}
            void setLimit(bool ToF, int lim); 
            void setSelected(bool sel) ;
            std::string getText() {return text.str();} 
            void drawTo(sf::RenderWindow &window){window.draw(textbox);}   
            void typedOn(sf::Event input);
        
        };  
    }
}