#include "SemanticAnalyser.h"

SemanticAnalyser::SemanticAnalyser(SyntaxAnalyser::SCommand& command) : command_(command) {
    cmd = {
        {"add shape", {
            {"-type",  std::string{}},
            {"-pos",   std::pair<float, float>{}},
            {"-color", std::string{}}
        }},
        {"add slide", {
            {"-id", int{}}   
        }},
        {"remove slide", {
            {"-id", int{}}
        }},
        {"remove shape", {
            {"-type", std::string{}},
            {"-pos", std::pair<float, float>{}},
            {"-color", std::string{}}
        }},
        {"exit", {}},
        {"help", {}}
    };
}

bool SemanticAnalyser::isCmdName() {
    auto it = cmd.find(command_.CmdName);
    if(it == cmd.end()) {
        return false;
        std::cerr << "Invalid command name" << command_.CmdName << std::endl;
    }
    return true;
}

bool SemanticAnalyser::isOption() {
    auto it = cmd.find(command_.CmdName);
    auto& options = it->second;
    int arg = 0;
    for(auto option : options) {
        while(arg < command_.ArgList.size() && command_.ArgList[arg][0] != '-') {
            ++arg;
        }
        if(command_.ArgList[arg][0] == '-' && option.first != command_.ArgList[arg]) {
            std::cerr << "Ivalid option" << std::endl;
            return false;
        }
        ++arg;
    }
    return true;
}

bool SemanticAnalyser::isShape() {
    std::vector<std::string> shapes = {"circle", "rectangle", "triangle", "square", "ellipse"};
    for(std::string shape : shapes) {
        if(shape == command_.ArgList[1]) {
            return true;
        }
    }
    std::cerr << "Invalid shape name" << command_.ArgList[1] << std::endl;
    return false;
}

bool SemanticAnalyser::isColor() {
    int size = command_.ArgList.size();
    std::vector<std::string> colors = {"white", "red", "blue", "black", "green", "yellow", "brown"};
    for(std::string color : colors) {
        if(color == command_.ArgList[size - 1]) {
            return true;
        }
    }
    std::cerr << "Invalid color name" << std::endl;
    return false;
}

