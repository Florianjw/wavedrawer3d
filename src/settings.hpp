#include <string>
#include <vector>
#include "point.hpp"

 /** class settings ******************************************
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
		vector<point> points;
		
		string file;
};