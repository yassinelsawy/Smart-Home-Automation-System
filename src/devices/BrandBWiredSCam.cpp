#include "../../include/devices/BrandBWiredSCam.h"
#include <iostream>
using namespace std;

BrandBWiredSCam::BrandBWiredSCam(string id, string name, string brand)
    : id(id), name(name), brand(brand) {}

void BrandBWiredSCam::startRecording() {
    recording = true;
    cout << "[BrandBWiredSCam] Recording started.\n";
}

void BrandBWiredSCam::stopRecording() {
    recording = false;
    cout << "[BrandBWiredSCam] Recording stopped.\n";
}

bool BrandBWiredSCam::isRecording() const {
    return recording;
}

void BrandBWiredSCam::enableNightVision() {
    nightVisionEnabled = true;
    cout << "[BrandBWiredSCam] Night vision ENABLED.\n";
}

void BrandBWiredSCam::disableNightVision() {
    nightVisionEnabled = false;
    cout << "[BrandBWiredSCam] Night vision DISABLED.\n";
}
