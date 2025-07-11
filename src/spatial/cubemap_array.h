#ifndef CUBEMAP_ARRAY_H
#define CUBEMAP_ARRAY_H

#include <godot_cpp/classes/cubemap_array.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define GodotCubemapArray godot::CubemapArray

#include "../core/image_texture_layered.h"

using namespace godot;
using namespace bxtk::core;

namespace bxtk::spatial {
    void bindCubemapArray(sol::state_view& lua);

    class CubemapArray : public bxtk::core::ImageTextureLayered {
    private:
        GodotCubemapArray* cubemapArray = nullptr;
    public:
        CubemapArray() {
            setCubemapArray(memnew(GodotCubemapArray));
        }

        CubemapArray(GodotCubemapArray* c) {
            setCubemapArray(c);
        }

        GodotCubemapArray* getCubemapArray() {
            return cubemapArray;
        }

        void setCubemapArray(GodotCubemapArray* c) {
            cubemapArray = c;
            //cubemapArray->reference();
            setImageTextureLayered(cubemapArray);
        }

        bxtk::core::Resource* createPlaceholder() {
            return new bxtk::core::Resource(
                cubemapArray->create_placeholder().ptr()
            );
        }
    };
}

#endif // CUBEMAP_ARRAY_H