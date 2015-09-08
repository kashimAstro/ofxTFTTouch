#include "ofMain.h"
#include "fb.h"
#include "ofxTFTTouch.h"

class ofApp : public ofBaseApp{
	public:
	ofxTFTTouch touch;
	int w,h;
	int Tx,Ty,Tp;
	string p;

	void setup(){
		w=ofGetScreenWidth();
		h=ofGetScreenHeight();
		touch.init("/dev/input/event0",w,h);
		ofLog()<<touch.getName();
	}

	void update(){
		Tx=touch.getCoordTouch().x;
		Ty=touch.getCoordTouch().y;
		Tp=touch.getCoordTouch().z;
		p ="X:"+ofToString(Tx)+" Y:"+ofToString(Ty)+" Pressur:"+ofToString(Tp);
	}

	void draw(){
		ofBackground(ofColor(10,45,110));
		ofDrawBitmapStringHighlight(p,ofPoint(20,20),ofColor(0),ofColor(255));

		ofPushStyle();
		ofSetColor(255,0,0);
		ofFill();
		ofCircle(Tx,Ty,Tp/4,Tp/4);
		ofPopStyle();

		ofNoFill();
		ofColor(255,255,255);
		ofCircle(Tx,Ty,Tp/3,Tp/3);
		fbcp.Copy();
	}
	/* */
};

int main( ){
	ofSetupOpenGL(1024,768, OF_WINDOW);
	ofRunApp( new ofApp());
}
