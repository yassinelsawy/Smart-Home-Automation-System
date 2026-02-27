#include "../../include/devices/BrandAWirelessSCam.h"
#include <iostream>
using namespace std;


BrandAWirelessSCam::BrandAWirelessSCam(string id, string name, string brand)
    : id(id), name(name), brand(brand) {}
void BrandAWirelessSCam::startRecording() {
    recording = true;
    cout << "[BrandAWirelessSCam] Recording started.\n";
}

void BrandAWirelessSCam::stopRecording() {
    recording = false;
    cout << "[BrandAWirelessSCam] Recording stopped.\n";
}

bool BrandAWirelessSCam::isRecording() const {
    return recording;
}

void BrandAWirelessSCam::enableNightVision() {
    nightVisionEnabled = true;
    cout << "[BrandAWirelessSCam] Night vision ENABLED.\n";
}

void BrandAWirelessSCam::disableNightVision() {
    nightVisionEnabled = false;
    cout << "[BrandAWirelessSCam] Night vision DISABLED.\n";
}
