#ifndef EVENT_H
#define EVENT_H

#include <godot_cpp/core/method_bind.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/godot.hpp>
#include <sol/sol.hpp>
#include <vector>

#include "base_object.h"

using namespace godot;

namespace sunaba::core {
    void bindEvent(sol::state &lua);

    class Event : public BaseObject {
        private:
            std::vector<std::function<void(godot::Array)>*> listeners;
            std::vector<sol::function> lua_listeners;

            void callCppListener(void* listener, godot::Array args) {
                // Call the C++ listener function with the provided arguments
                // Assuming listener is a function pointer or a callable object
                auto func = static_cast<void(*)(godot::Array)>(listener);
                func(args);
            }

            void callLuaListener(sol::function listener, sol::table args) {
                // Call the Lua listener function with the provided arguments
                listener(sol::as_args(args));
            }

            public:
            Event() = default;
            ~Event() {
                for (auto listener : listeners) {
                    delete listener; // Assuming listeners are dynamically allocated
                }
            }

            void connect(std::function<void(godot::Array)>* listener) {
                listeners.push_back(listener);
            }

            void connectLua(sol::function listener) {
                lua_listeners.push_back(listener);
            }

            void disconnect(std::function<void(godot::Array)>* listener) {
                auto it = std::remove(listeners.begin(), listeners.end(), listener);
                if (it != listeners.end()) {
                    listeners.erase(it, listeners.end());
                }
            }

            void disconnectLua(sol::function listener) {
                auto it = std::remove(lua_listeners.begin(), lua_listeners.end(), listener);
                if (it != lua_listeners.end()) {
                    lua_listeners.erase(it, lua_listeners.end());
                }
            }

            void emitLua(sol::variadic_args args) {
                for (auto listemer: listeners) {
                    godot::Array args_array;
                    for (auto arg : args) {
                        args_array.append(arg.as<godot::Variant>());
                    }
                    callCppListener(listemer, args_array);
                }
                for (auto lua_listener : lua_listeners) {
                    sol::state_view lua_state = sol::state_view(lua_listener.lua_state());
                    sol::table lua_args = lua_state.create_table(args.size(), 0);
                    for (int i = 0; i < args.size(); ++i) {
                        lua_args[i + 1] = args[i]; // Lua tables are 1-indexed
                    }
                    callLuaListener(lua_listener, lua_args);
                }
            }

            void emit(godot::Array args) {
                for (auto listemer: listeners) {
                    callCppListener(listemer, args);
                }

                for (sol::function lua_listener : lua_listeners) {
                    sol::state_view lua_state = sol::state_view(lua_listener.lua_state());
                    sol::table lua_args = lua_state.create_table(args.size(), 0);
                    for (int i = 0; i < args.size(); ++i) {
                        lua_args[i + 1] = args[i]; // Lua tables are 1-indexed
                    }
                    callLuaListener(lua_listener, lua_args);
                }
            }

            static Event* createFromSignal(godot::Signal signal);
    };

    class EventBridge : public godot::Object {
        GDCLASS(EventBridge, godot::Object);
    public:
        Event* event = nullptr;

        EventBridge() {
            event = new Event();
        }
        void callEvent(const godot::Variant* args, GDExtensionInt arg_count, GDExtensionCallError &error) {
            Array args_array;
            for (int i = 0; i < arg_count; ++i) {
                args_array.append(args[i]);
            }
            event->emit(args_array);
        }
    protected:
        static void _bind_methods() {
            ClassDB::bind_vararg_method(
                METHOD_FLAGS_DEFAULT,
                "callEvent",
                &EventBridge::callEvent,
                MethodInfo(Variant::Type::NIL, "callEvent") // Add method info for clarity
            );
        }
    };
}

#endif // EVENT_H
