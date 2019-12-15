#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


class Config
{
private:
    int nStudent;
    int nResearcher;
    int nITSupport;
    int budgetStudent;
    int budgetResearcher;
    int budgetITSupport;
    int nNode;
    int nGPU;
    int speed;
    int simulationTime;

public:
    Config(void);
    Config(std::string fileName);
           
    int Get_Student_Number(void);
    int Get_Researcher_Number(void);
    int Get_ITSupport_Number(void);
    int Get_Student_Budget(void);
    int Get_Researcher_Budget(void);
    int Get_ITSupport_Budget(void);
    int Get_Node_Number(void);
    int Get_GPU_Number(void);
    int Get_Speed(void);
    int Get_Simulation_Time(void);
};
