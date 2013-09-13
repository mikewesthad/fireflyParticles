#include "testApp.h"

int swarmSize=1000;
fireflySwarm *swarm;
fireflySwarm *swarm2;

bool isMousePressed = false;
float mousex = 0;
float mousey = 0;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofEnableAlphaBlending();

    swarm = new fireflySwarm(swarmSize, ofColor(72,35,83), ofColor(206,76,243));
    swarm2 = new fireflySwarm(swarmSize, ofColor(0,91,228), ofColor(0,0,57));

}

//--------------------------------------------------------------
void testApp::update(){
    swarm->update(isMousePressed, mousex, mousey);
    swarm2->update(isMousePressed, mousex, mousey);

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0,100);
    ofRectMode(OF_RECTMODE_CORNER);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+" fps", 10, 15);

    swarm->draw();
    swarm2->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mousex = x;
    mousey = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    mousex = x;
    mousey = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    isMousePressed = true;
    mousex = x;
    mousey = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    isMousePressed = false;
    mousex = x;
    mousey = y;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
