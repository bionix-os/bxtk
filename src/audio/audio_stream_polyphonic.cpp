#include "audio_stream_polyphonic.h"

void bxtk::audio::bindAudioStreamPolyphonic(sol::state_view& lua) {
    lua.new_usertype<AudioStreamPolyphonic>("AudioStreamPolyphonic",
        "new", sol::factories([]() {
            return new AudioStreamPolyphonic();
        }),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, AudioStream>(),
        "cast", [](bxtk::core::Resource* resource) { 
            return new AudioStreamPolyphonic(
                Object::cast_to<GodotAudioStreamPolyphonic>(
                    resource->getResource()
                )
            ); 
        },
        "polyphony", sol::property(&AudioStreamPolyphonic::getPolyphony, &AudioStreamPolyphonic::setPolyphony)
    );
}