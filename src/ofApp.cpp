#include "ofApp.h"

ofApp::~ofApp() {
	delete kinect;
	//delete depth;
	delete IR;
}

//--------------------------------------------------------------
void ofApp::setup(){
	//Instantiate the kinect reference
	kinect = new ofxKFW2::Device;
	kinect->open();
	//kinect->initDepth();
	kinect->initInfrared();
	//kinect->initLongExposureInfrared();

	//depth = new DepthProc();
	IR = new IRProc();

	//ofAddListener(tuioClient.cursorAdded, this, &ofApp::tuioAdded);
	//ofAddListener(tuioClient.cursorRemoved, this, &ofApp::tuioRemoved);
	//ofAddListener(tuioClient.cursorUpdated, this, &ofApp::tuioUpdated);
	
	//tuioClient.start();
}

//--------------------------------------------------------------
void ofApp::update(){
	kinect->update();
	
	IR->update(kinect);
	//depth->update(kinect);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//kinect->getDepth()->draw(0, 0, ofGetWidth() / 2, ofGetHeight()); // note that the depth texture is RAW so may appear dark
	//kinect->getInfrared()->draw(0, 0, ofGetWidth(), ofGetHeight());
	//kinect->getLongExposureInfrared()->draw(0, 0, ofGetWidth() / 2, ofGetHeight());
	
	IR->draw();
	//depth->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if (key == 'f') {
		ofToggleFullscreen();
	}

	IR->keyPressed(key);
	//depth->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

/* For testing your own TUIO Client. Will draw the recieved cursors on screen
void ofApp::tuioAdded(ofxTuioCursor &tuioCursor){
	ofPoint loc = ofPoint(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
	cout << "Point n" << tuioCursor.getSessionId() << " add at " << loc << endl;
}

void ofApp::tuioUpdated(ofxTuioCursor &tuioCursor){
	//ofPoint loc = ofPoint(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
	//cout << "Point n" << tuioCursor.getSessionId() << " updated at " << loc << endl;
}

void ofApp::tuioRemoved(ofxTuioCursor &tuioCursor){
	ofPoint loc = ofPoint(tuioCursor.getX()*ofGetWidth(), tuioCursor.getY()*ofGetHeight());
	cout << "Point n" << tuioCursor.getSessionId() << " remove at " << loc << endl;
}
*/