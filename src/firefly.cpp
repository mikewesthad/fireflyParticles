#include "firefly.h"

firefly::firefly(ofColor _litColor, ofColor _darkColor)
{
    colorLevel = 0;
    darkColor = _darkColor;
    litColor = _litColor;
    color = darkColor;
    width = 3;
    height = 3;

    pos.set(100,100);
    speed = 5;
    heading = 0;
    maxTurningAngle = PI/8;

    movementNoiseOffset = ofRandom(100000);
    colorNoiseOffset = ofRandom(100000);
}

void firefly::update(bool isTarget, float x, float y) {
    if (isTarget) {
        float headingToMouse = atan2(y-pos.y, x-pos.x);
        if (headingToMouse < 0) {
            // atan2 returns on the range PI to -PI
            // I am using the range 0 to TWO_PI, so the negative values need
            // to be swung around in the positive direction one full turn
            headingToMouse += TWO_PI;
        }

        // Find the direction to travel based on shortest angular distance
        float clockwise_distance = 0;
        float counter_clockwise_distance = 0;
        if (headingToMouse < heading) {
            clockwise_distance = (TWO_PI - heading) + headingToMouse;
            counter_clockwise_distance = heading - headingToMouse;
        }
        else if (headingToMouse > heading) {
            clockwise_distance = headingToMouse - heading;
            counter_clockwise_distance = (TWO_PI - headingToMouse) + heading;
        }

        // Shortest distance is clockwise (positive) direction
        if (clockwise_distance < counter_clockwise_distance) {
            heading += ofRandom(0.0, maxTurningAngle);
        }
        // Shortest distance is counter-clockwise (negative) direction
        else if (clockwise_distance > counter_clockwise_distance) {
            heading += ofRandom(-maxTurningAngle, 0.0);
        }
        // Both distances are equal
        else {
            heading += ofRandom(-maxTurningAngle, maxTurningAngle);
        }
        wrapHeading();
    }
    else {
        randomHeadingChange();
    }

    randomColorChange();
    updatePosition();



}

void firefly::randomColorChange() {
    colorLevel += ofSignedNoise(ofGetElapsedTimef()+colorNoiseOffset);
    colorLevel = ofClamp(colorLevel, 0, 1);
    color.r = (litColor.r - darkColor.r)*colorLevel + darkColor.r;
    color.g = (litColor.g - darkColor.g)*colorLevel + darkColor.g;
    color.b = (litColor.b - darkColor.b)*colorLevel + darkColor.b;
}

void firefly::randomHeadingChange() {
    // Scaling the time down by a hundred causes circular flight paths
    // Scalling the time up by a hundred causes straight line paths
    heading += ofSignedNoise(ofGetElapsedTimef()+movementNoiseOffset) * maxTurningAngle;
    wrapHeading();
}

void firefly::wrapHeading() {
    if (heading < 0) {
        heading = TWO_PI + heading;
    }
    else if (heading > TWO_PI) {
        heading = heading - TWO_PI;
    }
}

void firefly::updatePosition() {
    pos.x += cos(heading) * speed;
    pos.y += sin(heading) * speed;
    if (pos.x > ofGetWindowWidth()+width/2) {
        pos.x = -width/2;
    }
    else if (pos.x < -width/2) {
        pos.x = ofGetWindowWidth()+width/2;
    }
    if (pos.y > ofGetWindowHeight()+height/2) {
        pos.y = -height/2;
    }
    else if (pos.y < -height/2) {
        pos.y = ofGetWindowHeight()+height/2;
    }
}

void firefly::draw() {
    ofSetColor(color);
    ofFill();
//    ofRectMode(OF_RECTMODE_CENTER);
//    ofRect(pos.x, pos.y, width, height);
    ofCircle(pos.x, pos.y, width);
}
