#include "ofMain.h"
#include "fb.h"
#include "ofxTFTTouch.h"

class ofApp : public ofBaseApp{
	public:
	ofxTFTTouch touch;
	int w,h;
	int Tx,Ty,Tp;
	string p;
	ofFbo fbo;

	void setup(){
		w=ofGetScreenWidth();
		h=ofGetScreenHeight();
		touch.init("/dev/input/event0",w,h);
		ofLog()<<touch.getName();
		fbo.allocate(w,h);
	}

	void exit(){
		touch.exit();
	}

	void update(){
		Tx=touch.getCoordTouch().x;
		Ty=touch.getCoordTouch().y;
		Tp=touch.getCoordTouch().z;
		p ="X:"+ofToString(Tx)+" Y:"+ofToString(Ty)+" Pressur:"+ofToString(Tp)+" FPS:"+ofToString(ofGetFrameRate());
	}

	void draw(){
		ofBackground(ofColor(10,45,110));
		ofDrawBitmapStringHighlight(p,ofPoint(20,20),ofColor(0),ofColor(255));
		fbo.begin();
		if(Tx < 70 && Ty < 70)
			ofClear(0,0,0,0);
		ofSetColor(255);
		ofCircle(Tx,Ty,Tp/6,Tp/6);
		fbo.end();
		fbo.draw(0,0);
		/*
		ofPushStyle();
		ofSetColor(255,0,0);
		ofFill();
		ofCircle(Tx,Ty,Tp/4,Tp/4);
		ofPopStyle();

		ofNoFill();
		ofColor(255,255,255);
		ofCircle(Tx,Ty,Tp/3,Tp/3);
		*/
		fbcp.Copy();
	}
	/* */
};

int main( ){
	ofSetupOpenGL(1024,768, OF_WINDOW);
	ofRunApp( new ofApp());
}
