#include "BA_Algorithm.h"

template <short N_IN, short N_OUT>
class JacobianFunctionWithRespectToRotation {
public:

	enum {
		InputesAtCompile = N_IN,
		ValuesAtCompile = N_OUT
	};

	typedef Eigen::Matrix<float, N_IN, N_IN> InputType;
	typedef Eigen::Matrix<float, N_OUT, 1> ValueType;
	typedef Eigen::Matrix <float,
		ValueType::RowsAtCompileTime,
		InputType::RowsAtCompileTime> JacobianType;

	JacobianFunctionWithRespectToRotation() {}

	template <typename T>
	void operator (const Eigen::Matrix<T, N_IN, N_IN>& vIn, Eigen::Matrix<T, N_OUT, 1> *vOut) const
	{
		/*Eigen::Vector3f point_in_camera_coordinates = vIn * point.point_in_world_coordinates + camera.camera_position;

		Eigen::Vector2f perspective_division = {
			-point_in_camera_coordinates[0] / point_in_camera_coordinates[2],
			-point_in_camera_coordinates[1] / point_in_camera_coordinates[2]
		};

		float normalised_p = perspective_division.norm();

		float radial_distortion =
			1.0 + camera.distortion_coef1 * std::pow(normalised_p, 2) +
			camera.distortion_coef2 * std::pow(normalised_p, 4);
		*/
		//vOut = camera.focal_length * radial_distortion * perspective_division;
		//vOut = vIn * 2;
	}
};