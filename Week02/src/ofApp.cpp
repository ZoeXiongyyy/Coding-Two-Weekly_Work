#include "ofApp.h"

// This example uses pure openGL (mostly) to create a procedural sphere

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    // Maximilian audio stuff
    int sampleRate = 44100; /* Sampling Rate */
    int bufferSize= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    // Setup ofSound
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
/*//-----------------------------------------------Mesh-------------------------------
    ofEnableDepthTest();
    
    dim=50;
    spacing = ((PI * 2) / dim);
    size = 3;
    numPoints = dim * dim;
    
    
    
    
    
    // This code generates all the vertices we need to make a sphere
    for (int i = 0; i < dim + 1; i++) {
        
        
        
        // ******* Calculate the current ring position ********
        
        // To calculate the current ring position, we divide our spacing variable in half
        // This is because otherwise, the cosine / sine waves will
        // generate twice as many numbers as we need (e.g. positive then negative)
        // We only need the first half of the wave
        
        // z is the position of the current ring
        float z = size * cos(spacing / 2 * i );
        
        // This calculates the size of the current ring
        float s = size * sin(spacing / 2 * i );
        
        // For each ring..
        
        for (int j = 0; j < dim ; j++) {
            //------------------------------------new edited
            float mouseX1 = mouseX/10;
            float mouseY1 = mouseY/10;
            
            // m=10;//this affect how many petalles//
            float m = abs(mouseX - windowWidth/2);
            ///The smaller the number(whne less than 0.8) the more exaggerate the shape is
            float n1 = 1.2;
            float n2 = 0.8;
            ////This affect the size and the exaggerate of the shape in the same time //Recommend 9
            float n3 = abs(mouseX - windowWidth/2);
            
            int b = 1;
            int a = 2;
            int size2 = 3;
            
            float r1 = size2 * pow(pow(abs(cos((m * spacing/2 * j) / 4) / a), n2) + pow(abs(sin((m * spacing/2 * j) / 4)) / b, n3), -(1 / n1));

           
            // ...create the next point in the circle at the current size s, at the current depth z
            
            ofVec3f point;
            point.set(r1 * cos(spacing * j) * s,r1 * sin(spacing * j)*s,z);
            
            //point.set(cos(spacing * j) * s,sin(spacing * j) * s,z);
            
            points.push_back(point);

        }
    }
    
    

    cout << "done";*/
    
    
    //We are using ofCamera, which sets up a projection matrix like the ones we have built by hand.
    //Here we can set the clipping planes
    //And also the camera position
    //If we wanted we could adjust the FOV and a bunch of other stuff
    
    
  //  ofSetColor(200,200,125,255);
    cam.setNearClip(1);
    cam.setFarClip(-1000);
    cam.setPosition(0,0,30);
    
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    //-----------------------------------------------Mesh-------------------------------
        ofEnableDepthTest();
        
        dim=5;
        spacing = ((PI * 2) / dim);
        size = 3;
        numPoints = dim * dim;
    
        
        
        //ofBackground(0,0,0);
        //ofDrawRectangle(0, 0, 100, 100);
        //ofSetColor(0, 0, 0);
        
        // This code generates all the vertices we need to make a sphere
        for (int i = 0; i < dim + 1; i++) {
            
            
            //ofDrawRectangle(0, 0, windowWidth, windowHeight);
            
            // ******* Calculate the current ring position ********
            
            // To calculate the current ring position, we divide our spacing variable in half
            // This is because otherwise, the cosine / sine waves will
            // generate twice as many numbers as we need (e.g. positive then negative)
            // We only need the first half of the wave
            
            // z is the position of the current ring
            float z = size * cos(spacing / 2 * i );
            
            // This calculates the size of the current ring
            float s = size * sin(spacing / 2 * i );
            
            // For each ring..
            
            for (int j = 0; j < dim ; j++) {
                //------------------------------------new edited
                float mouseX1 = mouseX/100;
                float mouseY1 = mouseY/10;
                
                // m=10;//this affect how many petalles//
                int m = abs(mouseX - windowWidth/2);
                ///The smaller the number(whne less than 0.8) the more exaggerate the shape is
                float n1 = 1.2;
                float n2 = 0.8;
                ////This affect the size and the exaggerate of the shape in the same time //Recommend 9
                float n3 = abs(mouseX - windowWidth/2);
                
                int b = 1;
                int a = 2;
                int size2 = 3;
                
                float r1 = size2 * pow(pow(abs(cos((m * spacing/2 * j*mouseX1) / 4) / a), n2) + pow(abs(sin((m * spacing/2 * j) / 4)) / b, n3), -(1 / n1));
               
                // ...create the next point in the circle at the current size s, at the current depth z
                
                ofVec3f point;
                point.set(r1 * cos(spacing * j) * s,r1 * sin(spacing * j)*s,z);
                                //point.set(cos(spacing * j) * s,sin(spacing * j) * s,z);
               // ofVec3f *Points = & point;
                points.push_back(point);
                //ofBackground(0,0,0);
               // points.(*Points);

            }
        }
        
        

        cout << "done";
    
    //ofBackground(0);

    // cam gives us proper openGL world coordinates, like proper openGL
    cam.begin();
    //-----------------------------------rotation
    // We're rotating using OF, because OFs projection matrix is a bit screwy if we use the native openGL method.
    //ofFpsCounter();
    
    
    /*for(int i = 1; i < 256; i++){
        int r = 255%i;
        int g = 255;
        int b = 255;
        int a = i*100 + 100;
        ofSetColor(r,g,b,a);

    }*/
    
 
    
    
     ofSetColor( ofColor(196, 90, ofRandom( 170, 300 ) ));
    //ofSetColor(mouseX%120, mouseX%155, abs(windowWidth/2-mouseX)%200,abs(windowHeight/2- mouseY)%255);
    ofRotateY(mouseY%200);
    //ofRotateXDeg(ofGetElapsedTimeMillis()/10);
    ofRotateX(ofGetElapsedTimeMillis()/100);
    ofRotateZDeg(mouseX/10000);
    
    
    
 glBegin(GL_LINE_LOOP);

    // you could do this instead
//    glBegin(GL_TRIANGLES);
    
    //------------------------------------draw the picture

    for (int i = dim ; i < points.size(); i++) {
        
        //ofVec3f vec;
        ofVec3f vec;
       
        int mouseX2 = abs(windowWidth/2 - mouseX);
        int mouseY2 = abs(windowHeight/2 -mouseY);
       glVertex3f(points[i].x*mouseX2*0.001, points[i].y, points[i].z);
        
          
       glVertex3f(points[i-1].x*mouseX2*0.001, points[i-1].y, points[i-1].z);

       glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);

       glVertex3f(points[i-1].x, points[i-1].y, points[i-1].z);
          
       glVertex3f(points[i-dim-1].x, points[i-dim-1].y, points[i-dim-1].z);
          
       glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);
        
        
      /*glVertex3f(points[i].x*mouseX2, points[i].y, points[i].z);
        
        glVertex3f(points[i-1].x, points[i-1].y/mouseY, points[i-1].z);

        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);

        glVertex3f(points[i-1].x, points[i-1].y/mouseY, points[i-1].z);
        
        glVertex3f(points[i-dim-1].x, points[i-dim-1].y*mouseY, points[i-dim-1].z);
        
        glVertex3f(points[i-dim].x, points[i-dim].y, points[i-dim].z);*/
        
    }

    glEnd();

    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    if (x || y == 0) {
          mouseX = x;
          mouseY = y;
    } else if (x || x == 0) {
          mouseX = x;
          mouseY = y;
    }

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

/*void ofApp::ofSetColor(int r, int g, int b, int a){
    
    r = mouseX%255;
    g = floor(mouseX%250) + 1;
    b = floor(mouseX%245) +5 ;
    a = floor(mouseY%254) + 1;
    

}*/

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer& input){
    std::size_t nChannels = input.getNumChannels();
    for (size_t i = 0; i < input.getNumFrames(); i++)
    {
        // handle input here
        
    }
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& output){
    std::size_t outChannels = output.getNumChannels();
    for (int i = 0; i < output.getNumFrames(); ++i){
        
       // output[i * outChannels] = oscillator1.square(532) * 0.5;
        output[i * outChannels] = oscillator1.sinewave(44)*mouseY*0.00075*mouseX;
        output[i * outChannels + 1 ] = oscillator2.coswave(12)*abs(windowWidth-mouseX)*0.0001;
        //output[i * outChannels + 2 ] = oscillator3.sinewave(6*(oscillator2.coswave(88)))*mouseY*0.005;
        //output[i * outChannels + 1] = output[i * outChannels];

    }
}
