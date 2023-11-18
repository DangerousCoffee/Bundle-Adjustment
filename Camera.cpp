#include "BA_Algorithm.h";

struct Camera {
	int id;
	float pos_x;
	float pos_y;
	float pos_z;
	float rot_x;
	float rot_y;
	float rot_z;
	float focal_length;
	float distortion_coef1;
	float distortion_coef2;

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
};