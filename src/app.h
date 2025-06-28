//
// Created by mintkat on 1/31/25.
//

#ifndef APP_H
#define APP_H

#include <godot_cpp/classes/node.hpp>
#define SOL_ALL_SAFETIES_ON 1
#include <sol/state.hpp>

#include "core/element.h"
#include "core/io/io_manager.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba
{
    class App : public Node {
        GDCLASS(App, Node)
    protected:
        static void _bind_methods();
    public:
        App();
        ~App();

        sol::state global_state;

        sunaba::core::io::IoManager* ioManager;

        void _ready() override;
        void _process(double delta) override;

        void initState(bool sandboxed = true);

        void loadAndExecuteSbx(const String &path);

        void start( const String &path );

        // Mobdebug support
        void initMobdebug();
        void startMobdebug(const String& host = "localhost", int port = 8172);
        void stopMobdebug();
        
        // Lua file loading
        static int loadFileRequire(lua_State* L);
    private:
    };

    class Runtime : public Element {
        private:
            App* app = nullptr;
            
        public:
            Runtime() {
                setApp(memnew(App));
                onInit();
            }

            Runtime(App* a) {
                setApp(a);
            }

            App* getApp() {
                return app;
            }

            void setApp(App* a) {
                app = a;
                setNode(a);
            }

            void initState(bool sandboxed = true) {
                app->initState(sandboxed);
            }

            void loadAndExecuteSbx(const std::string &path) {
                app->loadAndExecuteSbx(path.c_str());
            }

            void initMobdebug() {
                app->initMobdebug();
            }

            void startMobdebug(const std::string& host = "localhost", int port = 8172) {
                app->startMobdebug(host.c_str(), port);
            }

            void stopMobdebug() {
                app->stopMobdebug();
            }
    };
}



#endif //APP_H
