#include "Carpentry.h"

Carpentry::Carpentry() {}

Carpentry::~Carpentry() {}

int Carpentry :: calculateCardboards(int pieceH, int pieceW, int requiredPieces)
{
    float ch = 8.0f;
    float cw = 5.0f;

    bool validInput = ((pieceH <= ch && pieceW <= cw) || (pieceH <= cw && pieceW <= ch));

    if(!validInput)
        return -1;


    float h1 = ch/pieceH;
    float w1 = cw/pieceW;
    int total1 = h1 * w1;

    float h2 = ch/pieceW;
    float w2 = cw/pieceH;
    int total2 = h2 * w2;




}
