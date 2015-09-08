#include "ofMain.h"
#include "fb.h"
#include "ofxTFTTouch.h"

class ofApp : public ofBaseApp{
	public:
	ofxTFTTouch touch;
	int w,h;
	string p;

	void setup(){
		w=ofGetScreenWidth();
		h=ofGetScreenHeight();
		touch.init("/dev/input/event0",w,h);
		ofLog()<<touch.getName();
	}

	void update(){
		p ="X:"+ofToString(touch.getCoordTouch().x)+" Y:"+ofToString(touch.getCoordTouch().y)+" Pressur:"+ofToString(touch.getCoordTouch().z);
	}

	void draw(){
		ofDrawBitmapStringHighlight(p,ofPoint(20,20),ofColor(0),ofColor(255));
		fbcp.Copy();
	}
	/* */
};

int main( ){
	ofSetupOpenGL(1024,768, OF_WINDOW);
	ofRunApp( new ofApp());
}
