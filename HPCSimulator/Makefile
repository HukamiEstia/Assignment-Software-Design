HPCSim: libhpcsim.so HPCSimulator.cpp
	g++ -std=c++17 -g -L/home/hukami/Workspace/Assignment_Software_Design/HPCSimulator -Wall -o HPCSim HPCSimulator.cpp -lhpcsim 

libhpcsim.so: Config.cpp NumberGenerator.cpp Core.cpp Node.cpp Job.cpp Request.cpp Scheduler.cpp User.cpp Simulator.cpp Simulation.cpp
	g++ -std=c++17 -c -g -Wall -fPIC Config.cpp NumberGenerator.cpp Core.cpp Node.cpp Job.cpp Request.cpp User.cpp Scheduler.cpp Simulator.cpp Simulation.cpp
	g++ -std=c++17 -g -shared -o libhpcsim.so Config.o NumberGenerator.o Core.o Node.o Job.o Request.o User.o Scheduler.o Simulator.o Simulation.o