#include "Text.h"

Text::Text(Flags * f)
{
    flags = f;
}

bool Text::LoadFont()
{
    if (!Cheeseburger.LoadFromFile("fonts/cheeseburger.ttf"))
        return false;

    return true;
}

void Text::SetTextPositions()
{
    // Initialize the end text
    End.SetFont(Cheeseburger);
	End.SetSize(60.f);
    End.SetPosition(0, 0);
    End.SetColor(Color(244, 241, 6));

    //Intilialize the dead goats text
    DGoats.SetPosition(0, boardHeight/2);

    //Intilialize the remaining goats text
    RGoats.SetPosition(0, boardHeight/2 - 30);

    PosRepeated.SetPosition(0, boardHeight/2 + 60);
    PosRepeated.SetColor(Color(244, 241, 6));
    PosRepeated.SetText("Repetition is not allowed!");

    InvalidMove.SetPosition(0, boardHeight/2 + 60);
    InvalidMove.SetColor(Color(244, 241, 6));
    InvalidMove.SetText("Invalid Move!");

    ComputerThinking.SetPosition(0, 0);
    ComputerThinking.SetColor(Color(244, 241, 6));
    ComputerThinking.SetText("I am thinking...");

    //Initialize the flags->turn string
    defturn.SetPosition(0, boardHeight/2 - 90);
    defturn.SetColor(Color(244, 241, 6));

    Escape.SetSize(20.f);
    Escape.SetPosition(0, 150);
    Escape.SetText("(Press Escape.)");
    Escape.SetColor(Color(244, 241, 6));
}

void Text::DisplayTexts(RenderWindow & App)
{
    //convert numbers dgoats & rgoats to string
    ConvertToString(dgoats, flags->deadGoats);
    ConvertToString(rgoats, flags->goatsToBePlaced);

    DGoats.SetText("Dead Goats: " + dgoats);
    App.Draw(DGoats);

    RGoats.SetText("Goats to place: " + rgoats);
    App.Draw(RGoats);

    if (flags->drawRepeatText)
    {
        App.Draw(PosRepeated);
    }

    if (flags->drawInvalidMove && !flags->drawRepeatText)
    {
        App.Draw(InvalidMove);
    }

    flags->turn == Tiger? defturn.SetText("Turn: Tiger") : defturn.SetText("Turn: Goat");
    App.Draw(defturn);
}

void Text::ConvertToString(std::string & strng, int n)
{
    std::ostringstream convert;
    convert << n;
    strng = convert.str();
}

void Text::DisplayEndText(RenderWindow & App)
{
     if (flags->winner == Tiger)
     {
        End.SetText("Tiger player\nwins!");
     }

     else
     {
        End.SetText("Goat player\nwins!");
     }
    App.Draw(End);
    App.Draw(Escape);
}

void Text::DisplayThinkingMessage(RenderWindow & App)
{
    if (flags->drawThinking)
    {
        App.Draw(ComputerThinking);
    }
}
