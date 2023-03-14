#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include <vector>
#include "boid.h"

#include <stdio.h>


class testApp : public ofBaseApp{
	
public:
    ~testApp();//destructor
	
    void setup();
    void update();
    
    //void secondBoidUpdate();
    
    
    void draw();
    
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    float boidRadius = 3;
    //ofVec3f velocity;
    
    
    //vector with "Boid" pointer
    std::vector<Boid *> boids;
    //each one boid is one bird in the flock,this is an array , standard vector is an array,it's just a vector of objects
    //这是属于boid 的pointer，因为创建了pointer所以需要再destructor后面创建的函数中delete pointer
    
    //Boid
    std::vector<Boid *> secondBoids;
    
    
    
	
};

#endif	
