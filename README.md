# ChronoMate-Suite :hourglass_flowing_sand:
## Overview:
The Time Tracking CLI (Command Line Interface) application is a software tool designed to help users monitor and manage their time effectively. It offers a user-friendly text-based interface for users to track various tasks, record the time spent on each task, generate reports, and save their time tracking data to files.

## Key Features:

* Task Tracking: Users can start tracking a task by providing a task name. The application records the start time for the task.
* Task Stopping: When a task is completed or paused, users can stop tracking it. The application calculates the elapsed time and associates it with the task.
* Time Reporting: Users can view a report of all tracked tasks, showing the task names and the time spent on each task.
* File Export: The application allows users to save their time tracking data to a file. This feature is helpful for keeping a record of time spent on various activities over time.

## Installation 

### CMake MacOS
1. Clone the repo
```
git clone https://github.com/OleynikovNikolay/ChronoMate-Suite
cd CHRONOMATE-SUITE
```
2. Compile with CMake 
``` 
cmake .
make
```
3. Change directory for binary file path
```
cd bin
```

### Docker MacOS {Apple Silicon M1 (and M2) chip having AArch64=ARM64} / Linux
Check you architecture on MacOS 
```
arch
```
If it has `arm64` then you macOS is suitable for this image. 


1. Clone the repo
```
git clone https://github.com/OleynikovNikolay/ChronoMate-Suite
cd CHRONOMATE-SUITE
```
2. Build docker image
```
docker build -t chronomate-suite
```
3. Check if the image has been successfully built
```
docker images | grep chronomate-suite
```
4. Run docker in interactive terminal session 
```
docker run -it chronomate-suite 
```

### Pulling image from DockerHub for Linux and MacOS {Apple Silicon M1 (and M2) chip having AArch64=ARM64}
You may also pull the image (linux/arm64/v8) directly from DockerHub. 
```
docker pull 20041996/chronomate-suite:latest
```


## Usage:
* Local repo
```
./CHRONOMATE-SUITE
```
* Docker image
```
docker run -it 20041996/chronomate-suite
```


* Start Tracking: Users select the "Start Tracking" option and provide a name for the task they want to track. The application records the start time.
* Stop Tracking: When the task is completed or paused, users choose the "Stop Tracking" option and * specify the task name. The application calculates the elapsed time for the task and associates it with the task name.
* Display Report: Users can view a report of all tracked tasks, which includes the task names and the time spent on each task. This report helps users analyze how their time is allocated.
* Save to File: The application allows users to save the time tracking data to a file. Users provide a filename, and the application creates or appends to a file, storing the task names and associated time data.
* Exit: Users can exit the application when they are done tracking their time.


