#pragma once

#include "../core/SmartDevice.h"
#include "../observer/ISubject.h"
#include "../state/IDeviceState.h"
#include <memory>
#include <string>
using namespace std;

class Camera {
public:
    Camera(){}
    Camera(string type){}
    virtual ~Camera() = default;
    virtual void startRecording() = 0;
    virtual void stopRecording() = 0;
    virtual bool isRecording() const = 0;
    virtual bool enableNightVision() = 0;
    virtual bool disableNightVision() = 0;

};
