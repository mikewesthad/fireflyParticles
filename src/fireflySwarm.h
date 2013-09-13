#ifndef FIREFLYSWARM_H
#define FIREFLYSWARM_H

#include "ofMain.h"
#include "firefly.h"

class fireflySwarm
{
    public:
        fireflySwarm(int _swarmSize, ofColor _litColor, ofColor _darkColor);
        void update(bool isMousePressed, float mousex, float mousey);
        void generateTarget();
        void generateNullTarget();
        void draw();

        int swarmSize;
        firefly **swarm;

        bool nullTargetPresent;
        bool targetPresent;
        float currentTargetTime;
        float targetDuration;
        int targetx;
        int targety;
};

#endif // FIREFLYSWARM_H
