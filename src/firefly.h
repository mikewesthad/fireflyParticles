#ifndef FIREFLY_H
#define FIREFLY_H

#include "ofMain.h"

class firefly
{
    public:
        firefly(ofColor litColor, ofColor darkColor);
        void update(bool isTarget, float x, float y);
        void draw();
        void randomHeadingChange();
        void randomColorChange();
        void updatePosition();
        void wrapHeading();

        ofVec2f pos;
        ofColor litColor;
        ofColor darkColor;
        ofColor color;
        float colorLevel;
        float width;
        float height;
        float heading;
        float speed;
        float movementNoiseOffset;
        float colorNoiseOffset;
        float maxTurningAngle;

};

#endif // FIREFLY_H
