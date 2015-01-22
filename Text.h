#ifndef TEXT_H
#define TEXT_H

#include "Headers.h"
#include "Flags.h"
#include <sstream>//to convert numbers to string

class Text
{
private:
    Font Cheeseburger;
    void ConvertToString(std::string & strng, int n);
    Flags * flags;

    String End;
    String DGoats;//dead goats
    String RGoats;//remaining goats to be placed
    String defturn;//define turn
    String PosRepeated;//position repeated
    String InvalidMove;
    String ComputerThinking;
    String Escape;

    std::string dgoats;
    std::string rgoats;

public:
    Text(Flags * f);
    bool LoadFont();

    void SetTextPositions();
    void DisplayTexts(RenderWindow & App);
    void DisplayEndText(RenderWindow & App);
    void DisplayThinkingMessage(RenderWindow & App);
};

#endif
