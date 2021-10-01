#include "SphereCollider.h"
#include <iostream>
float colliderDistance(glm::vec3 myPosition, glm::vec3 theirPosition) {
	float dist = sqrt(pow((theirPosition[0] - myPosition[0]), 2.0) + pow((theirPosition[1] - myPosition[1]), 2.0) + pow((theirPosition[2] - myPosition[2]), 2.0));
	return dist;
}
glm::vec3 findNormalVector(glm::vec3 myPosition, glm::vec3 theirPosition) {
	return glm::normalize(theirPosition - myPosition);
}
glm::vec3 ARP::SphereCollider::bounceVector(glm::vec3 myPosition, glm::vec3 theirPosition, glm::vec3 theirForward) {
	glm::vec3 normal = findNormalVector(myPosition, theirPosition);
	float dot = glm::dot(theirForward, normal);
	return ((-2 * dot) * normal) - theirForward;

}
ARP::SphereCollider::SphereCollider(glm::vec3 center, float radius)
{
	this->center = center;
	this->radius = radius;
}

bool ARP::SphereCollider::isColliding(SphereCollider other)
{
	//If the distance between sphere is smalled than the two radii then they are colliding.
	/*std::cout << "--------------------------\n";
	std::cout << colliderDistance(this->center, other.center);
	std::cout << "\n";
	std::cout << (this->radius + other.radius);
	std::cout << "\n--------------------------\n";*/
	if (colliderDistance(this->center, other.center) < this->radius + other.radius)
		return true;
	return false;
}

void ARP::SphereCollider::setRadius(float radius)
{
	this->radius = radius;
}

void ARP::SphereCollider::setCenter(glm::vec3 newCenter)
{
	this->center = newCenter;
}

float ARP::SphereCollider::getRadius()
{
	return this->radius;
}

glm::vec3 ARP::SphereCollider::getCenter()
{
	return this->center;
}



