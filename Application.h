#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "../CLI/Parser.h"
#include "../CLI/Controller.h"
#include "../Document/Document.h"
#include "../Editor/Editor.h"
#include "../Visualization/Visualization.h"

class Application {
    public:
      static Application& getInstance();
      void Start();
      std::shared_ptr<Controller> controller;
      std::shared_ptr<Document> document;
      //std::shared_ptr<Parser> parser;
      std::shared_ptr<Editor> editor;
      std::shared_ptr<Visualization> visualization
    private:
      Application();
      Application(const Application& other) = delete;
      Application& operator=(const Application& other) = delete;
};

#endif //APPLICATION_HPP