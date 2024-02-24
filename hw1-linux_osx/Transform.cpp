// Transform.cpp: implementation of the Transform class.


#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	// YOUR CODE FOR HW1 HERE
	mat3 Identity = glm::mat3(1.0);

	mat3 Axis_Axis_T = glm::mat3(
		axis.x*axis.x, axis.x*axis.y, axis.y*axis.z,
	  	axis.x*axis.y, axis.y*axis.y, axis.y*axis.z,
	  	axis.x*axis.z, axis.y*axis.z, axis.z*axis.z
	);  Axis_Axis_T= glm::transpose(Axis_Axis_T);

	mat3 A_star = glm::mat3(
	  0, axis.z, -axis.y,
	  -axis.z, 0, axis.x,
	  axis.y, -axis.x, 0);

	float radians = degrees * (pi/180);
	float sin_angle = sin(radians);
	float cos_angle = cos(radians);
	
	mat3 Rotation = glm::mat3( cos_angle*Identity + (1-cos_angle)*Axis_Axis_T + sin_angle*A_star);
	// You will change this return call
	return Rotation;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE 
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	// YOUR CODE FOR HW1 HERE

	// You will change this return call
	return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
