#include "font_file.h"

void bxtk::core::bindFontFile(sol::state &lua) {
    lua.new_usertype<bxtk::core::FontFile>("FontFile",
        "new", sol::factories(
            []() { return new bxtk::core::FontFile(); }
        ),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, bxtk::core::Font>(),

        "allowSystemFallback", sol::property(
            &bxtk::core::FontFile::getAllowSystemFallback,
            &bxtk::core::FontFile::setAllowSystemFallback
        ),
        "antialiasing", sol::property(
            &bxtk::core::FontFile::getAntialiasing,
            &bxtk::core::FontFile::setAntialiasing
        ),
        "data", sol::property(
            &bxtk::core::FontFile::getData,
            &bxtk::core::FontFile::setData
        ),
        "disableEmbeddedBitmaps", sol::property(
            &bxtk::core::FontFile::getDisableEmbeddedBitmaps,
            &bxtk::core::FontFile::setDisableEmbeddedBitmaps
        ),
        "fixedSize", sol::property(
            &bxtk::core::FontFile::getFixedSize,
            &bxtk::core::FontFile::setFixedSize
        ),
        "fixedSizeScaleMode", sol::property(
            &bxtk::core::FontFile::getFixedSizeScaleMode,
            &bxtk::core::FontFile::setFixedSizeScaleMode
        ),
        "fontName", sol::property(
            &bxtk::core::FontFile::getFontName,
            &bxtk::core::FontFile::setFontName
        ),
        "fontStretch", sol::property(
            &bxtk::core::FontFile::getFontStretch,
            &bxtk::core::FontFile::setFontStretch
        ),
        "fontStyle", sol::property(
            &bxtk::core::FontFile::getFontStyle,
            &bxtk::core::FontFile::setFontStyle
        ),
        "fontWeight", sol::property(
            &bxtk::core::FontFile::getFontWeight,
            &bxtk::core::FontFile::setFontWeight
        ),
        "forceAutohinter", sol::property(
            &bxtk::core::FontFile::getForceAutohinter,
            &bxtk::core::FontFile::setForceAutohinter
        ),
        "generateMipmaps", sol::property(
            &bxtk::core::FontFile::getGenerateMipmaps,
            &bxtk::core::FontFile::setGenerateMipmaps
        ),
        "hinting", sol::property(
            &bxtk::core::FontFile::getHinting,
            &bxtk::core::FontFile::setHinting
        ),
        "msdfPixelRange", sol::property(
            &bxtk::core::FontFile::getMsdfPixelRange,
            &bxtk::core::FontFile::setMsdfPixelRange
        ),
        "msdfSize", sol::property(
            &bxtk::core::FontFile::getMsdfSize,
            &bxtk::core::FontFile::setMsdfSize
        ),
        "multichannelSignedDistanceField", sol::property(
            &bxtk::core::FontFile::getMultichannelSignedDistanceField,
            &bxtk::core::FontFile::setMultichannelSignedDistanceField
        ),
        "opentypeFeatureOverrides", sol::property(
            &bxtk::core::FontFile::getOpentypeFeatureOverrides,
            &bxtk::core::FontFile::setOpentypeFeatureOverrides
        ),
        "oversampling", sol::property(
            &bxtk::core::FontFile::getOversampling,
            &bxtk::core::FontFile::setOversampling
        ),
        "styleName", sol::property(
            &bxtk::core::FontFile::getStyleName,
            &bxtk::core::FontFile::setStyleName
        ),
        "subpixelPositioning", sol::property(
            &bxtk::core::FontFile::getSubpixelPositioning,
            &bxtk::core::FontFile::setSubpixelPositioning
        ),
        "clearCache", &bxtk::core::FontFile::clearCache,
        "clearGlyphs", &bxtk::core::FontFile::clearGlyphs,
        "clearKerningMap", &bxtk::core::FontFile::clearKerningMap,
        "getFallbacks", &bxtk::core::FontFile::getFallbacks,
        "getFaceIndex", &bxtk::core::FontFile::getFaceIndex,
        "getFontName", &bxtk::core::FontFile::getFontName,
        "getGlyphAdvance", &bxtk::core::FontFile::getGlyphAdvance,
        "getGlyphIndex", &bxtk::core::FontFile::getGlyphIndex,
        "getGlyphList", &bxtk::core::FontFile::getGlyphList,
        "getGlyphOffset", &bxtk::core::FontFile::getGlyphOffset,
        "getGlyphSize", &bxtk::core::FontFile::getGlyphSize,
        "getKerning", &bxtk::core::FontFile::getKerning,
        "getKerningList", &bxtk::core::FontFile::getKerningList,
        "getLanguageSupportOverride", &bxtk::core::FontFile::getLanguageSupportOverride,
        "getScriptSupportOverride", &bxtk::core::FontFile::getScriptSupportOverride,
        "getMsdfPixelRange", &bxtk::core::FontFile::getMsdfPixelRange,
        "getMsdfSize", &bxtk::core::FontFile::getMsdfSize,
        "getOversampling", &bxtk::core::FontFile::getOversampling,
        "getSizeCacheList", &bxtk::core::FontFile::getSizeCacheList,
        "getTextureCount", &bxtk::core::FontFile::getTextureCount,
        "getTextureImage", &bxtk::core::FontFile::getTextureImage,
        "getTextureOffsets", &bxtk::core::FontFile::getTextureOffsets,
        "getTransform", &bxtk::core::FontFile::getTransform,
        "getVariationCoordinates", &bxtk::core::FontFile::getVariationCoordinates,
        "isLanguageSupported", &bxtk::core::FontFile::isLanguageSupported,
        "isScriptSupported", &bxtk::core::FontFile::isScriptSupported,
        "loadBitmapFont", &bxtk::core::FontFile::loadBitmapFont,
        "loadDynamicFont", &bxtk::core::FontFile::loadDynamicFont,
        "setCacheCapacity", &bxtk::core::FontFile::setCacheCapacity,
        "setFallbacks", &bxtk::core::FontFile::setFallbacks,
        "setFontName", &bxtk::core::FontFile::setFontName,
        "setFontStyle", &bxtk::core::FontFile::setFontStyle,
        "setFontWeight", &bxtk::core::FontFile::setFontWeight,
        "setGlyphAdvance", &bxtk::core::FontFile::setGlyphAdvance,
        "setGlyphOffset", &bxtk::core::FontFile::setGlyphOffset,
        "setGlyphSize", &bxtk::core::FontFile::setGlyphSize,
        "setGlyphTextureIndex", &bxtk::core::FontFile::setGlyphTextureIndex,
        "setGlyphUvRect", &bxtk::core::FontFile::setGlyphUvRect,
        "setKerning", &bxtk::core::FontFile::setKerning,
        "setLanguageSupportOverride", &bxtk::core::FontFile::setLanguageSupportOverride,
        "setScriptSupportOverride", &bxtk::core::FontFile::setScriptSupportOverride,
        "setTextureImage", &bxtk::core::FontFile::setTextureImage,
        "setTextureOffsets", &bxtk::core::FontFile::setTextureOffsets,
        "setTransform", &bxtk::core::FontFile::setTransform,
        "setVariationCoordinates", &bxtk::core::FontFile::setVariationCoordinates,
        "cast", [](Resource* instance) {
            return new FontFile(godot::Object::cast_to<GodotFontFile>(instance->getResource()));
        }
    );
}