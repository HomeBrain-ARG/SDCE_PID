# **Udacity Self Driving Car Engineer Course**

## **Project Nº 6: SDCE_PID**

### [Go To Source Code Directly!!!](https://github.com/HomeBrain-ARG/SDCE_PID/tree/main/01_Source_Code) <br />

![alt text](https://github.com/HomeBrain-ARG/SDCE_PID/blob/main/00_Images/00_Prueba_Auto_Sin_Movimiento.JPG) <br />

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

## **3) Project Instructions:**<br />
In the previous project you built a path planner for the autonomous vehicle. Now you will build the steer and throttle controller so that the car follows the trajectory.<br />
You will design and run the a PID controller as described in the previous course.<br />
In the directory **/pid_controller** you will find the files **pid_controller.cpp** and **pid_controller.h**. This is where you will code your pid controller. The function pid is called in **main.cpp**.<br />

### **Step 1: Build the PID controller object.** <br />

Complete the TODO in the **pid_controller.h** and **pid_controller.cpp**.<br />

Run the simulator and see in the desktop mode the car in the CARLA simulator. Take a screenshot and add it to your report. The car should not move in the simulation.<br />

### **Step 2: PID controller for throttle.** <br />
1) In main.cpp, complete the TODO (step 2) to compute the error for the throttle pid. The error is the speed difference between the actual speed and the desired speed.<br />
Useful variables:<br />
- The last point of **v_points** vector contains the velocity computed by the path planner.<br />
- **velocity** contains the actual velocity.<br />
- The output of the controller should be inside **[-1, 1]**.<br />

2) Comment your code to explain why did you computed the error this way.<br />
3) Tune the parameters of the pid until you get satisfying results (a perfect trajectory is not expected).<br />

### **Step 3: PID controller for steer.** <br />

1) In **main.cpp**, complete the TODO (step 3) to compute the error for the steer pid. The error is the angle difference between the actual steer and the desired steer to reach the planned position.<br />

Useful variables:<br />

- The variable y_points and x_point gives the desired trajectory planned by the path_planner.<br />
- yaw gives the actual rotational angle of the car.<br />
- The output of the controller should be inside [-1.2, 1.2].<br />
- If needed, the position of the car is stored in the variables x_position, y_position and z_position.<br />

2) Comment your code to explain why did you computed the error this way.<br />

3) Tune the parameters of the pid until you get satisfying results (a perfect trajectory is not expected).<br />

### **Step 4: Evaluate the PID efficiency.** <br />
The values of the error and the pid command are saved in thottle_data.txt and steer_data.txt. Plot the saved values using the command (in nd013-c6-control-refresh/project):<br />

```
python3 plot_pid.py
```

You might need to install a few additional python modules:<br />

```
pip3 install pandas
pip3 install matplotlib
```
<br />

## **4) Results:** <br />

FIGURE 1: Dodging the vehicle to the right.. <br />
![alt text](https://github.com/HomeBrain-ARG/SDCE_PID/blob/main/00_Images/01_Car.JPG) <br />

FIGURE 2: Arriving at the last vehicle without oscillations. <br />
![alt text](https://github.com/HomeBrain-ARG/SDCE_PID/blob/main/00_Images/02_Car.JPG) <br />

FIGURE 3: Stopping at the end of the path. <br />
![alt text](https://github.com/HomeBrain-ARG/SDCE_PID/blob/main/00_Images/04_Car.JPG) <br />

FIGURE 4: Steering Error vs. Steering Output. <br />
![alt text](https://github.com/HomeBrain-ARG/SDCE_PID/blob/main/00_Images/05_Error_Steering.JPG) <br />
### **In this graph it can be seen that the error follows the output signal in an acceptable way.** <br />

FIGURE 5: Throttle Error vs. Throttle Output vs Brake Output. <br />
![alt text](https://github.com/HomeBrain-ARG/SDCE_PID/blob/main/00_Images/06_Error_Throttle.JPG) <br />
### **In the first part of the curve the throttle error is high, an improvement is seen when the vehicle moves in a straight line continuously.** <be />




### [Go To Source Code Directly!!!](https://github.com/HomeBrain-ARG/SDCE_PID/tree/main/01_Source_Code) <br />
