#include "../../include/devices/BrandBWirelessSCam.h"
#include <iostream>
using namespace std;

BrandBWirelessSCam::BrandBWirelessSCam(){
    recording = false;
    nightVisionEnabled = false;
}

BrandBWirelessSCam::BrandBWirelessSCam(string id, string name, string brand)
    : id(id), name(name), brand(brand) {}

void BrandBWirelessSCam::startRecording() {
    recording = true;
    cout << "[BrandBWirelessSCam] Recording started.\n";
}

void BrandBWirelessSCam::stopRecording() {
    recording = false;
    cout << "[BrandBWirelessSCam] Recording stopped.\n";
}

bool BrandBWirelessSCam::isRecording() const {
    return recording;
}

void BrandBWirelessSCam::enableNightVision() {
    nightVisionEnabled = true;
    cout << "[BrandBWirelessSCam] Night vision ENABLED.\n";
}

void BrandBWirelessSCam::disableNightVision() {
    nightVisionEnabled = false;
    cout << "[BrandBWirelessSCam] Night vision DISABLED.\n";
}
