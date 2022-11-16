# **Udacity Self Driving Car Engineer Course**

## **Project Nº 6: SDCE_PID**

### [Go To Source Code Directly!!!]() <br />

![alt text]() <br />

## **1) Project Summary:** <br />

In this project, you will apply the skills you have acquired in this course to design a PID controller to perform vehicle trajectory tracking. Given a trajectory as an array of locations, and a simulation environment (the vehicle with possible perturbations), you will design and code a PID controller and test its efficiency on the CARLA simulator used in the industry.<br />

The project will provide the dynamic model of the vehicle as well as an approximate distribution of the possible perturbations. The code to use the simulation environment (CARLA) will be provided as well as a template in C++ for the controller.<br />

The deliverable will be the code, explanations about how you chose the parameters, as well as a result of the simulation with analysis of the results.<br />

### **Project Steps Overview:**<br />
- Design the PID controller in C++.<br />
- Integrate the controller with the CARLA simulator.<br />
- Tune the parameters using a technique.<br />
- Explain a strategy to test the controller and perform the test.<br />
- Create plots to show how successful the controller is as well as the simulator video.<br />
- Talk about how the controller recovered/etc. Can be a sentence.<br />

### **Project Dependencies Overview:**<br />
- CARLA simulator in a workspace.<br />
- A C++ solver open sources and used in the industry.<br />
- Code to interact with the CARLA simulator.<br />

## **2) Installation:**<br />
Run the following commands to install the starter code in the Udacity Workspace:<br />

### **Clone the repository:** <br />
```
git clone https://github.com/udacity/nd013-c6-control-starter.git
```

### **Run Carla Simulator:** <br />
Open new window:<br />
```
su - student // Will say permission denied, ignore and continue
cd /opt/carla-simulator/
SDL_VIDEODRIVER=offscreen ./CarlaUE4.sh -opengl
```

### **Compile and Run the Controller:** <br />
Open new window
```
cd nd013-c6-control-starter/project
./install-ubuntu.sh
cd pid_controller/
rm -rf rpclib
git clone https://github.com/rpclib/rpclib.git
cmake .
make (This last command compiles your c++ code, run it after every change in your code)
```

### **Testing:** <br />
To test your installation run the following commands.<br />
```
cd nd013-c6-control-starter/project
./run_main_pid.sh This will silently fail ctrl + C to stop
./run_main_pid.sh (again) Go to desktop mode to see CARLA
```

If error bind is already in use, or address already being used
```
ps -aux | grep carla
kill id
```



