class SmartHomeHub;

class Client {
    SmartHomeHub* hub;

public:
    Client();
    ~Client();

    void setupSystem();
    void run();
};
