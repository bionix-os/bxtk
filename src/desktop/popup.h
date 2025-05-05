#ifndef POPUP_H
#define POPUP_H

#include <godot_cpp/classes/popup.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define PopupNode godot::Popup

#include "window.h"
#include "../core/stl_function_wrapper.h"
#include "../core/event.h"

using namespace godot;
using namespace sunaba::core;

namespace sunaba::desktop {
    void bindPopup(sol::state &lua);

    class Popup;

    class PopupProxy : public PopupNode {
        public:
            sunaba::desktop::Popup* element = nullptr;

            void onInit() {
                // Initialize the NodeProxy instance
            }

            void _enter_tree() override;
            void _exit_tree() override;
            void _ready() override ;
            void _process(double delta) override;
            void _physics_process(double delta) override;
            void _input(const Ref<InputEvent>& event) override;
            void _unhandled_input(const Ref<InputEvent>& event) override;
            void _unhandled_key_input(const Ref<InputEvent>& event) override;
            void _shortcut_input(const Ref<InputEvent>& event) override;

            Vector2 _get_contents_minimum_size() const override;
    };

    class Popup : public sunaba::desktop::Window {
        private:
            PopupNode* popup = nullptr; // Pointer to the Popup instance
            void connectPopupSignals() {
                // Connect signals specific to Popup
            }

        public:
            Popup() {
                setPopup(memnew(PopupProxy));
                onInit();
            }

            Popup(PopupNode* popup) {
                setPopup(popup);
                onInit();
            }

            PopupNode* getPopup() {
                return popup;
            }

            void setPopup(PopupNode* popup) {
                this->popup = popup;
                connectPopupSignals();
                setViewport(popup);
            }

            bool getBorderless() const {
                return popup->get_flag(godot::Popup::Flags::FLAG_BORDERLESS);
            }

            void setBorderless(bool borderless) {
                popup->set_flag(godot::Popup::Flags::FLAG_BORDERLESS, borderless);
            }

            bool getPopupWindow() const {
                return popup->get_flag(godot::Popup::Flags::FLAG_POPUP);
            }

            void setPopupWindow(bool p_popup) {
                popup->set_flag(godot::Popup::Flags::FLAG_POPUP, p_popup);
            }

            bool getTransient() const {
                return popup->is_transient();
            }

            void setTransient(bool transient) {
                popup->set_transient(transient);
            }

            bool getUnresizable() const {
                return popup->get_flag(godot::Popup::Flags::FLAG_RESIZE_DISABLED);
            }
    };
}

#endif // POPUP_H