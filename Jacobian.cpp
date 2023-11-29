#include "Jacobian.h"

JacobianCalculator::JacobianCalculator(Camera camera, Point point) {
	this->camera = camera;
	this->point = point;
	this->rotation_matrix = camera.rotation_matrix();
	this->quaternion = camera.camera_quaternion(this->rotation_matrix);
}

JacobianCalculator::~JacobianCalculator() {

}

void JacobianCalculator::calculateComponentVectors() {
	Eigen::Vector3f point_coordinates = this->point.point_in_world_coordinates();
	Eigen::Vector3f camera_coordinates = this->camera.camera_position();
	this->u_partial = {
		this->camera.focal_length * this->rotation_matrix(1, 1),
		this->camera.focal_length * this->rotation_matrix(1, 2),
		this->camera.focal_length * this->rotation_matrix(1, 3)
	};
	this->v_partial = {
		this->camera.focal_length * this->rotation_matrix(2, 1),
		this->camera.focal_length * this->rotation_matrix(2, 2),
		this->camera.focal_length * this->rotation_matrix(2, 3)
	};
	this->w_partial = {
		this->rotation_matrix(3, 1),
		this->rotation_matrix(3, 2),
		this->rotation_matrix(3, 3)
	};
	this->u = this->u_partial * (point_coordinates - camera_coordinates);
	this->v = this->v_partial * (point_coordinates - camera_coordinates);
	this->w = this->w_partial * (point_coordinates - camera_coordinates);
	this->w_squared = this->w * this->w;
}

Eigen::Matrix<float, 2, 3> JacobianCalculator::pointCoordinatesJacobian() {
	
	Eigen::Matrix<float, 2, 3> df_over_dX = {
		(this->w * this->u_partial - this->u * this->w_partial).array() / this->w_squared.array(),
		(this->w * this->v_partial - this->v * this->w_partial).array() / this->w_squared.array()
	};

	return df_over_dX;
}

Eigen::Matrix<float, 2, 3> JacobianCalculator::cameraCoordinatesJacobian() {

	Eigen::Matrix<float, 2, 3> df_over_dC = {
		(this->w * -(this->u_partial) - this->u * -(this->w_partial)).array() / this->w_squared.array(),
		(this->w * -(this->v_partial) - this->v * -(this->w_partial)).array() / this->w_squared.array()
	};

	return df_over_dC;
}

Eigen::Matrix<float, 2, 9> JacobianCalculator::rotationMatrixJacobian() {
	Eigen::Vector3f point_coordinates = this->point.point_in_world_coordinates();
	Eigen::Vector3f camera_coordinates = this->camera.camera_position();

	Eigen::Vector<float, 9> du_over_dR = Eigen::Vector<float, 9>::Zero();
	du_over_dR(0) = this->camera.focal_length * (point_coordinates(0) - camera_coordinates(0));

	Eigen::Vector<float, 9> dv_over_dR = Eigen::Vector<float, 9>::Zero();
	dv_over_dR(4) = this->camera.focal_length * (point_coordinates(1) - camera_coordinates(1)); // coordinates at (1) or (0)?
	
	Eigen::Vector<float, 9> dw_over_dR = Eigen::Vector<float, 9>::Zero();
	dw_over_dR(8) = (point_coordinates(2) - camera_coordinates(2));

	Eigen::Matrix<float, 2, 9> df_over_dR = {
		(this->w * du_over_dR - this->u * dw_over_dR).array() / this->w_squared.array(),
		(this->w * dv_over_dR - this->v * dw_over_dR).array() / this->w_squared.array()
	};

	return df_over_dR;
}