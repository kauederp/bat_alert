* Author: [Kaue Delgado](https://github.com/kauederp)
* date: 2022-01-16

# bat_alert
A minimal C++ battery manager that triggers an alert.


### Compile
> g++ main.cpp -o bat_alert 
### Install
> ln -s $(pwd)/bat_alert /usr/local/bin/
### How to use
> $ batalert limiting_number

limiting_number is an integer representing the percentage that will trigger the alert. It is recommended to use 15 or 20
