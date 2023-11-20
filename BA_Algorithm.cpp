#include "BA_Algorithm.h"

BundleAdjustment::BundleAdjustment(std::map<int, Camera> cameras, std::map<int, Point> points, Eigen::Vector<Observation, -1> observations) {
	this->cameras = cameras;
	this->points = points;
	this->observations = observations;
}

BundleAdjustment::~BundleAdjustment() {

}

void BundleAdjustment::buildJacobian() {
	
	Eigen::SparseMatrix<float> jacobianMatrix(this->observations.size(), this->cameras.size() + this->points.size));
	Eigen::AutoDiffScalar<Eigen::Vector<float, 3>> differentiation;

	for (int i = 0; i < this->observations.size(); i++) {
		Observation current_observation = observations[i];

		Camera current_camera = this->cameras[current_observation.camera_id];
		Point current_point = this->points[current_observation.point_id];



	}

}

void BundleAdjustment::calculateResiduals() {

}

void BundleAdjustment::solveJacobian() {

}

void BundleAdjustment::updateParams() {

}