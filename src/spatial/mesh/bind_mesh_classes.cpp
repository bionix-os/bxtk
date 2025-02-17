#include "bind_mesh_classes.h"

#include "box.h"
#include "sphere.h"
#include "capsule.h"
#include "mesh_renderer.h"

void sunaba::spatial::mesh::bindMeshClasses(sol::state& lua) {
    bindMeshRenderer(lua);
    bindBox(lua);
    bindSphere(lua);
    bindCapsule(lua);
}