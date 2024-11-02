#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

class ICommand {
    public:
      //std::string cmd_name;
      //std::vector<std::string> Args;
      virtual void execute() = 0;
};

#endif //ICOMMAND_HPP