#include "BA_Algorithm.h"
/*! \brief A struct for storing camera data. 
* 
* This struct is used to store camera data. It provides camera id, position and intrinsics.
*/
struct Camera {
	int id; /*! id of the camera */
	float pos_x; /*! x position of the camera */
	float pos_y; /*! y position of the camera */
	float pos_z; /*! z position of the camera */
	float rot_x; /*! x rotation of the camera */
	float rot_y; /*! y rotation of the camera */
	float rot_z; /*! z rotation of the camera */
	float focal_length; /*! focal length of the camera */
	float distortion_coef1; /*! distrotion coefficient 1 */
	float distortion_coef2; /*! distrotion coefficient 2 */

	/*!
	* Constructor function. Assigns every values of the camera object.
	*/
	Camera(int id,
		float pos_x,
		float pos_y,
		float pos_z,
		float rot_x,
		float rot_y,
		float rot_z,
		float focal_length,
		float distortion_coef1,
		float distortion_coef2
	) {
		this->id = id;
		this->pos_x = pos_x;
		this->pos_y = pos_y;
		this->pos_z = pos_z;
		this->rot_x = rot_x;
		this->rot_y = rot_y;
		this->rot_z = rot_z;
		this->focal_length = focal_length;
		this->distortion_coef1 = distortion_coef1;
		this->distortion_coef2 = distortion_coef2;
	}

	Eigen::Matrix3f rotation_matrix() {
		Eigen::Vector3f rVector = { this->rot_x, this->rot_y, this->rot_z };
		float magnitude = rVector.norm();

		Eigen::Vector3f normalisedVector = rVector / magnitude;

		Eigen::Matrix3f skew_sym_matrix = {
			0, -normalisedVector[2], normalisedVector[1],
			normalisedVector[2], 0, -normalisedVector[0],
			-normalisedVector[1], normalisedVector[0], 0
		};

		Eigen::Matrix3f rotationMatrix = Eigen::Matrix3f::Identity() + sin(magnitude) * skew_sym_matrix +
			(1 - cos(magnitude)) * skew_sym_matrix * skew_sym_matrix;

		return rotationMatrix;
	}

	Eigen::Vector3f point_world_to_camera_coordinates(Eigen::Vector3f point_in_world_coordinates) {

		Eigen::Matrix3f rotation_matrix = this->rotation_matrix();
		Eigen::Vector3f translation_vector = { this->pos_x, this->pos_y, this->pos_z };

		Eigen::Matrix4f transform_matrix = Eigen::Matrix4f::Identity();
		transform_matrix.block<3, 3>(0, 0) = rotation_matrix;
		transform_matrix.block<3, 1>(0, 3) = translation_vector;

		Eigen::Vector4f point_world_homogeneous;
		point_world_homogeneous.head<3>() = point_in_world_coordinates;
		point_world_homogeneous(3) = 1.0;

		Eigen::Vector4f point_in_camera_coordinates = transform_matrix * point_world_homogeneous;

		return point_in_camera_coordinates.head<3>();
	}

	Eigen::Vector2f point_projection(Point point) {
		Eigen::Vector3f point_in_camera_coordinates = this->point_world_to_camera_coordinates(point.point_in_world_coordinates());

		Eigen::Vector2f perspective_division = {
			-point_in_camera_coordinates[0] / point_in_camera_coordinates[2],
			-point_in_camera_coordinates[1] / point_in_camera_coordinates[2]
		};

		float normalised_p = perspective_division.norm();

		float radial_distortion =
			1.0 + this->distortion_coef1 * std::pow(normalised_p, 2) +
			this->distortion_coef2 * std::pow(normalised_p, 4);


		return 	this->focal_length * radial_distortion * perspective_division;;
	}
};

