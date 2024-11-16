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
        {"help", {}},
        {"undo", {}},
        {"redo", {}}
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
            std::cerr << "Invalid option" << std::endl;
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

bool SemanticAnalyser::isCmdSingle() {
    return command_.CmdName.find(' ') == std::string::npos;
}

bool SemanticAnalyser::CheckPosition() {
    for(int arg = 0; arg < command_.ArgList.size(); ++arg) {
        if(command_.ArgList[arg] == "-pos") {
            if(arg + 2 >= command_.ArgList.size()) {
                std::cerr << "Option '-pos' requires two arguments" << std::endl;
                return false;
            }
            try {
                float pos_1 = std::stof(command_.ArgList[arg + 1]);
                float pos_2 = std::stof(command_.ArgList[arg + 2]);
                return true;
            }
            catch(const std::exception&) {
                std::cerr << "Invalid position values" << std::endl;
                return false;
            }
        }
    }
    std::cerr << "Option -pos not found" << std::endl;
    return false;
}

bool SemanticAnalyser::CheckID() {
    for(int arg = 0; arg < command_.ArgList.size(); ++arg) {
        if(command_.ArgList[arg] == "-id") {
            if(arg + 1 >= command_.ArgList.size()) {
                std::cerr << "Option '-id' requires one argument" << std::endl;
                return false;
            }
            try {
                int id = stoi(command_.ArgList[arg + 1]);
                return true;
            }
            catch(const std::exception&) {
                std::cerr << "Invalid ID value" << std::endl;
                return false;
            }
        }
    }
    std::cerr << "Opton -id not found" << std::endl;
    return false;
}

bool SemanticAnalyser::CheckCommand() {
    if(isCmdName() && isCmdSingle()) { 
        return true;
    }
    if (isCmdName() && isOption()) {
        if(command_.CmdName =="add shape" || "remove shape") {
            return (isShape() && CheckPosition() && isColor());
        }
        if(command_.CmdName == "add slide" || "remove slide") {
            return (CheckID());
        }
    }
    return false;
}

