#pragma once
#include "Camera.h"
#include <string>
using namespace std;

class BrandBWirelessSCam : public Camera {
    string id, name, brand;
    bool recording;
    bool nightVisionEnabled;
public:
    BrandBWirelessSCam();
    BrandBWirelessSCam(string id, string name, string brand);

    void startRecording() override;
    void stopRecording() override;
    bool isRecording() const override;
    void enableNightVision()  override;
    void disableNightVision() override;
};
