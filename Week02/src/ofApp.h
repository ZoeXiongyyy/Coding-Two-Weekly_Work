#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{
	public:
        void setup() override;
        void update() override;
        void draw() override;
        
        void keyPressed(int key) override;
        void keyReleased(int key) override;
        void mouseMoved(int x, int y ) override;
        void mouseDragged(int x, int y, int button) override;
        void mousePressed(int x, int y, int button) override;
        void mouseReleased(int x, int y, int button) override;
        void mouseEntered(int x, int y) override;
        void mouseExited(int x, int y) override;
        void windowResized(int w, int h) override;
        void dragEvent(ofDragInfo dragInfo) override;
        void gotMessage(ofMessage msg) override;
    
    
        ofSoundStream soundStream;
    
        //void ofSetColor(int r, int g, int b, int a);
    /* ofxMaxi*/
        void audioIn(ofSoundBuffer& input) override; // not used in this example
        void audioOut(ofSoundBuffer& output) override;
        maxiOsc oscillator1;
        maxiOsc oscillator2;
        maxiOsc oscillator3;
    
    
       
    
    
    
        int dim;
        float spacing;
        int size;
        int numPoints;
        int windowWidth = ofGetWindowWidth();
        int windowHeight = ofGetWindowHeight();
        //int mouseX = ofGetMouseX();
        //int mouseY = ofGetMouseY();
    
        ofCamera cam;
    
        std::vector<ofVec3f> points;
        
    
    
    
    
    
    
};
