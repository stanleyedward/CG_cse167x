// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
#include <stdio.h>
#include <iostream>
//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
	// YOUR CODE FOR HW1 HERE
	mat3 Identity = glm::mat3(1.0);

	mat3 Axis_Axis_T = glm::mat3(
		axis.x*axis.x, axis.x*axis.y, axis.y*axis.z,
	  	axis.x*axis.y, axis.y*axis.y, axis.y*axis.z,
	  	axis.x*axis.z, axis.y*axis.z, axis.z*axis.z
	);

	mat3 A_star = glm::mat3(
	  0, axis.z, -axis.y,
	  -axis.z, 0, axis.x,
	  axis.y, -axis.x, 0);

	float radians = degrees * (pi/180);
	float sin_angle = sin(radians);
	float cos_angle = cos(radians);
	
	mat3 Rotation = glm::mat3( cos_angle*Identity + (1.0-cos_angle)*Axis_Axis_T + sin_angle*A_star);
	// You will change this return call
	return Rotation;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE
	mat3 rotation = rotate(degrees, vec3(0, 1, 0));
	eye = eye * rotation;
	up = up * rotation;
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	// YOUR CODE FOR HW1 HERE 
	mat3 rotation = rotate(degrees, vec3(1, 0, 0));
	eye = eye * rotation;
	up = up * rotation;
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));

}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	// YOUR CODE FOR HW1 HERE
	vec3 w = glm::normalize(eye);
	vec3 u = glm::normalize(glm::cross(up, w));
	vec3 v = glm::cross(w, u);

	// You will change this return call
	return mat4(
		u.x, v.x, w.x, 0,
		u.y, v.y, w.y, 0,
		u.z, v.z, w.z, 0,
		-u.x*eye.x-u.y*eye.y-u.z*eye.z, -v.x*eye.x-v.y*eye.y-v.z*eye.z, -w.x*eye.x-w.y*eye.y-w.z*eye.z, 1
		);
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
