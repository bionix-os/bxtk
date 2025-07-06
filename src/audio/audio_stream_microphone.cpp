#include "audio_stream_microphone.h"

void bxtk::audio::bindAudioStreamMicrophone(sol::state_view& lua) {
    lua.new_usertype<AudioStreamMicrophone>("AudioStreamMicrophone",
        "new", sol::factories([]() {
            return new AudioStreamMicrophone();
        }),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, AudioStream>(),
        "cast", [](bxtk::core::Resource* resource) { 
            return new AudioStreamMicrophone(
                Object::cast_to<GodotAudioStreamMicrophone>(
                    resource->getResource()
                )
            ); 
        });
}