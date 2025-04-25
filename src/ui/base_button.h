#ifndef BASE_BUTTON_H
#define BASE_BUTTON_H

#include <godot_cpp/classes/base_button.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <sol/sol.hpp>

#define BaseButtonNode godot::BaseButton

#include "control.h"
#include "../input/shortcut.h"
#include "../core/event.h"

#include "../core/stl_function_wrapper.h"
#define StlFunctionWrapper sunaba::core::StlFunctionWrapper

namespace sunaba::ui {
    void bindBaseButton(sol::state &lua);

    class BaseButton;

     class BaseButtonProxy : public BaseButtonNode {
        public:
            sunaba::ui::BaseButton* element = nullptr;

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

            void _draw() override;

            bool _can_drop_data(const Vector2& at_position, const Variant &data) const override;

            void _drop_data(const Vector2 &at_position, const Variant &data) override;

            Variant _get_drag_data(const Vector2 &at_position) override;

            Vector2 _get_minimum_size() const override;

            String _get_tooltip(const Vector2 &at_position) const override;

            void _gui_input(const Ref<InputEvent> &event) override;

            bool _has_point(const Vector2 &point) const override;

            //Object* _make_custom_tooltip(const String &for_text) const override;

            TypedArray<Vector3i> _structured_text_parser(const Array &args, const String &text) const override;

            void _pressed() override;

            void _toggled(bool p_toggled_on) override;
    };

    class BaseButton : public sunaba::ui::Control {
        private:
            BaseButtonNode* base_button = nullptr;

            void connectBaseButtonSignals() {
                // Connect signals from the BaseButton node to the BaseButton class
                std::function<Variant(std::vector<Variant>)> pressedFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->pressedEvent != nullptr) {
                        this->pressedEvent->emit(args);
                    }
                    return Variant();
                };
                Callable pressedCallable = StlFunctionWrapper::create_callable_from_cpp_function(pressedFunc);
                base_button->connect("pressed", pressedCallable);

                std::function<Variant(std::vector<Variant>)> toggledFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->toggledEvent != nullptr) {
                        this->toggledEvent->emit(args);
                    }
                    return Variant();
                };
                Callable toggledCallable = StlFunctionWrapper::create_callable_from_cpp_function(toggledFunc);
                base_button->connect("toggled", toggledCallable);

                std::function<Variant(std::vector<Variant>)> buttonDownFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->buttonDown != nullptr) {
                        this->buttonDown->emit(args);
                    }
                    return Variant();
                };
                Callable buttonDownCallable = StlFunctionWrapper::create_callable_from_cpp_function(buttonDownFunc);
                base_button->connect("button_down", buttonDownCallable);

                std::function<Variant(std::vector<Variant>)> buttonUpFunc =
                [this](std::vector<Variant> av) {
                    Array args;
                    for (int i = 0; i < av.size(); ++i) {
                        args.append(av[i]);
                    }
                    if (this->buttonUp != nullptr) {
                        this->buttonUp->emit(args);
                    }
                    return Variant();
                };
                Callable buttonUpCallable = StlFunctionWrapper::create_callable_from_cpp_function(buttonUpFunc);
                base_button->connect("button_up", buttonUpCallable);
            }
        
        public:
            // Constructor with Node* parameter
            BaseButton(BaseButtonNode* p_node) {
                setBaseButton(p_node);
            }

            BaseButton(BaseButtonProxy* p_node) {
                setBaseButton(p_node);
            }

            // Constructor with no parameters
            BaseButton() {
                setBaseButton(memnew(BaseButtonNode));
                onInit();
            }

            // Getter for the BaseButton node
            BaseButtonNode* getBaseButton() {
                return base_button;
            }

            // Setter for the BaseButton node
            void setBaseButton(BaseButtonNode* p_node) {
                base_button = p_node;
                connectBaseButtonSignals();
                setCanvasItem(base_button);
            }

            void setBaseButton(BaseButtonProxy* p_node) {
                base_button = p_node;
                p_node->element = this;
                connectBaseButtonSignals();
                setCanvasItem(p_node);
            }

            int getActionMode() {
                return base_button->get_action_mode();
            }

            void setActionMode(int mode) {
                base_button->set_action_mode(static_cast<godot::BaseButton::ActionMode>(mode));
            }

            int getButtonMask() {
                return base_button->get_button_mask();
            }

            void setButtonMask(int mask) {
                base_button->set_button_mask(static_cast<godot::BitField<godot::MouseButtonMask>>(mask));
            }

            bool getButtonPressed() {
                return base_button->is_pressed();
            }

            void setButtonPressed(bool pressed) {
                base_button->set_pressed(pressed);
            }

            bool getDisabled() {
                return base_button->is_disabled();
            }

            void setDisabled(bool disabled) {
                base_button->set_disabled(disabled);
            }

            int getFocusMode() {
                return base_button->get_focus_mode();
            }

            void setFocusMode(int mode) {
                base_button->set_focus_mode(static_cast<godot::Control::FocusMode>(mode));
            }

            bool getKeepPressedOutside() {
                return base_button->is_keep_pressed_outside();
            }
            
            void setKeepPressedOutside(bool enabled) {
                base_button->set_keep_pressed_outside(enabled);
            }

            sunaba::input::Shortcut* getShortcut() {
                return new sunaba::input::Shortcut(base_button->get_shortcut().ptr());
            }

            void setShortcut(sunaba::input::Shortcut* shortcut) {
                base_button->set_shortcut(shortcut->getShortcut());
            }

            bool getShortcutFeedback() {
                return base_button->is_shortcut_feedback();
            }

            void setShortcutFeedback(bool enabled) {
                base_button->set_shortcut_feedback(enabled);
            }

            bool getToggleMode() {
                return base_button->is_toggle_mode();
            }

            void setToggleMode(bool enabled) {
                base_button->set_toggle_mode(enabled);
            }

            Event* buttonDown;
            Event* buttonUp;
            Event* pressedEvent;
            Event* toggledEvent;

            int getDrawMode() {
                return base_button->get_draw_mode();
            }

            bool isHovered() {
                return base_button->is_hovered();
            }

            void setPressedNoSignal(bool pressed) {
                base_button->set_pressed_no_signal(pressed);
            }
        };
}

#endif // BASE_BUTTON_H