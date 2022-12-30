#include "player-controller.hpp"
#include "../ecs/entity.hpp"
#include "../deserialize-utils.hpp"
#include <iostream>

namespace our {
    // Reads collider center & radius from the given json object
    void PlayerControllerComponent::deserialize(const nlohmann::json& data)
    {
        if (!data.is_object()) return;

        // colliderCenter = data.value("colliderCenter", colliderCenter);
        // radius = data.value("radius", radius);
    }
}