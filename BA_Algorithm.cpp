#include "BA_Algorithm.h"

BundleAdjustment::BundleAdjustment(std::map<int, Camera> cameras, std::map<int, Point> points, Eigen::Vector<Observation, -1> observations) {
	this->cameras = cameras;
	this->points = points;
	this->observations = observations;
}

BundleAdjustment::~BundleAdjustment() {

}

void BundleAdjustment::buildJacobian() {
	
	Eigen::SparseMatrix<float> jacobianMatrix(this->observations.size(), this->cameras.size() + this->points.size());

	for (int i = 0; i < this->observations.size() / 100; i++) {
		Observation current_observation = observations[i];

		Camera current_camera = this->cameras[current_observation.camera_id];
		Point current_point = this->points[current_observation.point_id];

		Eigen::Matrix3f rotation_matrix = current_camera.rotation_matrix(); 
		Eigen::Quaternion<float> camera_quaternion = current_camera.camera_quaternion(rotation_matrix);

		std::cout << std::endl << camera_quaternion << std::endl;

	}; 

}

void BundleAdjustment::calculateResiduals() {

}

void BundleAdjustment::solveJacobian() {

}

void BundleAdjustment::updateParams() {
}

/*Eigen::Vector2f BundleAdjustment::pointProjection(Point point, Camera camera) {
	Eigen::Vector3f point_in_camera_coordinates = this->pointWorldToCameraCoordinates(point, camera);

	Eigen::Vector2f perspective_division = {
		-point_in_camera_coordinates[0] / point_in_camera_coordinates[2],
		-point_in_camera_coordinates[1] / point_in_camera_coordinates[2]
	};

	float normalised_p = perspective_division.norm();

	float radial_distortion =
		1.0 + camera.distortion_coef1 * std::pow(normalised_p*normalized_p, 2) +
		camera.distortion_coef2 * std::pow(normalised_p*normalized_p, 4);


	return 	camera.focal_length * radial_distortion * perspective_division;
} */

/*Eigen::Vector3f BundleAdjustment::pointWorldToCameraCoordinates(Point point, Camera camera) {

	Eigen::Matrix3f rotation_matrix = camera.rotation_matrix();
	Eigen::Vector3f translation_vector = { camera.pos_x, camera.pos_y, camera.pos_z };

	Eigen::Matrix4f transform_matrix = Eigen::Matrix4f::Identity();
	transform_matrix.block<3, 3>(0, 0) = rotation_matrix;
	transform_matrix.block<3, 1>(0, 3) = translation_vector;

	Eigen::Vector4f point_world_homogeneous;
	point_world_homogeneous.head<3>() = point.point_in_world_coordinates();
	point_world_homogeneous(3) = 1.0;

	Eigen::Vector4f point_in_camera_coordinates = transform_matrix * point_world_homogeneous;

	return point_in_camera_coordinates.head<3>();
}
*/

/* template <typename T>
T pointProjectionFunction(
	T const& cameraRotation,
	T const& cameraPosition,
	T const& pointPosition,
	float focal_length
) {
	Eigen::Vector3f point_in_camera_coordinates = cameraRotation * pointPosition + cameraPosition;

	Eigen::Vector2f perspective_division = {
		-point_in_camera_coordinates[0] / point_in_camera_coordinates[2],
		-point_in_camera_coordinates[1] / point_in_camera_coordinates[2]
	};

	float normalised_p = perspective_division.norm();

	float radial_distortion =
		1.0 + camera.distortion_coef1 * std::pow(normalised_p, 2) +
		camera.distortion_coef2 * std::pow(normalised_p, 4);

	return focal_length * radial_distortion * perspective_division;
} */