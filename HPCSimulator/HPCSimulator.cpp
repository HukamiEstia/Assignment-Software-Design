#include "User.h"
#include "Simulator.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
	int Nsupport = 100;
	int Nresearch = 100;
	int Nstudent = 100;
	int BudgetSupport = 100;
	int BudgetResearch = 100;
	int BudgetStudent = 100;

	std::vector<User> supports;
	std::vector<User> researchers;
	std::vector<User> students;

	for (int i = 0; i < Nsupport; ++i) {
		User newSupport = User("support");
		supports.push_back(newSupport);
	}
	for (int i = 0; i < Nresearch; ++i) {
		User newResearcher = User("researcher");
		supports.push_back(newResearcher);

	}for (int i = 0; i < Nstudent; ++i) {
		User newStudent = User("student");
		supports.push_back(newStudent);
	}

	supports[0].GenerateRequest();
}