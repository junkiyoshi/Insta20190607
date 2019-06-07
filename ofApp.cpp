#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto size = 144;
	auto len = 120;
	auto span = 1;
	int param_start = ofGetFrameNum();
	for (int x = size * 0.5; x < ofGetWidth(); x += size) {

		for (int y = size * 0.5; y < ofGetHeight(); y += size) {

			param_start += 10;

			ofPushMatrix();
			ofTranslate(x, y);

			vector<glm::vec2> vertices, sub_vertices;
			for (int i = 1; i <= 12; i++) {

				vertices.clear();
				sub_vertices.clear();
				for (int param = param_start; param < param_start + span * i; param++) {

					vertices.push_back(this->make_point(len, param));
					sub_vertices.push_back((this->make_point(len - 35, param)));
				}
				param_start += i * span;

				reverse(sub_vertices.begin(), sub_vertices.end());

				ofBeginShape();
				ofVertices(vertices);
				ofVertices(sub_vertices);
				ofEndShape(true);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param, int width) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}