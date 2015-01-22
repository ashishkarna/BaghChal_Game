#include "MainMenu.h"

void MainMenu::Initialize()
{
    mState = NORMAL;
    nState = NBASE;
    cState = CBASE;
    lState = LBASE;

    //normal zones
    //goat
    NormalZone[0].low_x = 40;
    NormalZone[0].high_x = 1350;
    NormalZone[0].low_y = 385;
    NormalZone[0].high_y = 440;

    //tiger
    NormalZone[1].low_x = 40;
    NormalZone[1].high_x = 1350;
    NormalZone[1].low_y = 480;
    NormalZone[1].high_y = 540;

    //human
    NormalZone[2].low_x = 240;
    NormalZone[2].high_x = 1150;
    NormalZone[2].low_y = 570;
    NormalZone[2].high_y = 630;

    //exit
    NormalZone[3].low_x = 20;
    NormalZone[3].high_x = 150;
    NormalZone[3].low_y = 660;
    NormalZone[3].high_y = 710;

    //credits
    NormalZone[4].low_x = 1100;
    NormalZone[4].high_x = 1350;
    NormalZone[4].low_y = 660;
    NormalZone[4].high_y = 710;

    //credits zone
    CreditsZone.low_x = 60;
    CreditsZone.high_x = 230;
    CreditsZone.low_y = 680;
    CreditsZone.high_y = 720;

    int height = 52;
    int width = 305;
    int vGap = 47;//vertical gap
    int startHeight = 272;
    int startWidth = 535;
    int dHeight = vGap + height;//difference in height

    //level zones
    LevelZone[0].low_x = startWidth;
    LevelZone[0].high_x =  startWidth + width;
    LevelZone[0].low_y = startHeight;
    LevelZone[0].high_y = startHeight + height;

    LevelZone[1].low_x = startWidth;
    LevelZone[1].high_x =  startWidth + width;
    LevelZone[1].low_y = LevelZone[0].low_y + dHeight;
    LevelZone[1].high_y = LevelZone[0].low_y + dHeight + height;

    LevelZone[2].low_x = startWidth;
    LevelZone[2].high_x =  startWidth + width;
    LevelZone[2].low_y = LevelZone[1].low_y + dHeight;
    LevelZone[2].high_y = LevelZone[1].low_y + dHeight + height;

    LevelZone[3].low_x = startWidth;
    LevelZone[3].high_x =  startWidth + width;
    LevelZone[3].low_y = LevelZone[2].low_y + dHeight;
    LevelZone[3].high_y = LevelZone[2].low_y + dHeight + height;

    LevelZone[4].low_x = startWidth;
    LevelZone[4].high_x =  startWidth + width;
    LevelZone[4].low_y = LevelZone[3].low_y + dHeight;
    LevelZone[4].high_y = LevelZone[3].low_y + dHeight + height;
}
