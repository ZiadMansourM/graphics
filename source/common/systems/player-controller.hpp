#pragma once

#include "../ecs/world.hpp"
#include "../components/player-controller.hpp"
#include "../components/collider.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/trigonometric.hpp>
#include <glm/gtx/fast_trigonometry.hpp>

namespace our
{

    // The movement system is responsible for moving every entity which contains a MovementComponent.
    // This system is added as a simple example for how use the ECS framework to implement logic. 
    // For more information, see "common/components/movement.hpp"
    class PlayerControllerSystem {
    public:

        // This should be called every frame to update all entities containing a MovementComponent. 
        void update(World* world, float deltaTime)
        {
            PlayerControllerComponent* playerController = nullptr;
            Entity* playerEntity = nullptr;
            //For each entity in the world
            for (auto entity : world->getEntities())
            {
                // Get the movement component if it exists
                playerController = entity->getComponent<PlayerControllerComponent>();
                // If the movement component exists
                if (playerController)
                {
                    break;
                }
            }
            if (!playerController) { return; }
            playerEntity = playerController->getOwner();

            //Get a reference of player's position and rotation
            glm::vec3& playerPosition = playerEntity->localTransform.position;
            glm::vec3& playerRotation = playerEntity->localTransform.rotation;


            //Search for other entity having a collider component
            Entity* other = nullptr;
            ColliderComponent* collider = nullptr;
            for (auto entity : world->getEntities())
            {
                // Get the movement component if it exists
                collider = entity->getComponent<ColliderComponent>();
                // If the movement component exists
                if (collider)
                {
                    break;
                }
            }
            if (!collider)
            {
                // std::cout << "None found" << std::endl;
                return;
            }
            // std::cout << "Found" << std::endl;
            other = collider->getOwner();

            //Get position of other entity
            glm::vec3 otherPosition = other->localTransform.position;

            //Detect collisions

            float dist = glm::length(otherPosition - playerPosition);
            if (dist < collider->radius)
            {
                std::cout << "Collision detected" << std::endl;
            }


        }

    };

}
