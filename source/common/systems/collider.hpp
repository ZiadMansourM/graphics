#pragma once

#include "../ecs/world.hpp"
#include "../components/collider.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/fast_trigonometry.hpp>

namespace our
{

    class ColliderSystem {
    public:

        // This should be called every frame to update all entities containing a ColliderComponent. 
        void update(World* world, float deltaTime)
        {
            // For each entity in the world
            for (auto entity : world->getEntities())
            {
                // Get the movement component if it exists
                ColliderComponent* collider = entity->getComponent<ColliderComponent>();
                // If the collider component exists
                if (collider)
                {
                    cout << "ColliderComponent exists" << endl;
                }
            }
        }

    };

}
