#pragma once

#include "../ecs/entity.hpp"
#include "camera.hpp"
#include "mesh-renderer.hpp"
#include "free-camera-controller.hpp"
#include "movement.hpp"
#include "collider.hpp"
#include "player-controller.hpp"
#include<iostream>

namespace our {

    // Given a json object, this function picks and creates a component in the given entity
    // based on the "type" specified in the json object which is later deserialized from the rest of the json object
    inline void deserializeComponent(const nlohmann::json& data, Entity* entity)
    {
        std::string type = data.value("type", "");
        Component* component = nullptr;
        //TODO: (Req 8) Add an option to deserialize a "MeshRendererComponent" to the following if-else statement.
        if (type == CameraComponent::getID())
        {

            component = entity->addComponent<CameraComponent>();
        }
        else if (type == FreeCameraControllerComponent::getID())
        {
            component = entity->addComponent<FreeCameraControllerComponent>();
        }
        else if (type == MovementComponent::getID())
        {
            // glm::vec3 linearVelocity = { 0, 0, 0 };
            // std::cout << "MovementComponent exists" << std::endl;
            // std::cout << entity << std::endl;
            // std::cout << data.is_object() << std::endl;
            // std::cout << data.value("type", "") << std::endl;
            // linearVelocity = data.value("linearVelocity", linearVelocity);
            // std::cout << linearVelocity.x << std::endl;
            component = entity->addComponent<MovementComponent>();
        }
        else if (type == MeshRendererComponent::getID())
        {
            component = entity->addComponent<MeshRendererComponent>();
        }
        else if (type == ColliderComponent::getID())
        {

            // std::cout << "Before call" << std::endl;
            component = entity->addComponent<ColliderComponent>();
            // std::cout << "After call" << std::endl;

        }
        else if (type == PlayerControllerComponent::getID())
        {
            std::cout << "Player Controller" << std::endl;
            component = entity->addComponent<PlayerControllerComponent>();
        }

        // else if (type == LightComponent::getID())
        // {
        //     component = entity->addComponent<LightComponent>();

        // }

        if (component) component->deserialize(data);
    }

}