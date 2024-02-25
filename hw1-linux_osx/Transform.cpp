// Transform.cpp: implementation of the Transform class.

#include <stdio.h>
#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {

	mat3 Identity = glm::mat3(1.0);

	mat3 Axis_Axis_T = mat3(
		axis.x * axis.x, axis.x * axis.y, axis.x * axis.z,
		axis.y * axis.x, axis.y * axis.y, axis.y * axis.z,
		axis.z * axis.x, axis.z * axis.y, axis.z * axis.z
		);

	mat3 A_star = mat3(
		0., axis.z, -axis.y, 
		-axis.z, 0., axis.x,
		 axis.y, -axis.x, 0.
		 );
	
	// float radians = degrees * (pi/180);
	float radians = glm::radians(degrees);
	float sin_angle = sin(radians);
	float cos_angle = cos(radians);

	mat3 Rotation = glm::mat3(cos_angle*Identity + (1.f-cos_angle)*Axis_Axis_T + sin_angle*A_star);

	return Rotation;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {

	mat3 rotation = rotate(degrees, up);
	eye = rotation * eye;

	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));

}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {

	vec3 rotation_axis = glm::normalize(glm::cross(eye, up));
	mat3 rotation = rotate(degrees, rotation_axis);
	eye = rotation * eye;
	up = glm::normalize(glm::cross(rotation_axis, eye));

	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));

}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {

	vec3 w = glm::normalize(eye);
	vec3 u = glm::normalize(glm::cross(up, w));
	vec3 v = glm::cross(w, u);

	return mat4(
		u.x, v.x, w.x, 0., 
		u.y, v.y, w.y, 0., 
		u.z, v.z, w.z, 0., 
		-glm::dot(u, eye), -glm::dot(v, eye), -glm::dot(w, eye), 1.);
}

Transform::Transform()
{

}

Transform::~Transform()
{

}