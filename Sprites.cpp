#include "Sprites.h"
#include "Game.h"

Sprites::Sprites(Flags * f, Board * b, MainMenu * m)
{
    flags = f;
    board = b;
    mainMenu = m;
}

void Sprites::SetPointSpritePosition()
{
    for (int i = 1; i < 26; i++)
    {
        point[i].pnt.SetPosition(board->point[i].GetX() - playerWidth/2, board->point[i].GetY() - playerHeight/2);
        point[i].zone.SetZone(board->point[i].GetX(), board->point[i].GetY());
    }
}

void Sprites::SetSpriteImages()
{
    // Create the sprites of the board, background
    BoardSprite.SetImage(img.boardimg);
    Background.SetImage(img.backgroundimg);

    //selectors
    Selector.SetImage(img.selectorimg);

    LastMove[0].SetImage(img.lastmoveimg);//from point
    LastMove[1].SetImage(img.lastmoveimg);//to point

    HighLight.SetImage(img.highlightimg);
}

void Sprites::SetBoardPos()
{
    BoardSprite.SetPosition(boardX, boardY);
}

void Sprites::DrawLastMove(RenderWindow & App)
{
    if (flags->drawLastMove == true)
    {
        //from point
        LastMove[0].SetPosition(board->point[flags->fromPoint].GetX() - selectorWidth/2, board->point[flags->fromPoint].GetY() - selectorHeight/2);
        //to point
        LastMove[1].SetPosition(board->point[flags->toPoint].GetX() - selectorWidth/2, board->point[flags->toPoint].GetY() - selectorHeight/2);

        App.Draw(LastMove[1]);
        App.Draw(LastMove[0]);
    }
}

void Sprites::DrawPointSprites(RenderWindow & App)
{
    for (int i = 1; i < 26; i++)
    {
        switch(board->point[i].GetState())
        {
            case N:
                break;

            case T:
                if (!point[i].isDrawn)
                {
                    //clear the image stored first
                    point[i].pnt.SetImage(img.tigerimg);
                    point[i].isDrawn = true;
                }

                App.Draw(point[i].pnt);
                break;

            case G:
                if (!point[i].isDrawn)
                {
                    point[i].pnt.SetImage(img.goatimg);
                    point[i].isDrawn = true;
                }

                App.Draw(point[i].pnt);
                break;

            case V:
                App.Draw(sf::Shape::Circle(float(board->point[i].GetX()+1),float(board->point[i].GetY()+1),float(10),sf::Color(0,100,100)));
                break;
        }
    }
}

void Sprites::DrawHighlightSprite(RenderWindow & App)
{
    if (flags->selectPressed)
    {
        if (!flags->highlightIsDrawn)
        {
            HighLight.SetPosition(Selector.GetPosition().x, Selector.GetPosition().y);
        }

        App.Draw(HighLight);
        flags->highlightIsDrawn = true;
    }
}

void Sprites::DrawPermanentSprites(RenderWindow & App)
{
    // Draw the background, board
    App.Draw(Background);
    App.Draw(BoardSprite);
}

void Sprites::DrawSelector(RenderWindow & App)
{
    App.Draw(Selector);
}

bool Sprites::ImgLoader()
{
    if (!img.LoadImages())
    {
        return false;
    }

    return true;
}

void Sprites::DrawMainMenuSprite(RenderWindow & App)
{
    switch (mainMenu->mState)
    {
        case NORMAL:
        switch (mainMenu->nState)
        {
            case NBASE:
            Menu.SetImage(img.mmBase);
            break;

            case C_GOAT:
            Menu.SetImage(img.mmGoat);
            break;

            case C_TIGER:
            Menu.SetImage(img.mmTiger);
            break;

            case HUMAN:
            Menu.SetImage(img.mmHuman);
            break;

            case EXIT:
            Menu.SetImage(img.mmExit);
            break;

            case NCREDITS:
            Menu.SetImage(img.mmCredits);
            break;
        }
        break;

        case CREDITS:
        switch(mainMenu->cState)
        {
            case CBASE:
            Menu.SetImage(img.credits);
            break;

            case HIGHLIGHT:
            Menu.SetImage(img.creditsHighlight);
            break;
        }
        break;

        case LEVELS:
        switch (mainMenu->lState)
        {
            case LBASE:
            Menu.SetImage(img.lbase);
            break;

            case L1:
            Menu.SetImage(img.l1);
            break;

            case L2:
            Menu.SetImage(img.l2);
            break;

            case L3:
            Menu.SetImage(img.l3);
            break;

            case L4:
            Menu.SetImage(img.l4);
            break;

            case L5:
            Menu.SetImage(img.l5);
            break;
        }
        break;
    }
    App.Draw(Menu);
}
