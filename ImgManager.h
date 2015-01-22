#ifndef IMGMANAGER_H
#define IMGMANAGER_H

#include "headers.h"

class ImgManager
{
public:
    Image boardimg, backgroundimg, selectorimg, highlightimg, goatimg, tigerimg, lastmoveimg;
    Image mmBase, mmGoat, mmTiger, mmHuman, mmExit, mmCredits, credits, creditsHighlight, lbase, l1, l2, l3, l4, l5;
    bool LoadImages();
};

#endif
