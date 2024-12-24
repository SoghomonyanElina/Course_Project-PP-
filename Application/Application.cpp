#include "Application.h"

Application::Application() {
    controller = std::make_shared<Controller>();
    //parser = std::make_shared<Parser>(std::cin);
    document = std::make_shared<Document>();
    editor = std::make_shared<Editor>();
    visualization = std::make_shared<Visualization>();
}

Application& Application::getInstance() {
    static Application application;
    return application;
}

void Application::Start() {
    controller->Start();
}