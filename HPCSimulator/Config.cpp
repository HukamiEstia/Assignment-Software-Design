#include "Config.h"

Config::Config(void) {}

Config::Config(std::string fileName){
    /*
    Parse the config file and convert the 
    read strings into int values
    /**/

    std::ifstream configFile(fileName);

    std::string line;
    if (configFile.is_open()) {
        std::cout << "file opened" << "\n";
        while (std::getline(configFile, line)) {
            std::istringstream lineStream(line);
            std::string key;
            if (std::getline(lineStream, key, '=')) {
                std::string value;
                if (std::getline(lineStream, value)) {
                    if (key == "nStudent"){
                        nStudent = std::stoi(value);
                    }
                    else if (key == "nResearcher"){
                        nResearcher = std::stoi(value);
                    }
                    else if (key == "nITSupport"){
                        nITSupport = std::stoi(value);
                    }
                    else if (key == "budgetStudent"){
                        budgetStudent = std::stoi(value);
                    }
                    else if (key == "budgetResearcher"){
                        budgetResearcher = std::stoi(value);
                    }
                    else if (key == "budgetITSupport"){
                        budgetITSupport = std::stoi(value);
                    }
                    else if (key == "nNode"){
                        nNode = std::stoi(value);
                    }
                    else if (key == "nGPU"){
                        nGPU = std::stoi(value);
                    }
                    else if (key == "speed"){
                        speed = std::stoi(value);
                    }
                    else if (key == "simulationTime"){
                        simulationTime = std::stoi(value);
                    }
                }
            }
        }
    configFile.close();
    }
    else {
        std::cout << "Unable to open file";
    }
}

int Config::Get_Student_Number(void){
    return nStudent;
}

int Config::Get_Researcher_Number(void){
    return nResearcher;
}

int Config::Get_ITSupport_Number(void){
    return nITSupport;
}

int Config::Get_Student_Budget(void){
    return budgetStudent;
}

int Config::Get_Researcher_Budget(void){
    return budgetResearcher;
}

int Config::Get_ITSupport_Budget(void){
    return budgetITSupport;
}

int Config::Get_Node_Number(void){
    return nNode;
}

int Config::Get_GPU_Number(void){
    return nGPU;
}

int Config::Get_Speed(void){
    return speed;
}

int Config::Get_Simulation_Time(void){
    return simulationTime;
}
