#pragma once

namespace Core::ECS::Components
{
	struct Rigidbody
	{
		//Default Constructor
		Rigidbody()
		{
		}

		//Move Constructor
		Rigidbody(Rigidbody&& other) noexcept
		{
			velocity = other.velocity;
			gravity = other.gravity;
			mass = other.mass;
		}

		//Move Assignment operator
		Rigidbody& operator=(Rigidbody&& other) noexcept
		{
			if (this != &other)
			{
				velocity = other.velocity;
				gravity = other.gravity;
				mass = other.mass;
			}

			return *this;
		}

		//Copy Constructor
		Rigidbody(const Rigidbody& other)
		{
			velocity = other.velocity;
			gravity = other.gravity;
			mass = other.mass;
		}

		float velocity = 0.0f;
		float gravity = 0.0f;
		float mass = 0.0f;
	};
}
