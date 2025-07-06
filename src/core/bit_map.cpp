#include "bit_map.h"

void bxtk::core::bindBitMap(sol::state &lua) {
    lua.new_usertype<bxtk::core::BitMap>("BitMap",
        "new", sol::factories(
            []() { return new bxtk::core::BitMap(); }),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "convertToImage", &bxtk::core::BitMap::convertToImage,
        "create", &bxtk::core::BitMap::create,
        "createFromImageAlpha", &bxtk::core::BitMap::createFromImageAlpha,
        "getBit", &bxtk::core::BitMap::getBit,
        "getBitv", &bxtk::core::BitMap::getBitv,
        "getSize", &bxtk::core::BitMap::getSize,
        "getTrueBitCount", &bxtk::core::BitMap::getTrueBitCount,
        "growMask", &bxtk::core::BitMap::growMask,
        "opaqueToPolygons", &bxtk::core::BitMap::opaqueToPolygons,
        "resize", &bxtk::core::BitMap::resize,
        "setBit", &bxtk::core::BitMap::setBit,
        "setBitRect", &bxtk::core::BitMap::setBitRect,
        "setBitv", &bxtk::core::BitMap::setBitv,
        "cast", [](Resource* instance) {
            return new BitMap(godot::Object::cast_to<GodotBitMap>(instance->getResource()));
        }
    );
}
