/*! \brief A struct for storing observation data.
* 
* This struct is used to store observation data, it stores an id, camera nd point ids, point coordinates from the observation
*/
struct Observation {
	int id; /*! id of the observation */
	int camera_id; /*! id of the camera */
	int point_id; /*! id of the 3D point in environment */
	float x; /*! x of the point on camera */
	float y; /*! y of the point on camera */

	/*!
	* A constructor function. Assigns every value of the observation object.
	*/
	Observation(int id, int camera_id, int point_id, float x, float y) {
		this->id = id;
		this->camera_id = camera_id;
		this->point_id = point_id;
		this->x = x;
		this->y = y;
	}
};