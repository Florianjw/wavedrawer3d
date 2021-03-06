#ifndef __class_settings_hpp__
#define __class_settings_hpp__

#include "stimulator.hpp"

#include <string>
#include <vector>

 /*** class settings *****************************************
 *                                                           *
 * This class contains all the information about the         *
 * settings of the programm                                  *
 *                                                           *
 *                                                           *
 *                                                           *
 *************************************************************/

 using namespace std;
 
class settings{
	public:
		settings();
		settings(int argc, char **argv);
		unsigned int width;
		unsigned int height;
		unsigned int number_of_pics;
		double propagation_speed;
		double total_amplitude;
		double runtime;
		vector<stimulator> stimulators;
		
		string file;
};

#endif
