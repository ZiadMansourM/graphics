#pragma once

#include "../ecs/component.hpp"

#include <glm/glm.hpp>

namespace our {

    //ColliderComponent
    class PlayerControllerComponent: public Component {
    public:

        // glm::vec3 colliderCenter = { 0, 0, 0 };
        // float radius = 0.0f;

        // The ID of this component type is "Collider"
        static std::string getID() { return "Player Controller"; }

        // Reads collider center & radius from the given json object
        void deserialize(const nlohmann::json& data) override;
    };

}