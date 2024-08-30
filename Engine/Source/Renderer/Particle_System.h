#pragma once

#include "..//../Source/Renderer/Particle.h"

#include <vector>

class ParticleSystem
{
public:
	ParticleSystem(int max_size = 1000)
	{
		particles.resize(max_size);
	}
	void Update(float dt);
	void Draw(Renderer& renderer);
	void AddParticle(const Particle::Data& data);

private:
	Particle* GetFreeParticle();

private:
	std::vector<Particle> particles; //post of particles
};