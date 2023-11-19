#pragma once
#include "Eigen/Sparse"
#include "Point.cpp"
#include "Observation.cpp"
#include "Camera.cpp"

/*! \brief A class to handle bundle adjustment logic.
* 
* This class handles bundle adjustment logic. It accepts arrays of camera, point and observation objects and calculates and applies deltas via jacobian matrices.
* 
* TODO: Fix this when i figure out how exactly i'm calculating stuff.
*/
class BundleAdjustment {
	public:

		/*! 
		* Constructor function. Used to assign cameras, points and observation arrays.
		* 
		* @param cameras - an eigen vector of cameras
		* @param points - an eigen vector of points
		* @param observations - an eigen vector of observations
		*/
		BundleAdjustment(Eigen::Vector<Camera, -1> cameras, Eigen::Vector<Point, -1> points, Eigen::Vector<Observation, -1> observations);
		/*!
		* Destructor function.
		*/
		virtual ~BundleAdjustment();
		/*!
		* A function to build a jacobian matrix for given observations.
		*/
		virtual void buildJacobian();
		/*!
		* A function to calculate residual value between the projection of a 3D point and observed point.
		*/
		virtual void calculateResiduals();
		/*!
		* A function to solve the jacobian matrix and calculate deltas.
		*/
		virtual void solveJacobian();
		/*!
		* A function to apply deltas to the cameras and points.
		*/
		virtual void updateParams();

		Eigen::Vector<Camera, -1> cameras; /*! array of camera objects */
		Eigen::Vector<Point, -1> points; /*! array of point objects */
		Eigen::Vector<Observation, -1> observations; /*! array of observation objects */

	private: 

};