#pragma once
#include "Camera.h"
#include <string>
using namespace std;

class BrandAWiredSCam : public Camera {
    string id, name, brand;
    bool recording = false;
    bool nightVisionEnabled = false;
public:
    BrandAWiredSCam() = default;
    BrandAWiredSCam(string id, string name, string brand);
    void startRecording() override;
    void stopRecording() override;
    bool isRecording() const override;
    void enableNightVision() override;
    void disableNightVision() override;
};
