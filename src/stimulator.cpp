#ifndef __class_stimulator_cpp__
#define __class_stimulator_cpp__

#include "stimulator.hpp"
#include "divide_string.hpp"

#include <cstdlib>
#include <cmath>
#include <vector>

//Constructors:

stimulator::stimulator(double x, double y, double z, double amplitude, double frequency, double start_phase) {

	set(x, y, z);
	this->amplitude = (amplitude == 0) ? 1 : amplitude;
	this->frequency = (frequency == 0) ? 1 : frequency;
	this->start_phase=start_phase;
}

stimulator::stimulator(std::string str) {
	vector<double> values = divide_string(str, 6);
	x = values[0];
	y = values[1];
	z = values[2];
	amplitude = values[3];
	frequency = values[4];
	start_phase = values[5];

	amplitude = (amplitude == 0) ? 1 : amplitude;
	frequency = (frequency == 0) ? 1 : frequency;
}



//TODO: giving this the correct formula, that takes into consideration the decrease of the amplitude in growing distance
double stimulator::get_elongation(point3d point, double time, double propagation_speed) {
	double wavelength = propagation_speed / frequency;
	if(!active_times.empty()){
		double t=(get_dist_3d(*this,point)/propagation_speed)-time;
		for(auto range:active_times){
			if(t>=range.first&&t<=range.second){
				goto regular_end_of_function;
			}
		}
		return 0.0;
	}
	regular_end_of_function: 
	return amplitude * sin(time*frequency*2*M_PI - 2*M_PI*get_dist_3d(*this, point)/wavelength + start_phase*M_PI/180);
}

#endif
