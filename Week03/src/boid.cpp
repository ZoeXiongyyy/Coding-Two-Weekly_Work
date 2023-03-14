/*
 *  boid.cpp
 *  boids
 *
 *  Created by Marco Gillies on 05/10/2010.
 *  Copyright 2010 Goldsmiths, University of London. All rights reserved.
 *
 */

#include "boid.h"
#include "ofMain.h"
// Constructor definition outside the class
//this method defines attribute when boids get moved
Boid::Boid()
{
	//separationWeight = 1.0f;
	//cohesionWeight = 0.2f;
    separationWeight = 1.0f;
    cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;
	
	separationThreshold = 15;
	neighbourhoodSize = 100;
	
    //float x = ofRandom(100, 200);
   // float y =  ofRandom(100, 200);
	position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
	velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
    //velocity = ofVec3f(ofRandom(-2, 10), ofRandom(-2, 10));
//===================================================================
    //secondBoidPosition = ofVec3f(1,1);
    //secondBoidPosition = ofVec3f(ofRandom(100, 200), ofRandom(100, 200));
    //secondBoidVelocity = ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1));
    boidRadius = 2;
    //float secondBoidRadius = 10;
    
}

//define a constructor"Boid"， outside the class"Boid“.
//this constructor boid has 2 parameters, just like a function.
//Boid::Boid(ofVec3f &pos, ofVec3f &vel)
Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
	separationWeight = 1.0f;
	cohesionWeight = 0.2f;
	alignmentWeight = 0.1f;
	
	separationThreshold = 15;
	neighbourhoodSize = 100;
	
	position = pos;
    velocity = vel;
   // secondBoidPosition = position;
   // secondBoidVelocity = velocity;
   //secondBoidPosition = secondPos;
   //secondBoidVelocity = secondVel;
}

Boid::~Boid()
{
	
}



//create a method"getSeparationWeight
float Boid::getSeparationWeight()
{
	return separationWeight;
}
float Boid::getCohesionWeight()
{
	return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
	return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
	return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
	return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
	separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
	cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
	alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
	separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
	neighbourhoodSize = f;
}

//-------------------------------------------------------------------------------------

ofVec3f Boid::getPosition()
{
	return position;
}

//---------------------------
/*ofVec3f Boid::getSecondBoidPosition()
{
    return secondBoidPosition;
}*/
//-------------------------------------------------------------------------------------

ofVec3f Boid::getVelocity()
{
	return velocity;
}
//--------------------------
/*ofVec3f Boid::getSecondBoidVelocity()
{
    return secondBoidVelocity;
}*/


//-------------------------------------------------------------------------------------
ofVec3f Boid::separation(std::vector<Boid *> &otherBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
    ofVec3f v;
	for (int i = 0; i < otherBoids.size(); i++)
	{	
		if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
		{
			//ofVec3f v = position -  otherBoids[i]->getPosition();
            v = position -  otherBoids[i]->getPosition();
			
			//return v;
        }
        
	}
    v.normalize();
    return v;
    
}
ofVec3f Boid::secondBoidSeparation(std::vector<Boid *> &otherSecondBoids)
{
    // finds the first collision and avoids that
    // should probably find the nearest one
    // can you figure out how to do that?
    ofVec3f v;
    for (int i = 0; i < otherSecondBoids.size(); i++)
    {
        if(position.distance(otherSecondBoids[i]->getPosition()) < separationThreshold +100)
        {
            //ofVec3f v = position -  otherBoids[i]->getPosition();
            v = position -  otherSecondBoids[i]->getPosition();
            
            //return v;
        }
        

    }
    v.normalize();
    return v;
    
}
//-------------------------------------------------------------------------------------

ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
{
    ofVec3f v;
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getPosition();
			count += 1;
            
            
            
		}
	}
    average /= count;
    v =  average - position;
    v.normalize();
	return v;
}

ofVec3f Boid::secondBoidCohesion(std::vector<Boid *> &otherSecondBoids)
{
    ofVec3f v;
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < otherSecondBoids.size(); i++)
    {
        if (position.distance(otherSecondBoids[i]->getPosition()) < neighbourhoodSize + 100)
        {
            average += otherSecondBoids[i]->getPosition();
            count += 1;
            
            
            //ofVec3f v =  average - secondBoidPosition;
            
        }
        
       /* if (secondBoidPosition.distance(otherSecondBoids[i]->getSecondBoidPosition()) < neighbourhoodSize)
        {
            average += otherSecondBoids[i]->getSecondBoidPosition();
            count += 1;
        }*/
    }
    average /= count;
    v =  average - position;
    v.normalize();
    return v;
}

//-------------------------------------------------------------------------------------
//alignment is how we decide what direction to head in.
//steer towards the average heading向着平均方向行驶
ofVec3f Boid::alignment(std::vector<Boid *> &otherBoids)
{
    ofVec3f v;
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getVelocity();
			count += 1;
            
            
            
		}
	}
    average /= count;
    v =  average - velocity;
    v.normalize();
	return v;
}

ofVec3f Boid::secondBoidAlignment(std::vector<Boid *> &othersecondBoids)
{
    ofVec3f v;
    ofVec3f average(0,0,0);
    int count = 0;
    for (int i = 0; i < othersecondBoids.size(); i++)
    {
        if (position.distance(othersecondBoids[i]->getPosition()) < neighbourhoodSize)
        {
            average += othersecondBoids[i]->getVelocity();
            //average += othersecondBoids[i]->getSecondBoidVelocity();
            count += 1;
            
            
            
        }
        

    }
    average /= count;
    v =  average - velocity;
    v.normalize();
    return v;
}

//-------------------------------------------------------------------------------------

void Boid::update(std::vector<Boid *> &otherBoids, std::vector<Boid *> &othersecondBoids,ofVec3f &min, ofVec3f &max)
{
	velocity += (0.9f)*separation(otherBoids) + (0.2f)*secondBoidSeparation(othersecondBoids);
	velocity += (0.3f)*cohesion(otherBoids) + (0.2f)*secondBoidCohesion(othersecondBoids);
	velocity += alignmentWeight*alignment(otherBoids) + (0.1f)*secondBoidAlignment(othersecondBoids);
	
	walls(min, max);
	position += velocity;
}

void Boid::secondBoidUpdate(std::vector<Boid *> &otherBoids,std::vector<Boid *> &othersecondBoids, ofVec3f &secondMin, ofVec3f &secondMax)
{
   // velocity += separationWeight*separation(othersecondBoids);
   // velocity += cohesionWeight*cohesion(othersecondBoids);
    //velocity += alignmentWeight*alignment(othersecondBoids);
    velocity += (0.9f)*separation(otherBoids) + (0.2f)*secondBoidSeparation(othersecondBoids);
    velocity += (0.3f)*cohesion(otherBoids) + (0.2f)*secondBoidCohesion(othersecondBoids);
    velocity += alignmentWeight*alignment(otherBoids) + (0.1f)*secondBoidAlignment(othersecondBoids);
    
    secondBoidWalls(secondMin, secondMax);
    position += velocity;
    //secondBoidPosition += velocity;
}

//-------------------------------------------------------------------------------------

void Boid::walls(ofVec3f &min, ofVec3f &max)
{
	/*if (position.x < min.x){
		position.x = min.x;
		velocity.x *= -0.5;
	} else if (position.x > max.x){
		position.x = max.x;
		velocity.x *= -0.5;
	}
	
	if (position.y < min.y){
		position.y = min.y;
		velocity.y *= -0.5;
	} else if (position.y > max.y){
		position.y = max.y;
		velocity.y *= -0.5;
	}*/
    if (position.x  < min.x){
        position.x = min.x;
        velocity.x *= -1;
    } else if (position.x> max.x){
        position.x = max.x;
        velocity.x *= -1;
    }
    
    if (position.y < min.y){
        position.y = min.y;
        velocity.y *= -1;
    } else if (position.y > max.y){
        position.y = max.y;
        velocity.y *= -1;
    }
    
}

void Boid::secondBoidWalls(ofVec3f &secondMin, ofVec3f &secondMax)
{

    if (position.x  < secondMin.x){
        position.x = secondMin.x;
        velocity.x *= -1;
    } else if (position.x> secondMax.x){
        position.x = secondMax.x;
        velocity.x *= -1;
    }
    
    if (position.y < secondMin.y){
        position.y = secondMin.y ;
        velocity.y *= -1;
    } else if (position.y > secondMax.y){
        position.y = secondMax.y;
        velocity.y *= -1;
    }
    
}

void Boid::draw()
{
	ofSetColor(0, 255, 255);
    ofFill();
	ofCircle(position.x, position.y, boidRadius*2);
    
}

void Boid::secondBoidDraw()
{
    ofSetColor(200, 100, 155);
    ofFill();
    ofCircle(position.x + 150, position.y + 150, boidRadius*2);
    //ofCircle(secondBoidPosition.x,secondBoidPosition.y, 20);
    ofSetColor(120, 100, 145);
    ofSetLineWidth(0.5);
    ofNoFill();
    ofDrawTriangle(position.x + 150, position.y,position.z, position.x + 155, position.y+20,position.z-10, position.x + 160, position.y,position.z);
    ofSetLineWidth(0.5);
    
}


