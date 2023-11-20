#include "BA_Algorithm.h"
/*! \brief A struct for storing a point.
* 
* This struct is used to store data of a 3D point in the environment. It provides id and coordinates of the point.
*/
struct Point {
	int id; /*! id of the point */
	float x; /*! x of the point */
	float y; /*! y of the point */
	float z; /*! z of the point */

	/*! 
	* A constructor function. Assings every value of the point object.
	*/
	Point(int id, float x, float y, float z) {
		this->id = id;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Eigen::Vector3f point_in_world_coordinates() {
		return Eigen::Vector3f(this->x, this->y, this->z);
	}
};