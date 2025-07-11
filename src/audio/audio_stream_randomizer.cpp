#include "audio_stream_randomizer.h"

void bxtk::audio::bindAudioStreamRandomizer(sol::state_view& lua) {
    lua.new_usertype<AudioStreamRandomizer>("AudioStreamRandomizer",
        "new", sol::factories([]() {
            return new AudioStreamRandomizer();
        }),
        sol::base_classes, sol::bases<bxtk::core::BaseObject, bxtk::core::Resource, AudioStream>(),
        "cast", [](bxtk::core::Resource* resource) { 
            return new AudioStreamRandomizer(
                Object::cast_to<GodotAudioStreamRandomizer>(
                    resource->getResource()
                )
            ); 
        },
        "playbackMode", sol::property(&AudioStreamRandomizer::getPlaybackMode, &AudioStreamRandomizer::setPlaybackMode),
        "randomPitch", sol::property(&AudioStreamRandomizer::getRandomPitch, &AudioStreamRandomizer::setRandomPitch),
        "randomVolumeOffsetDb", sol::property(&AudioStreamRandomizer::getRandomVolumeOffsetDb, &AudioStreamRandomizer::setRandomVolumeOffsetDb),
        "streamsCount", sol::property(&AudioStreamRandomizer::getStreamsCount),
        "addStream", &AudioStreamRandomizer::addStream,
        "getStream", &AudioStreamRandomizer::getStream,
        "getStreamProbabilityWeight", &AudioStreamRandomizer::getStreamProbabilityWeight,
        "moveStream", &AudioStreamRandomizer::moveStream,
        "removeStream", &AudioStreamRandomizer::removeStream,
        "setStream", &AudioStreamRandomizer::setStream,
        "setStreamProbabilityWeight", &AudioStreamRandomizer::setStreamProbabilityWeight
    );
}