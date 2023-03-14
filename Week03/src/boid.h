/*

 *
 */

#ifndef _BOID
#define _BOID
//#include <vector>
#include "ofMain.h"

#include <stdio.h>

class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:
    
    float boidRadius;
    float secondBoidRadius;
    
    
	//ofVec3f position;
	//ofVec3f velocity;
    
    //ofVec3f position2;
    //ofVec3f velocity2;
	
	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;
	
	float separationThreshold;
	float neighbourhoodSize;
	
    //So these are vak of functions. And these functions take a vector of pointers to Boyds as an input.
    //they return to a vector of three float
	ofVec3f separation(std::vector<Boid *> &otherBoids);
	ofVec3f cohesion(std::vector<Boid *> &otherBoids);
	ofVec3f alignment(std::vector<Boid *> &otherBoids);
    
    ofVec3f secondBoidSeparation(std::vector<Boid *> &otherSecondBoids);
    ofVec3f secondBoidCohesion(std::vector<Boid *> &otherSecondBoids);
    ofVec3f secondBoidAlignment(std::vector<Boid *> &otherSecondBoids);
    
    
	
// all the methods and variables after the
// public keyword can only be used by anyone
public:
    ofVec3f position;
    ofVec3f velocity;
    //constructor decleration
	Boid();
    //constructor decleration
    //Boid(ofVec3f &pos, ofVec3f &vel, ofVec3f &secondPos, ofVec3f &secondVel);
    Boid(ofVec3f &pos, ofVec3f &vel);
    //denstructor decleration
	~Boid();
    
    //ofVec3f position;
    //ofVec3f velocity;
	
	ofVec3f getPosition();
	ofVec3f getVelocity();
    
    //ofVec3f getPosition2();
    //ofVec3f getVelocity2();
    
	
	
	float getSeparationWeight();
	float getCohesionWeight();
	float getAlignmentWeight();
	
	float getSeparationThreshold();
	float getNeighbourhoodSize();
	
	void setSeparationWeight(float f);
	void setCohesionWeight(float f);
	void setAlignmentWeight(float f);
	
	void setSeparationThreshold(float f);
	void setNeighbourhoodSize(float f);
	
	void update(std::vector<Boid *> &otherBoids, std::vector<Boid *> &otherSecondBoids,ofVec3f &min, ofVec3f &max);
    void secondBoidUpdate(std::vector<Boid *> &otherBoids,std::vector<Boid *> &otherSecondBoids, ofVec3f &secondMin, ofVec3f &secondMax);
	
	void walls(ofVec3f &min, ofVec3f &max);
    void secondBoidWalls(ofVec3f &secondMin, ofVec3f &secondMax);
    
	void draw();
    void secondBoidDraw();
    
    
   
};

class secondBoid : public Boid{

    
   // secondBoid();
   // ～secondBoid();
    
   // ofVec3f secondBoidSeparation(std::vector<Boid *> &otherSecondBoids);
   // ofVec3f secondBoidCohesion(std::vector<Boid *> &otherSecondBoids);
   // ofVec3f secondBoidAlignment(std::vector<Boid *> &otherSecondBoids);
    
};

#endif
