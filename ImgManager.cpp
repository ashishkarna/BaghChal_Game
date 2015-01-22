#include "ImgManager.h"

bool ImgManager::LoadImages()
{
    if (!boardimg.LoadFromFile("images/board.png")    ||
        !backgroundimg.LoadFromFile("images/background.png")   ||
        !selectorimg.LoadFromFile("images/selector.png")   ||
        !lastmoveimg.LoadFromFile("images/lastmove.png")   ||
        !tigerimg.LoadFromFile("images/tiger.png") ||
        !goatimg.LoadFromFile("images/goat.png") ||
        !highlightimg.LoadFromFile("images/selectorhighlight.png") ||
        !mmBase.LoadFromFile("images/mainMenu/mmBase.png") ||
        !mmGoat.LoadFromFile("images/mainMenu/mmGoat.png") ||
        !mmTiger.LoadFromFile("images/mainMenu/mmTiger.png") ||
        !mmHuman.LoadFromFile("images/mainMenu/mmHuman.png") ||
        !mmExit.LoadFromFile("images/mainMenu/mmExit.png") ||
        !mmCredits.LoadFromFile("images/mainMenu/mmCredits.png") ||
        !credits.LoadFromFile("images/mainMenu/credits.png") ||
        !creditsHighlight.LoadFromFile("images/mainMenu/ch.png") ||
        !lbase.LoadFromFile("images/mainMenu/levels/lbase.png") ||
        !l1.LoadFromFile("images/mainMenu/levels/l1.png") ||
        !l2.LoadFromFile("images/mainMenu/levels/l2.png") ||
        !l3.LoadFromFile("images/mainMenu/levels/l3.png") ||
        !l4.LoadFromFile("images/mainMenu/levels/l4.png") ||
        !l5.LoadFromFile("images/mainMenu/levels/l5.png"))
    {
        return false;
    }
    return true;
}
