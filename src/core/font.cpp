#include "font.h"

void bxtk::core::bindFont(sol::state &lua) {
    lua.new_usertype<bxtk::core::Font>("Font",
        "new", sol::factories(
            []() { return new bxtk::core::Font(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "fallbacks", sol::property(
            &bxtk::core::Font::getFallbacks, 
            &bxtk::core::Font::setFallbacks
        ),
        "getAscent", &bxtk::core::Font::getAscent,
        "getCharSize", &bxtk::core::Font::getCharSize,
        "getDescent", &bxtk::core::Font::getDescent,
        "getFaceCount", &bxtk::core::Font::getFaceCount,
        "getFontName", &bxtk::core::Font::getFontName,
        "getFontStyle", &bxtk::core::Font::getFontStyle,
        "getFontWeight", &bxtk::core::Font::getFontWeight,
        "getHeight", &bxtk::core::Font::getHeight,
        "getMultilineStringSize", &bxtk::core::Font::getMultilineStringSize,
        "getOpentypeFeatures", &bxtk::core::Font::getOpentypeFeatures,
        "getOtNameStrings", &bxtk::core::Font::getOtNameStrings,
        "getSpacing", &bxtk::core::Font::getSpacing,
        "getStringSize", &bxtk::core::Font::getStringSize,
        "getSupportedChars", &bxtk::core::Font::getSupportedChars,
        "getSupportedFeatureList", &bxtk::core::Font::getSupportedFeatureList,
        "getSupportedVariationList", &bxtk::core::Font::getSupportedVariationList,
        "getUnderlinePosition", &bxtk::core::Font::getUnderlinePosition,
        "getUnderlineThickness", &bxtk::core::Font::getUnderlineThickness,
        "hasChar", &bxtk::core::Font::hasChar,
        "isLanguageSupported", &bxtk::core::Font::isLanguageSupported,
        "isScriptSupported", &bxtk::core::Font::isScriptSupported,
        "setCacheCapacity", &bxtk::core::Font::setCacheCapacity,
        "cast", [](Resource* instance) {
            return new Font(godot::Object::cast_to<GodotFont>(instance->getResource()));
        }
    );
}