#include "audio_stream.h"

void bxtk::audio::bindAudioStream(sol::state_view& lua) {
    lua.new_usertype<AudioStream>("AudioStream",
        "new", sol::factories([]() {
            return new AudioStream();
        }),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource>(),
        "canBeSampled", &AudioStream::canBeSampled,
        "getLength", &AudioStream::getLength,
        "isMetaStream", &AudioStream::isMetaStream,
        "isMonophonic", &AudioStream::isMonophonic,
        "cast", [](bxtk::core::Resource* resource) { 
            return new AudioStream(
                Object::cast_to<GodotAudioStream>(
                    resource->getResource()
                )
            ); 
        });
}