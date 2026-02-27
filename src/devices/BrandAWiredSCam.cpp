#include "../../include/devices/BrandAWiredSCam.h"
#include <iostream>
using namespace std;


BrandAWiredSCam::BrandAWiredSCam(string id, string name, string brand) 
    : id(id), name(name), brand(brand){}
void BrandAWiredSCam::startRecording() {
    recording = true;
    cout << "[BrandAWiredSCam] Recording started.\n";
}

void BrandAWiredSCam::stopRecording() {
    recording = false;
    cout << "[BrandAWiredSCam] Recording stopped.\n";
}

bool BrandAWiredSCam::isRecording() const {
    return recording;
}

void BrandAWiredSCam::enableNightVision() {
    nightVisionEnabled = true;
    cout << "[BrandAWiredSCam] Night vision ENABLED.\n";
}

void BrandAWiredSCam::disableNightVision() {
    nightVisionEnabled = false;
    cout << "[BrandAWiredSCam] Night vision DISABLED.\n";
}
