#include "fireflySwarm.h"

fireflySwarm::fireflySwarm(int _swarmSize, ofColor _litColor, ofColor _darkColor)
{
    swarmSize = _swarmSize;
    swarm = new firefly*[swarmSize];
    for (int i=0; i<swarmSize; i++) {
        swarm[i] = new firefly(_litColor, _darkColor);
    }

    generateNullTarget();
}

void fireflySwarm::generateTarget() {
    targetDuration = ofRandom(0.25);
    currentTargetTime = 0;

//    targetx = ofRandomWidth();
//    targety = ofRandomHeight();
    int i = int(ofRandom(swarmSize));
    targetx = swarm[i]->pos.x;
    targety = swarm[i]->pos.y;


    nullTargetPresent = false;
    targetPresent = true;
}
void fireflySwarm::generateNullTarget() {
    targetDuration = ofRandom(0.25, 0.5);
    currentTargetTime = 0;
    nullTargetPresent = true;
    targetPresent = false;
}

void fireflySwarm::update(bool isMousePressed, float mousex, float mousey) {
    for (int i=0; i<swarmSize; i++) {
        if (isMousePressed) {
            swarm[i]->update(isMousePressed, mousex, mousey);
        }
        else if (targetPresent) {
            swarm[i]->update(targetPresent, targetx, targety);
        }
        else if (nullTargetPresent) {
            swarm[i]->update(false, 0, 0);
        }
        else {
            swarm[i]->update(false, 0, 0);
        }
    }

    if (targetPresent || nullTargetPresent) {
        currentTargetTime += ofGetLastFrameTime();
        if (currentTargetTime > targetDuration) {
            if (ofRandom(1)<0.5) {
                generateTarget();
            }
            else {
                generateNullTarget();
            }
        }
    }
}

void fireflySwarm::draw() {
    for (int i=0; i<swarmSize; i++) {
        swarm[i]->draw();
    }
}
