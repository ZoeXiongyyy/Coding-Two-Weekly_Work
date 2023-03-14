#include "testApp.h"




#include <stdio.h>


testApp::~testApp()
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
    
    for (int i = 0; i < secondBoids.size(); i++)
    {
        delete secondBoids[i];
    }
}
//define fuctions ouside the testAPP, but functions are all belongs to the class
//--------------------------------------------------------------
void testApp::setup(){ //setup function definition outside the class testAPP
	
	
	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	ofBackground(0,0,0);
    //ofVec3f velocity = ofVec3f(ofRandom(-2, 10), ofRandom(-2, 10));
	// set up the boids,decided the number of birds
    for (int i = 0; i < 50; i++){
        boids.push_back(new Boid());//call the method:push_back()
        //secondBoids.push_back(new secondBoid());//call the method:push_back();

        //boids[i]->position.x != boids[i+1]->position.x ;
        //boids[i]->position.y != boids[i+1]->position.y ;
        // secondBoids[i]->position.x != secondBoids[i+1]->position.x ;
        //secondBoids[i]->position.y != secondBoids[i+1]->position.y ;
        
    }
    
    for (int i = 0; i < 40; i++){
        secondBoids.push_back(new secondBoid());//call the method:push_back()
    }

}


//--------------------------------------------------------------
void testApp::update(){//update function definition outside the class testAPP
    
    ofVec3f min(boidRadius, boidRadius); //define an object1 of class ofVec3f
	//ofVec3f max(ofGetWidth() - boidRadius, ofGetHeight() -boidRadius);//define an object2 of class ofVec3f
    ofVec3f max(ofGetWidth() - boidRadius, ofGetHeight() -boidRadius);
    ofVec3f secondMin(boidRadius +150, boidRadius+150); //define an object1 of class ofVec3f
    //ofVec3f max(ofGetWidth() - boidRadius, ofGetHeight() -boidRadius);//define an object2 of class ofVec3f
    ofVec3f secondMax(ofGetWidth() - boidRadius-150, ofGetHeight() -boidRadius-150);
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids,secondBoids, min, max);//if your object is a pointer, you need to use ->to call method
	}
    
    for (int i = 0; i < secondBoids.size(); i++)
    {
        secondBoids[i]->secondBoidUpdate(secondBoids,boids, secondMin, secondMax);
    }
    
}

/*void testApp::secondBoidUpdate(){//update function definition outside the class testAPP
    
    ofVec3f min(0, 0); //define an object1 of class ofVec3f
    ofVec3f max(ofGetWidth(), ofGetHeight());//define an object2 of class ofVec3f
    
    
    for (int i = 0; i < secondBoids.size(); i++)
    {
        secondBoids[i]->update(boids, min, max);
    }

    
}*/





//--------------------------------------------------------------
//draw function definition outside the class testAPP
void testApp::draw(){

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}
    
    for (int i = 0; i < secondBoids.size(); i++)
    {
        //cannot use draw as method, if do this way , the code will excute "draw method" of original boid, not the second one
        secondBoids[i]->secondBoidDraw();
    }

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
 
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
